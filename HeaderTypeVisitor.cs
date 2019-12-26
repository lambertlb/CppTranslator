using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.Semantics;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;
using System.Linq;

namespace CppTranslator
{
	public class HeaderTypeVisitor : CppVisitorBase
	{
		private List<TypeDeclaration> declarations = new List<TypeDeclaration>();
		private Dictionary<String, String> namespaces = new Dictionary<String, String>();
		public HeaderTypeVisitor(Formatter formatter) : base(formatter)
		{
		}
		public override void AddHeaders()
		{
			Formatter.AppendLine("#pragma once");
			Formatter.AppendLine("#include \"CaBlockProtos.h\"");
			declarations.Clear();
		}
		public override void VisitSyntaxTree(SyntaxTree syntaxTree)
		{
			foreach (AstNode node in syntaxTree.Children)
			{
				node.AcceptVisitor(this);
			}
		}

		public override void CreateHeaders()
		{
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

		public override void VisitTypeDeclaration(TypeDeclaration typeDeclaration)
		{
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

		protected override void HeaderTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			IType type = typeDeclaration.Annotation<TypeResolveResult>().Type;
			Formatter.NameSpace = type.Namespace;
			if (!namespaces.ContainsKey(type.Namespace))
				namespaces.Add(type.Namespace, type.Namespace);
			var sym = typeDeclaration.GetSymbol();
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
			TypeVisitor.FormatType(type);
			if (typeDeclaration.BaseTypes.Any())
			{
				Formatter.Append(" : public ");
				WriteBaseClasses(typeDeclaration.BaseTypes);
			}
			else if (type.Kind == TypeKind.Class || type.Kind == TypeKind.Struct)
			{
				Formatter.Append(" : public Object");
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
			Formatter.AddCloseBrace(true);
		}
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
		public override void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
			TypeDeclaration type = constructorDeclaration.Parent as TypeDeclaration;
			String name = null;
			if (type != null && type.Name != constructorDeclaration.Name)
				name = type.NameToken.Name;
			else
				name = constructorDeclaration.NameToken.Name;
			Formatter.AppendIndented("");
			IType type2 = constructorDeclaration.GetResolveResult().Type;
			WriteMethodHeader(name, constructorDeclaration.Parameters);
			Formatter.AppendLine(";");
		}
		public override void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
			Formatter.AppendIndented("");
			WriteModifiers(methodDeclaration.ModifierTokens);
			IType type = methodDeclaration.ReturnType.GetResolveResult().Type;
			TypeVisitor.FormatTypeDelaration(type);
			Formatter.Append(" ");
			WriteMethodHeader(methodDeclaration.NameToken.Name, methodDeclaration.Parameters);
			if (methodDeclaration.Body.IsNull)
			{
				Formatter.Append(" = 0");
			}
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
			IType type = fieldDeclaration.ReturnType.GetResolveResult().Type;
			TypeVisitor.FormatTypeDelaration(type);
			Formatter.Append(" ");
			WriteCommaSeparatedList(fieldDeclaration.Variables);
			Formatter.AppendLine(";");
		}
		public override void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			Formatter.AppendName(variableInitializer.Name);
		}
		public override void VisitPropertyDeclaration(PropertyDeclaration propertyDeclaration)
		{
			IType type = propertyDeclaration.ReturnType.GetResolveResult().Type;
			if (propertyDeclaration.Getter != null)
			{
				Formatter.AppendIndented("");
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
				Formatter.AppendIndented("");
				TypeVisitor.FormatTypeDelaration(type);
				Formatter.Append(" ");
				Formatter.Append(hiddenName);
				Formatter.AppendLine(";");
			}
		}
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
