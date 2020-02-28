// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection.Metadata;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.TypeSystem;

namespace CppTranslator
{
	/// <summary>
	/// Entry point for convertine il code to C++
	/// All headers and method declarations are formatted using C# vistors.
	/// All the actual code formatting is done using and ILInstruction vistor.
	/// This was because the C# syntax tree lost a lot of the type information needed for translation.
	/// </summary>
	public static class Program
	{
		private static String pathToAssemble;
		private static CSharpDecompiler compiler;
		private static Formatter formatter = new Formatter();
		private static CppVisitorBase visitor = new CppVisitorBase(formatter);
		private static ProtoTypeVisitor prototypeVisitor = new ProtoTypeVisitor(formatter);
		private static HeaderTypeVisitor headerVisitor = new HeaderTypeVisitor(formatter);
		private static Boolean setOutput;
		/// <summary>
		/// Main entry point
		/// </summary>
		/// <param name="args">path to il code</param>
		public static void Main(string[] args)
		{
			if (args.Length != 1)
			{
				Usage();
				return;
			}
			try
			{
				var settings = new ICSharpCode.Decompiler.DecompilerSettings();
				settings.UsingStatement = false;
				settings.ObjectOrCollectionInitializers = false;
				GetPathToAssembly(args);
				CppTraceListener.AddListener(pathToAssemble);
				CppVisitorBase.TypeVisitor.LoadValidTypes();
				compiler = new CSharpDecompiler(args[0], settings);
				formatter.EmitToConsole = false;
				ProcessModules(prototypeVisitor, pathToAssemble + "Protos.h");
				ProcessModules(headerVisitor, pathToAssemble + "Header.h");
				ProcessModules(visitor, pathToAssemble + ".cpp");
				CppTraceListener.RemoveListener();
			}
			catch (Exception ex)
			{
				Trace.TraceError("Exception: " + ex.ToString());
				Trace.TraceError("StackTrace: " + ex.StackTrace);
			}
		}
		/// <summary>
		/// Compute path to assemble and all output files
		/// All output will be put into a generated folder in a subdirectory of the file to be tranlated.
		/// </summary>
		/// <param name="args">path to file to be translated</param>
		private static void GetPathToAssembly(string[] args)
		{
			int index;
			if (args[0].Contains("/", StringComparison.InvariantCulture))
			{
				index = args[0].LastIndexOf('/');
			}
			else
			{
				index = args[0].LastIndexOf('\\');
			}
			String path = args[0].Substring(0, index + 1);
			Directory.CreateDirectory(path + "generated/");
			pathToAssemble = path + "generated/Translated";
		}
		/// <summary>
		/// Process the input file using the supplied visitor
		/// </summary>
		/// <param name="visitorToUse">visitor to use</param>
		/// <param name="filePath">path to file</param>
		private static void ProcessModules(CppVisitorBase visitorToUse, String filePath)
		{
			setOutput = false;
			foreach (IModule module in compiler.TypeSystem.Modules)
			{
				if (module.IsMainModule)
				{
					foreach (ITypeDefinition typeDefinition in module.TopLevelTypeDefinitions)
					{
						if (typeDefinition.Kind == TypeKind.Class || typeDefinition.Kind == TypeKind.Enum || typeDefinition.Kind == TypeKind.Struct)
						{
							// Skip modules starting with < or any from CppTranslatorSupport namespace because
							// those are hand crafted for specific platforms
							if (!typeDefinition.Name.StartsWith("<", StringComparison.InvariantCulture) && !typeDefinition.Namespace.Contains("CppTranslatorSupport", StringComparison.InvariantCulture))
							{
								if (!setOutput)
								{
									formatter.OutputName = filePath;
									setOutput = true;
									visitorToUse.AddHeaders();
								}
								List<EntityHandle> entities = new List<EntityHandle>() { typeDefinition.MetadataToken };
								SyntaxTree syntaxTree = compiler.Decompile(entities);
								syntaxTree.AcceptVisitor(visitorToUse);
							}
						}
					}
					visitorToUse.CreateHeaders();
				}
			}
			formatter.Close();
		}

		private static void Usage()
		{
			System.Console.Out.WriteLine("CppTranslater PathToAssemble");
		}
	}
}
