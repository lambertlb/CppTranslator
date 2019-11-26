using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.Metadata;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection.Metadata;

namespace CppTranslator
{
	class Program
	{
		static String pathToAssemble;
		static CSharpDecompiler compiler;
		static Formatter formatter = new Formatter();
		static CppVisitorBase visitor = new CppVisitorBase(formatter);
		static ProtoTypeVisitor prototypeVisitor = new ProtoTypeVisitor(formatter);
		static HeaderTypeVisitor headerVisitor = new HeaderTypeVisitor(formatter);
		static Boolean setOutput;

		static void Main(string[] args)
		{
			if (args.Length != 1)
			{
				Usage();
				return;
			}
			GetPathToAssembly(args);
			compiler = new CSharpDecompiler(args[0], new ICSharpCode.Decompiler.DecompilerSettings());
			formatter.EmitToConsole = true;
			ProcessModules(prototypeVisitor, pathToAssemble + "Protos.h");
			ProcessModules(headerVisitor, pathToAssemble + "Header.h");
			ProcessModules(visitor, pathToAssemble + ".cpp");
		}

		private static void GetPathToAssembly(string[] args)
		{
			int index;
			if (args[0].Contains("/"))
			{
				index = args[0].LastIndexOf('/');
			} else
			{
				index = args[0].LastIndexOf('\\');
			}
			String path = args[0].Substring(0, index + 1);
			Directory.CreateDirectory(path + "Tests/generated/");
			pathToAssemble = path + "Tests/generated/CaBlock";
		}

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
							if (!typeDefinition.Name.StartsWith("<") && !typeDefinition.Namespace.Contains("BlockBase") && !typeDefinition.Namespace.Contains("SysCommon"))
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
