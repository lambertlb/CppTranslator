using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CppTranslator
{
	public class HeaderTypeVisitor : CppVisitorBase
	{
		public HeaderTypeVisitor(Formatter formatter) : base(formatter)
		{
		}
		public override void AddHeaders()
		{
			Formatter.AppendLine("#pragma once");
			Formatter.AppendLine("#include \"CaBlockProtos.h\"");
		}

		protected override void HeaderTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			HadConstructor = false;
			bool isClass = false;
			var sym = typeDeclaration.GetSymbol();
			switch (typeDeclaration.ClassType)
			{
				case ClassType.Interface:
					Formatter.AppendIndented("class ");
					isClass = true;
					break;
				case ClassType.Struct:
					Formatter.AppendIndented("struct ");
					isClass = true;
					break;
				default:
					Formatter.AppendIndented("class ");
					isClass = true;
					break;
			}
			Formatter.AppendName(typeDeclaration.Name);
			if (isClass)
			{
				Formatter.Append("Raw");
			}
			Formatter.AddOpenBrace();
			if (typeDeclaration.ClassType != ClassType.Struct)
			{
				Formatter.AppendIndentedLine("public:");
			}
			foreach (var member in typeDeclaration.Members)
			{
				member.AcceptVisitor(this);
			}
			if (isClass && !HadConstructor)
			{
				CreateDefaultConstructor(typeDeclaration);
			}
			Formatter.AddCloseBrace(true);
		}

		public override void CreateDefaultConstructor(TypeDeclaration typeDeclaration)
		{
			Formatter.AppendIndented("");
			Formatter.AppendName(typeDeclaration.Name);
			Formatter.AppendLine("Raw();");
		}

		public override void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
			HadConstructor = true;
			TypeDeclaration type = constructorDeclaration.Parent as TypeDeclaration;
			String name = null;
			if (type != null && type.Name != constructorDeclaration.Name)
				name = type.NameToken.Name;
			else
				name = constructorDeclaration.NameToken.Name;
			Formatter.AppendIndented("");
			WriteMethodHeader(name + "Raw", constructorDeclaration.Parameters);
			Formatter.AppendLine(";");
		}
		public override void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
			Formatter.AppendIndented("");
			WriteModifiers(methodDeclaration.ModifierTokens);
			methodDeclaration.ReturnType.AcceptVisitor(this);
			Formatter.Append(" ");
			WriteMethodHeader(methodDeclaration.NameToken.Name, methodDeclaration.Parameters);
			Formatter.AppendLine(";");
		}
		protected override void WriteMethodHeader(String medodName, AstNodeCollection<ParameterDeclaration> parameters)
		{
			Formatter.AppendName(medodName);
			WriteCommaSeparatedListInParenthesis(parameters);
		}
		public override void VisitFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
			VariableInitializer variable = fieldDeclaration.Variables.First<VariableInitializer>();
			Formatter.AppendIndented("");
			var sym = fieldDeclaration.GetSymbol() as IEntity;
			if (sym != null && sym.IsStatic)
			{
				Formatter.Append("static ");
			}
			fieldDeclaration.ReturnType.GetResolveResult().Type.AcceptVisitor(TypeVisitor);
			Formatter.Append(" ");
			WriteCommaSeparatedList(fieldDeclaration.Variables);
			Formatter.AppendLine(";");
		}
		public override void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			Formatter.AppendName(variableInitializer.Name);
			//if (!variableInitializer.Initializer.IsNull)
			//{
			//	Formatter.Append(" = ");
			//	variableInitializer.Initializer.AcceptVisitor(this);
			//}
		}
	}
}
