using ICSharpCode.Decompiler.CSharp.Syntax;
using System;
using System.Collections.Generic;
using System.Text;

namespace CppTranslator
{
	class ProtoTypeVisitor : CppVisitorBase
	{
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
			bool isClass = false;
			switch (typeDeclaration.ClassType)
			{
				case ClassType.Enum:
					Formatter.AppendIndented("enum ");
					break;
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
			if (typeDeclaration.ClassType == ClassType.Enum)
			{
				OutputEnumValues(typeDeclaration);
			}
			else
			{
				Formatter.Append(";");
			}
			if (isClass)
			{
				Formatter.AppendLine("");
				Formatter.AppendIndented("typedef PointerType<");
				Formatter.AppendName(typeDeclaration.Name);
				Formatter.Append("Raw>\t");
				Formatter.AppendName(typeDeclaration.Name);
				Formatter.Append(";");
			}
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
	}
}
