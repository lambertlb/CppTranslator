using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.Semantics;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;
using System.Text;

namespace CppTranslator
{
	class ProtoTypeVisitor : CppVisitorBase
	{
		private String EnumName { get; set; }
		public ProtoTypeVisitor(Formatter formatter) : base(formatter)
		{
		}
		public override void AddHeaders()
		{
			Formatter.AppendLine("#pragma once");
			Formatter.AppendLine("#include \"DotnetTypes.h\"");
			Formatter.AppendLine("using namespace DotnetLibrary;");
			Formatter.AppendLine("");
		}

		public override void VisitTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			IType type = typeDeclaration.Annotation<TypeResolveResult>().Type;
			Formatter.Name_space = type.Namespace;
			bool isClass = type.Kind == TypeKind.Class;
			switch (typeDeclaration.ClassType)
			{
				case ClassType.Enum:
					Formatter.AppendIndented("enum ");
					break;
				case ClassType.Interface:
					Formatter.AppendIndented("class ");
					break;
				case ClassType.Struct:
					Formatter.AppendIndented("struct ");
					break;
				default:
					Formatter.AppendIndented("class ");
					break;
			}
			FormatType(type);
			if (typeDeclaration.ClassType == ClassType.Enum)
			{
				OutputEnumValues(typeDeclaration);
			}
			else
			{
				Formatter.Append(";");
			}
			Formatter.AppendLine("");
		}
		private void OutputEnumValues(TypeDeclaration typeDeclaration)
		{
			EnumName = typeDeclaration.Name;
			Formatter.AddOpenBrace();
			bool first = true;
			foreach (var member in typeDeclaration.Members)
			{
				if (!first)
				{
					Formatter.AppendLine(",");
				}
				member.AcceptVisitor(this);
				first = false;
			}
			Formatter.AddCloseBrace(true);
		}
		public override void VisitEnumMemberDeclaration(EnumMemberDeclaration enumMemberDeclaration)
		{
			Formatter.AppendIndentedName(enumMemberDeclaration.NameToken.Name);
			Formatter.Append("_");
			Formatter.Append(EnumName);
			if (!enumMemberDeclaration.Initializer.IsNull)
			{
				Formatter.Append(" = ");
				enumMemberDeclaration.Initializer.AcceptVisitor(this);
			}
		}
	}
}
