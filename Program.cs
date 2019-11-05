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
		static CppVisitor visitor = new CppVisitor();
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
			visitor.EmitToConsole = true;
			CreatePrototypes();
			CreateHeaderFile();
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

		private static void CreatePrototypes()
		{
			setOutput = false;
			visitor.DoProtyping = true;
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
									visitor.OutputName = pathToAssemble + "Protos.h";
									setOutput = true;
									AppendProtoPreamble();
								}
								visitor.Name_space = typeDefinition.Namespace;
								List<EntityHandle> entities = new List<EntityHandle>() { typeDefinition.MetadataToken };
								SyntaxTree syntaxTree = compiler.Decompile(entities);
								syntaxTree.AcceptVisitor(visitor);
								visitor.AppendLine("");
							}
						}
					}
				}
			}
			visitor.Close();
		}

		private static void AppendProtoPreamble()
		{
			visitor.AppendLine("#pragma once");
			visitor.AppendLine("#include \"DotnetTypes.h\"");
			visitor.AppendLine("using namespace DotnetLibrary;");
			visitor.AppendLine("");
		}
		private static void AppendHeaderPreamble()
		{
			visitor.AppendLine("#include \"CaBlockProtos.h\"");
		}

		private static void CreateHeaderFile()
		{
			setOutput = false;
			visitor.DoHeaderFile = true;
			foreach (IModule module in compiler.TypeSystem.Modules)
			{
				if (module.IsMainModule)
				{
					foreach (ITypeDefinition typeDefinition in module.TopLevelTypeDefinitions)
					{
						if (typeDefinition.Kind == TypeKind.Class || typeDefinition.Kind == TypeKind.Struct)
						{
							if (!typeDefinition.Name.StartsWith("<") && !typeDefinition.Namespace.Contains("BlockBase") && !typeDefinition.Namespace.Contains("SysCommon"))
							{
								if (!setOutput)
								{
									visitor.OutputName = pathToAssemble + "Header.h";
									setOutput = true;
									AppendHeaderPreamble();
								}
								if (typeDefinition.Name.Contains("TimeTest"))
								{
									visitor.Name_space = typeDefinition.Namespace;
								}
								visitor.Name_space = typeDefinition.Namespace;
								List<EntityHandle> entities = new List<EntityHandle>() { typeDefinition.MetadataToken };
								SyntaxTree syntaxTree = compiler.Decompile(entities);
								syntaxTree.AcceptVisitor(visitor);
								visitor.AppendLine("");
							}
						}
					}
				}
			}
			visitor.Close();
		}

		private static void Usage()
		{
			System.Console.Out.WriteLine("CppTranslater PathToAssemble");
		}
	}
}
