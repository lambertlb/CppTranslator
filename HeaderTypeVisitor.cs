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
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.Semantics;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;
using System.Linq;

namespace CppTranslator
{
	/// <summary>
	/// Custom visitor for creating .h file
	/// </summary>
	public class HeaderTypeVisitor : CppVisitorBase
	{
		/// <summary>
		/// Keep track of declarations useful for parentage and ordering
		/// </summary>
		private List<TypeDeclaration> declarations = new List<TypeDeclaration>();
		/// <summary>
		/// Keep track of namespaces useful for formatting using statements
		/// </summary>
		private Dictionary<String, String> namespaces = new Dictionary<String, String>();
		/// <summary>
		/// Initializes a new instance of the <see cref="HeaderTypeVisitor"/> class.
		/// Constructor
		/// </summary>
		/// <param name="formatter">for output</param>
		public HeaderTypeVisitor(Formatter formatter) : base(formatter)
		{
		}
		/// <summary>
		/// Add header to .h file
		/// </summary>
		public override void AddHeaders()
		{
			Formatter.AppendLine("#pragma once");
			Formatter.AppendLine("#include \"CaBlockProtos.h\"");
			declarations.Clear();
		}
		/// <inheritdoc/>
		public override void VisitSyntaxTree(SyntaxTree syntaxTree)
		{
			foreach (AstNode node in syntaxTree.Children)
			{
				node.AcceptVisitor(this);
			}
		}
		/// <summary>
		/// Create header information from type declaration
		/// </summary>
		public override void CreateHeaders()
		{
			// output stucts before classes
			foreach (TypeDeclaration declaration in declarations)
			{
				if (declaration.ClassType == ClassType.Struct)
				{
					HeaderTypeDeclaration(declaration);
				}
			}
			foreach (TypeDeclaration declaration in declarations)
			{
				if (declaration.ClassType == ClassType.Class)
				{
					HeaderTypeDeclaration(declaration);
				}
			}
			WriteUsingNamespaces();
		}
		/// <summary>
		/// Output using namespaces
		/// </summary>
		private void WriteUsingNamespaces()
		{
			foreach (String ns in namespaces.Values)
			{
				Formatter.Append("using namespace ");
				if (String.IsNullOrEmpty(ns))
					Formatter.Append("UNNAMED");
				else
					Formatter.Append(ns + "_NS");
				Formatter.AppendLine(";");
			}
		}
		/// <inheritdoc/>
		public override void VisitTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			// sort by parentage
			if (typeDeclaration.ClassType != ClassType.Enum)
			{
				for (int i = 0; i < declarations.Count; ++i)
				{
					if (IsParentOf(typeDeclaration, declarations[i]))
					{
						declarations.Insert(i, typeDeclaration);
						return;
					}
				}
				declarations.Add(typeDeclaration);
			}
		}
		/// <summary>
		/// Is this parent of
		/// </summary>
		/// <param name="possibleParent">possible parent</param>
		/// <param name="possibleChild">possible child</param>
		/// <returns>true if parent</returns>
		private bool IsParentOf(TypeDeclaration possibleParent, TypeDeclaration possibleChild)
		{
			IType parentType = possibleParent.GetResolveResult().Type;
			foreach (AstType dependant in possibleChild.BaseTypes)
			{
				IType childtype = dependant.GetResolveResult().Type;
				if (parentType.FullName == childtype.FullName)
				{
					return (true);
				}
			}
			return (false);
		}
		/// <summary>
		/// Header type declaration
		/// </summary>
		/// <param name="typeDeclaration">type declaration</param>
		protected override void HeaderTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			IType type = typeDeclaration.Annotation<TypeResolveResult>().Type;
			Formatter.NameSpace = type.Namespace;
			if (!namespaces.ContainsKey(type.Namespace))
				namespaces.Add(type.Namespace, type.Namespace);
			OutputEntityType(typeDeclaration);
			TypeVisitor.FormatType(type);
			OutputParentage(typeDeclaration, type);
			Formatter.AddOpenBrace();
			if (typeDeclaration.ClassType != ClassType.Struct)
				Formatter.AppendIndentedLine("public:");
			foreach (var member in typeDeclaration.Members)
			{
				member.AcceptVisitor(this);
			}
			Formatter.AddCloseBrace(true);
		}
		private void OutputParentage(TypeDeclaration typeDeclaration, IType type)
		{
			if (typeDeclaration.BaseTypes.Any())
			{
				Formatter.Append(" : public ");
				WriteBaseClasses(typeDeclaration.BaseTypes);
			}
			else if (type.Kind == TypeKind.Class || type.Kind == TypeKind.Struct)
			{
				Formatter.Append(" : public Object");
			}
		}
		private void OutputEntityType(TypeDeclaration typeDeclaration)
		{
			switch (typeDeclaration.ClassType)
			{
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
		}

		/// <summary>
		/// Add base classes to output
		/// </summary>
		/// <param name="nodes">list of classes</param>
		protected void WriteBaseClasses(IEnumerable<AstNode> nodes)
		{
			bool isFirst = true;
			foreach (AstNode node in nodes)
			{
				IType type = node.Annotation<TypeResolveResult>().Type;
				if (!isFirst)
				{
					Formatter.Append(",");
				}
				node.AcceptVisitor(this);
				isFirst = false;
			}
		}
		/// <inheritdoc/>
		public override void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
			bool isStatic = (constructorDeclaration.Modifiers & Modifiers.Static) != 0;
			TypeDeclaration type = constructorDeclaration.Parent as TypeDeclaration;
			String name = null;
			if (type != null && type.Name != constructorDeclaration.Name)
				name = type.NameToken.Name;
			else
				name = constructorDeclaration.NameToken.Name;
			Formatter.AppendIndented(String.Empty);
			if (!isStatic)
			{
				IType type2 = constructorDeclaration.GetResolveResult().Type;
				WriteMethodHeader(name, constructorDeclaration.Parameters);
				Formatter.AppendLine(";");
			}
			else
			{
				Formatter.Append("static Boolean ");
				Formatter.AppendName(name);
				Formatter.AppendLine("_Static();");
				Formatter.AppendIndented("static Boolean ");
				Formatter.AppendName(name);
				Formatter.AppendLine("_Initilized;");
			}
		}
		/// <inheritdoc/>
		public override void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
			Formatter.AppendIndented(String.Empty);
			WriteModifiers(methodDeclaration.ModifierTokens);
			IType type = methodDeclaration.ReturnType.GetResolveResult().Type;
			TypeVisitor.FormatTypeDelaration(type);
			Formatter.Append(" ");
			WriteMethodHeader(methodDeclaration.NameToken.Name, methodDeclaration.Parameters);
			if (methodDeclaration.Body.IsNull)
				Formatter.Append(" = 0");
			Formatter.AppendLine(";");
		}
		/// <inheritdoc/>
		protected override void WriteMethodHeader(String methodName, AstNodeCollection<ParameterDeclaration> parameters)
		{
			Formatter.AppendName(methodName);
			WriteCommaSeparatedListInParenthesis(parameters);
		}
		/// <inheritdoc/>
		public override void VisitFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
			VariableInitializer variable = fieldDeclaration.Variables.First<VariableInitializer>();
			Formatter.AppendIndented(String.Empty);
			var sym = fieldDeclaration.GetSymbol() as IEntity;
			if (sym != null && sym.IsStatic)
			{
				Formatter.Append("static ");
			}
			IType type = fieldDeclaration.ReturnType.GetResolveResult().Type;
			TypeVisitor.FormatTypeDelaration(type);
			Formatter.Append(" ");
			WriteCommaSeparatedList(fieldDeclaration.Variables);
			Formatter.AppendLine(";");
		}
		/// <inheritdoc/>
		public override void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			Formatter.AppendName(variableInitializer.Name);
		}
		/// <inheritdoc/>
		public override void VisitPropertyDeclaration(PropertyDeclaration propertyDeclaration)
		{
			IType type = propertyDeclaration.ReturnType.GetResolveResult().Type;
			if (propertyDeclaration.Getter != null)
			{
				Formatter.AppendIndented(String.Empty);
				TypeVisitor.FormatTypeDelaration(type);
				Formatter.Append(" get_");
				Formatter.Append(propertyDeclaration.NameToken.Name);
				Formatter.AppendLine("();");
			}
			if (propertyDeclaration.Setter != null)
			{
				Formatter.AppendIndented("void set_");
				Formatter.Append(propertyDeclaration.NameToken.Name);
				Formatter.Append("(");
				TypeVisitor.FormatTypeDelaration(type);
				Formatter.AppendLine(" x_value );");
			}
			ICSharpCode.Decompiler.IL.ILFunction inst = propertyDeclaration.Getter.Annotation<ICSharpCode.Decompiler.IL.ILFunction>();
			String hiddenName = MyIlVisitor.GetHiddenPropertyName(inst.Body as ICSharpCode.Decompiler.IL.BlockContainer);
			if (!String.IsNullOrEmpty(hiddenName))
			{
				Formatter.AppendIndented(String.Empty);
				TypeVisitor.FormatTypeDelaration(type);
				Formatter.Append(" ");
				Formatter.Append(hiddenName);
				Formatter.AppendLine(";");
			}
		}
		/// <inheritdoc/>
		public override void VisitOperatorDeclaration(OperatorDeclaration operatorDeclaration)
		{
			Formatter.AppendIndented("static ");
			operatorDeclaration.ReturnType.AcceptVisitor(this);
			Formatter.Append(" ");
			Formatter.Append(Operators[operatorDeclaration.OperatorType]);
			WriteCommaSeparatedListInParenthesis(operatorDeclaration.Parameters);
			Formatter.AppendLine(";");
		}
	}
}
