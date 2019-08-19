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
		static void Main(string[] args)
		{
			CSharpDecompiler compiler = new CSharpDecompiler("..\\..\\..\\UnitTestDll.dll", new ICSharpCode.Decompiler.DecompilerSettings());
			foreach (IModule module in compiler.TypeSystem.Modules)
			{
				if (module.IsMainModule)
				{
					foreach (ITypeDefinition typeDefinition in module.TopLevelTypeDefinitions)
					{
						if (typeDefinition.Kind == TypeKind.Class)
						{
							if (!typeDefinition.Name.StartsWith("<"))
							{
								List<EntityHandle> entities = new List<EntityHandle>() { typeDefinition.MetadataToken };
								SyntaxTree syntaxTree = compiler.Decompile(entities);
								syntaxTree.AcceptVisitor(new CppVisitor());
								Console.WriteLine("--------------------------------------------------------------------");
							}
						}
					}
				}
			}
		}
	}
}
