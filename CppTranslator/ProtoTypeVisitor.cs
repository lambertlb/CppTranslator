// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sub-license, and/or sell copies of the Software, and to permit persons
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
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.Semantics;
using ICSharpCode.Decompiler.TypeSystem;

namespace CppTranslator
{
	/// <summary>
	/// Worker for handling functional prototypes
	/// This will define all forward references for classes and all enumerations.
	/// To make sure they are unique all enum will have there enum name appended to the end of each value
	/// </summary>
	public class ProtoTypeVisitor : CppVisitorBase
	{
		private String EnumName { get; set; }
		/// <summary>
		/// Initializes a new instance of the <see cref="ProtoTypeVisitor"/> class.
		/// Constructor
		/// </summary>
		/// <param name="formatter">for output</param>
		public ProtoTypeVisitor(Formatter formatter) : base(formatter)
		{
		}
		/// <summary>
		/// Add headers to output
		/// </summary>
		public override void AddHeaders()
		{
			Formatter.AppendLine("#pragma once");
			Formatter.AppendLine("#include \"DotnetTypes.h\"");
			Formatter.AppendLine("#include <DotNetLibrarySupport.h>");
			Formatter.AppendLine("using namespace DotnetLibrary;");
			Formatter.AppendLine("using namespace DotnetLibrarySupport;");
			Formatter.AppendLine(String.Empty);
		}
		/// <inheritdoc/>
		public override void VisitTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			IType type = typeDeclaration.Annotation<TypeResolveResult>().Type;
			Formatter.NameSpace = type.Namespace;
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
			TypeVisitor.FormatType(type);
			if (typeDeclaration.ClassType == ClassType.Enum)
			{
				OutputEnumValues(typeDeclaration);
			}
			else
			{
				Formatter.Append(";");
			}
			Formatter.AppendLine(String.Empty);
		}
		/// <summary>
		/// Output all values in an enum.
		/// Append the enum name to end to ensure they are unique.
		/// </summary>
		/// <param name="typeDeclaration">enum declaration</param>
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
		/// <inheritdoc/>
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
