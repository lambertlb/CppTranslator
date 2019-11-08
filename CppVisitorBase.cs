using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.CSharp.Syntax.PatternMatching;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace CppTranslator
{
	public class CppVisitorBase : IAstVisitor
	{
		private CppTypeVisitor typeVisitor;
		private Formatter formatter;
		private String enumName;
		public String EnumName { get => enumName; set => enumName = value; }
		public String CurrentClass { get; set; }

		public CppTypeVisitor TypeVisitor { get => typeVisitor; }
		public Formatter Formatter { get => formatter; }

		public CppVisitorBase(Formatter formatter)
		{
			this.formatter = formatter;
			typeVisitor = new CppTypeVisitor(formatter);
		}
		public void VisitAccessor(Accessor accessor)
		{
		}
		public virtual void AddHeaders()
		{
			Formatter.AppendLine("#pragma once");
			formatter.AppendLine("#include \"CaBlockHeader.h\"");
		}
		public void VisitAnonymousMethodExpression(AnonymousMethodExpression anonymousMethodExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitAnonymousTypeCreateExpression(AnonymousTypeCreateExpression anonymousTypeCreateExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitArrayCreateExpression(ArrayCreateExpression arrayCreateExpression)
		{
			Formatter.Append("new ");
			arrayCreateExpression.Type.AcceptVisitor(this);
			if (arrayCreateExpression.Arguments.Count > 0)
			{
				WriteCommaSeparatedListInBrackets(arrayCreateExpression.Arguments);
			}
			foreach (var specifier in arrayCreateExpression.AdditionalArraySpecifiers)
			{
				specifier.AcceptVisitor(this);
			}
			arrayCreateExpression.Initializer.AcceptVisitor(this);
		}

		private void WriteCommaSeparatedListInBrackets(AstNodeCollection<Expression> arguments)
		{
			Formatter.Append("[");
			WriteCommaSeparatedList(arguments);
			Formatter.Append("]");
		}

		public void VisitArrayInitializerExpression(ArrayInitializerExpression arrayInitializerExpression)
		{
			bool bracesAreOptional = arrayInitializerExpression.Elements.Count == 1
				&& IsObjectOrCollectionInitializer(arrayInitializerExpression.Parent)
				&& !CanBeConfusedWithObjectInitializer(arrayInitializerExpression.Elements.Single());
			if (bracesAreOptional && arrayInitializerExpression.LBraceToken.IsNull)
			{
				arrayInitializerExpression.Elements.Single().AcceptVisitor(this);
			}
			else
			{
				PrintInitializerElements(arrayInitializerExpression.Elements);
			}
		}
		protected virtual void PrintInitializerElements(AstNodeCollection<Expression> elements)
		{
			Formatter.Append("[");
			bool isFirst = true;
			AstNode last = null;
			foreach (AstNode node in elements)
			{
				if (isFirst)
				{
					isFirst = false;
				}
				else
				{
					Formatter.Append(",");
				}
				last = node;
				node.AcceptVisitor(this);
			}
			Formatter.Append("]");
		}
		protected bool CanBeConfusedWithObjectInitializer(Expression expr)
		{
			AssignmentExpression ae = expr as AssignmentExpression;
			return ae != null && ae.Operator == AssignmentOperatorType.Assign;
		}

		protected bool IsObjectOrCollectionInitializer(AstNode node)
		{
			if (!(node is ArrayInitializerExpression))
			{
				return false;
			}
			if (node.Parent is ObjectCreateExpression)
			{
				return node.Role == ObjectCreateExpression.InitializerRole;
			}
			if (node.Parent is NamedExpression)
			{
				return node.Role == Roles.Expression;
			}
			return false;
		}

		public void VisitArraySpecifier(ArraySpecifier arraySpecifier)
		{
			Formatter.Append("[");
			foreach (var comma in arraySpecifier.GetChildrenByRole(Roles.Comma))
			{
				Formatter.Append(",");
			}
			Formatter.Append("]");
		}

		public void VisitAsExpression(AsExpression asExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitAssignmentExpression(AssignmentExpression assignmentExpression)
		{
			bool isAssignToPointer = IsAssignToPointer(assignmentExpression.Left) && assignmentExpression.Operator == AssignmentOperatorType.Assign;
			assignmentExpression.Left.AcceptVisitor(this);
			if (isAssignToPointer)
			{
				Formatter.Append(".Assign(");
			}
			else
			{
				Formatter.Append(" ");
				Formatter.Append(AssignmentExpression.GetOperatorRole(assignmentExpression.Operator).ToString());
				Formatter.Append(" ");
			}
			assignmentExpression.Right.AcceptVisitor(this);
			if (isAssignToPointer)
			{
				Formatter.Append(")");
			}
		}

		private bool IsAssignToPointer(Expression left)
		{
			TypeKind expressionKind = left.GetResolveResult().Type.Kind;
			return (expressionKind == TypeKind.Array || expressionKind == TypeKind.Class);
		}

		public void VisitAttribute(ICSharpCode.Decompiler.CSharp.Syntax.Attribute attribute)
		{
			throw new NotImplementedException();
		}

		public void VisitAttributeSection(AttributeSection attributeSection)
		{
			throw new NotImplementedException();
		}

		public void VisitBaseReferenceExpression(BaseReferenceExpression baseReferenceExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitBinaryOperatorExpression(BinaryOperatorExpression binaryOperatorExpression)
		{
			binaryOperatorExpression.Left.AcceptVisitor(this);
			Formatter.Append(" ");
			Formatter.Append(BinaryOperatorExpression.GetOperatorRole(binaryOperatorExpression.Operator).ToString());
			Formatter.Append(" ");
			binaryOperatorExpression.Right.AcceptVisitor(this);
		}

		public void VisitBlockStatement(BlockStatement blockStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitBreakStatement(BreakStatement breakStatement)
		{
			Formatter.Append("break;");
		}

		public void VisitCaseLabel(CaseLabel caseLabel)
		{
			if (caseLabel.Expression.IsNull)
			{
				Formatter.Append("default");
			}
			else
			{
				Formatter.Append("case ");
				caseLabel.Expression.AcceptVisitor(this);
			}
			Formatter.Append(":");
		}

		public void VisitCastExpression(CastExpression castExpression)
		{
			Formatter.Append("( ");
			castExpression.Type.AcceptVisitor(this);
			Formatter.Append(" ) ");
			castExpression.Expression.AcceptVisitor(this);
		}

		public void VisitCatchClause(CatchClause catchClause)
		{
			throw new NotImplementedException();
		}

		public void VisitCheckedExpression(CheckedExpression checkedExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitCheckedStatement(CheckedStatement checkedStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitComment(Comment comment)
		{
			throw new NotImplementedException();
		}

		public void VisitComposedType(ComposedType composedType)
		{
			if (composedType.ArraySpecifiers.Count > 0)
			{
				composedType.GetResolveResult().Type.AcceptVisitor(TypeVisitor);
				return;
			}
			composedType.BaseType.AcceptVisitor(this);
			foreach (var node in composedType.ArraySpecifiers)
			{
				node.AcceptVisitor(this);
			}
		}

		public void VisitConditionalExpression(ConditionalExpression conditionalExpression)
		{
			conditionalExpression.Condition.AcceptVisitor(this);
			Formatter.Append(" ? ");
			conditionalExpression.TrueExpression.AcceptVisitor(this);
			Formatter.Append(" : ");
			conditionalExpression.FalseExpression.AcceptVisitor(this);
		}

		public void VisitConstraint(Constraint constraint)
		{
			throw new NotImplementedException();
		}

		protected virtual void WriteMethodHeader(String medodName, AstNodeCollection<ParameterDeclaration> parameters)
		{
			Formatter.AppendName(CurrentClass);
			Formatter.Append("Raw::");
			Formatter.AppendName(medodName);
			if (CurrentClass == medodName)
			{
				Formatter.Append("Raw");
			}
			WriteCommaSeparatedListInParenthesis(parameters);
		}
		protected virtual void WriteMethod(String medodName, AstNodeCollection<ParameterDeclaration> parameters, BlockStatement body)
		{
			WriteMethodHeader(medodName, parameters);
			WriteBlock(body);
		}

		private void WriteBlock(BlockStatement body)
		{
			Formatter.AddOpenBrace();
			foreach (var node in body.Statements)
			{
				Formatter.AppendIndented("");
				node.AcceptVisitor(this);
				Formatter.AppendLine("");
			}
			Formatter.AddCloseBrace();
		}

		public virtual void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
			TypeDeclaration type = constructorDeclaration.Parent as TypeDeclaration;
			String name = null;
			if (type != null && type.Name != constructorDeclaration.Name)
				name = type.NameToken.Name;
			else
				name = constructorDeclaration.NameToken.Name;
			Formatter.AppendIndented("");
			WriteMethod(name, constructorDeclaration.Parameters, constructorDeclaration.Body);
		}

		public void VisitConstructorInitializer(ConstructorInitializer constructorInitializer)
		{
			throw new NotImplementedException();
		}

		public void VisitContinueStatement(ContinueStatement continueStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitCSharpTokenNode(CSharpTokenNode cSharpTokenNode)
		{
			throw new NotImplementedException();
		}

		public void VisitCustomEventDeclaration(CustomEventDeclaration customEventDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitDefaultValueExpression(DefaultValueExpression defaultValueExpression)
		{
			Formatter.Append("default ");
			Formatter.Append("(");
			Formatter.Append(" ");
			defaultValueExpression.Type.AcceptVisitor(this);
			Formatter.Append(" ");
			Formatter.Append(")");
		}

		public void VisitDelegateDeclaration(DelegateDeclaration delegateDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitDestructorDeclaration(DestructorDeclaration destructorDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitDirectionExpression(DirectionExpression directionExpression)
		{
			switch (directionExpression.FieldDirection)
			{
				case FieldDirection.Out:
					Formatter.Append("out");
					break;
				case FieldDirection.Ref:
					Formatter.Append("ref");
					break;
				case FieldDirection.In:
					Formatter.Append("in");
					break;
				default:
					throw new NotSupportedException("Invalid value for FieldDirection");
			}
			Formatter.Append(" ");
			directionExpression.Expression.AcceptVisitor(this);
		}

		public void VisitDocumentationReference(DocumentationReference documentationReference)
		{
			throw new NotImplementedException();
		}

		public void VisitDoWhileStatement(DoWhileStatement doWhileStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitEmptyStatement(EmptyStatement emptyStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitEnumMemberDeclaration(EnumMemberDeclaration enumMemberDeclaration)
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

		public void VisitErrorNode(AstNode errorNode)
		{
			throw new NotImplementedException();
		}

		public void VisitEventDeclaration(EventDeclaration eventDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitExpressionStatement(ExpressionStatement expressionStatement)
		{
			expressionStatement.Expression.AcceptVisitor(this);
			Formatter.Append(";");
		}

		public void VisitExternAliasDeclaration(ExternAliasDeclaration externAliasDeclaration)
		{
			throw new NotImplementedException();
		}

		public virtual void VisitFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
		}

		private void AssignVariableName(IType type, String name)
		{
			if (type != null && IsPointerType(type))
			{
				Formatter.Append(".Assign(");
				Formatter.Append(name);
				Formatter.Append(")");
			}
			else
			{
				Formatter.Append(" ");
				Formatter.Append(name);
			}
		}

		public void FormatTypeDelaration(IType type, String typeName)
		{
			if (type != null && IsPointerType(type))
			{
				Formatter.Append("Pointer<");
				Formatter.Append(typeName);
				Formatter.Append(">");
				return;
			}
			Formatter.Append(typeName);
		}

		private bool IsPointerType(IType type)
		{
			return (type.Kind == TypeKind.Class || type.Kind == TypeKind.Array || type.IsByRefLike);
		}
		public void VisitFixedFieldDeclaration(FixedFieldDeclaration fixedFieldDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitFixedStatement(FixedStatement fixedStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitFixedVariableInitializer(FixedVariableInitializer fixedVariableInitializer)
		{
			throw new NotImplementedException();
		}

		public void VisitForeachStatement(ForeachStatement foreachStatement)
		{
			Formatter.Append("foreach ");
			Formatter.Append("(");
			foreachStatement.VariableType.AcceptVisitor(this);
			Formatter.Append(" ");
			WriteVariableName(foreachStatement.VariableNameToken);
			Formatter.Append(" in ");
			foreachStatement.InExpression.AcceptVisitor(this);
			Formatter.Append(" ");
			Formatter.Append(")");
			WriteEmbeddedStatement(foreachStatement.EmbeddedStatement);
		}

		private void WriteVariableName(Identifier nameIdentifier)
		{
			Formatter.Append(nameIdentifier.Name);
		}

		protected virtual void WriteEmbeddedStatement(Statement embeddedStatement)
		{
			Formatter.AppendLine("");
			BlockStatement block = embeddedStatement as BlockStatement;
			if (block != null)
			{
				WriteBlock(block);
				Formatter.AppendLine("");
			}
			else
			{
				Formatter.AppendLine("");
				embeddedStatement.AcceptVisitor(this);
			}
		}
		public void VisitForStatement(ForStatement forStatement)
		{
			Formatter.Append("for ( ");
			WriteCommaSeparatedList(forStatement.Initializers);
			Formatter.Append(" ;  ");
			forStatement.Condition.AcceptVisitor(this);
			Formatter.Append(" ;  ");
			if (forStatement.Iterators.Any())
			{
				Formatter.Append(" ");
				WriteCommaSeparatedList(forStatement.Iterators);
			}

			Formatter.Append(" )");
			WriteEmbeddedStatement(forStatement.EmbeddedStatement);
		}

		public void VisitGotoCaseStatement(GotoCaseStatement gotoCaseStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitGotoDefaultStatement(GotoDefaultStatement gotoDefaultStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitGotoStatement(GotoStatement gotoStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitIdentifier(Identifier identifier)
		{
			var res = identifier.GetResolveResult();
			var sym = identifier.GetSymbol();
			Formatter.Append(identifier.Name);
		}

		public void VisitIdentifierExpression(IdentifierExpression identifierExpression)
		{
			Formatter.AppendName(identifierExpression.IdentifierToken.Name);
		}

		public void VisitIfElseStatement(IfElseStatement ifElseStatement)
		{
			Formatter.Append("if ( ");
			ifElseStatement.Condition.AcceptVisitor(this);
			Formatter.Append(" )");
			if (ifElseStatement.FalseStatement.IsNull)
			{
				WriteEmbeddedStatement(ifElseStatement.TrueStatement);
			}
			else
			{
				WriteEmbeddedStatement(ifElseStatement.TrueStatement);
				Formatter.Append("else");
				if (ifElseStatement.FalseStatement is IfElseStatement)
				{
					// don't put newline between 'else' and 'if'
					ifElseStatement.FalseStatement.AcceptVisitor(this);
				}
				else
				{
					WriteEmbeddedStatement(ifElseStatement.FalseStatement);
				}
			}
		}

		public void VisitIndexerDeclaration(IndexerDeclaration indexerDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitIndexerExpression(IndexerExpression indexerExpression)
		{
			indexerExpression.Target.AcceptVisitor(this);
			Formatter.Append(" ");
			NewMethod(indexerExpression.Arguments);
		}

		private void NewMethod(IEnumerable<AstNode> nodes)
		{
			Formatter.Append("[ ");
			WriteCommaSeparatedList(nodes);
			Formatter.Append(" ]");
		}

		public void VisitInterpolatedStringExpression(InterpolatedStringExpression interpolatedStringExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitInterpolatedStringText(InterpolatedStringText interpolatedStringText)
		{
			throw new NotImplementedException();
		}

		public void VisitInterpolation(Interpolation interpolation)
		{
			throw new NotImplementedException();
		}

		public void VisitInvocationExpression(InvocationExpression invocationExpression)
		{
			invocationExpression.Target.AcceptVisitor(this);
			WriteCommaSeparatedListInParenthesis(invocationExpression.Arguments);
		}

		protected void WriteCommaSeparatedListInParenthesis(IEnumerable<AstNode> nodes)
		{
			Formatter.Append("(");
			WriteCommaSeparatedList(nodes);
			Formatter.Append(")");
		}

		private void WriteCommaSeparatedList(IEnumerable<AstNode> nodes)
		{
			bool isFirst = true;
			foreach (AstNode node in nodes)
			{
				if (!isFirst)
				{
					Formatter.Append(",");
				}
				node.AcceptVisitor(this);
				isFirst = false;
			}
		}

		public void VisitIsExpression(IsExpression isExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitLabelStatement(LabelStatement labelStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitLambdaExpression(LambdaExpression lambdaExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitLocalFunctionDeclarationStatement(LocalFunctionDeclarationStatement localFunctionDeclarationStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitLockStatement(LockStatement lockStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitMemberReferenceExpression(MemberReferenceExpression memberReferenceExpression)
		{
			IType type = memberReferenceExpression.GetResolveResult().Type;
			if (type.Kind == TypeKind.Unknown)
			{
				type = memberReferenceExpression.Parent.GetResolveResult().Type;
			}
			var sym = memberReferenceExpression.GetSymbol() as IEntity;
			if (sym == null)
			{
				sym = memberReferenceExpression.Parent.GetSymbol() as IEntity;
			}
			if (type.Kind == TypeKind.Enum)
			{
				HandleEnumExpression(type, sym);
				return;
			}
			memberReferenceExpression.Target.AcceptVisitor(this);
			if (sym != null && sym.IsStatic)
			{
				Formatter.Append("::");
			}
			else
			{
				if (type.Kind == TypeKind.Struct)
				{
					Formatter.Append(".");
				}
				else
				{
					Formatter.Append("->");
				}
			}
			Formatter.AppendName(memberReferenceExpression.MemberNameToken.Name);
		}

		private void HandleEnumExpression(IType type, IEntity sym)
		{
			Formatter.AppendName(sym.Name);
			Formatter.Append("_");
			Formatter.AppendName(type.Name);
		}

		public void VisitMemberType(MemberType memberType)
		{
			memberType.Target.AcceptVisitor(this);
		}

		public virtual void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
			Formatter.AppendIndented("");
			if (methodDeclaration.NameToken.Name == "BooleanOperatorTests")
			{
				Formatter.Append("");
			}
			methodDeclaration.ReturnType.AcceptVisitor(this);
			Formatter.Append(" ");
			WriteMethod(methodDeclaration.NameToken.Name, methodDeclaration.Parameters, methodDeclaration.Body);
		}
		protected virtual void WriteModifiers(IEnumerable<CSharpModifierToken> modifierTokens)
		{
			foreach (CSharpModifierToken modifier in modifierTokens)
			{
				if (modifier.Modifier == Modifiers.Static)
				{
					Formatter.Append("static ");
				}
			}
		}

		public void VisitNamedArgumentExpression(NamedArgumentExpression namedArgumentExpression)
		{
			namedArgumentExpression.Expression.AcceptVisitor(this);
		}

		public void VisitNamedExpression(NamedExpression namedExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitNamespaceDeclaration(NamespaceDeclaration namespaceDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitNewLine(NewLineNode newLineNode)
		{
			throw new NotImplementedException();
		}

		public void VisitNullNode(AstNode nullNode)
		{
		}

		public void VisitNullReferenceExpression(NullReferenceExpression nullReferenceExpression)
		{
			Formatter.Append("null");
		}

		public void VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression)
		{
			Formatter.Append("new ");
			objectCreateExpression.Type.AcceptVisitor(this);
			Formatter.Append("Raw");
			bool useParenthesis = objectCreateExpression.Arguments.Any() || objectCreateExpression.Initializer.IsNull;
			// also use parenthesis if there is an '(' token
			if (!objectCreateExpression.LParToken.IsNull)
			{
				useParenthesis = true;
			}
			if (useParenthesis)
			{
				WriteCommaSeparatedListInParenthesis(objectCreateExpression.Arguments);
			}
			objectCreateExpression.Initializer.AcceptVisitor(this);
		}

		public void VisitOperatorDeclaration(OperatorDeclaration operatorDeclaration)
		{
			//			throw new NotImplementedException();
		}

		public void VisitOutVarDeclarationExpression(OutVarDeclarationExpression outVarDeclarationExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitParameterDeclaration(ParameterDeclaration parameterDeclaration)
		{
			parameterDeclaration.Type.AcceptVisitor(this);
			Formatter.Append(" ");
			Formatter.AppendName(parameterDeclaration.NameToken.Name);
		}

		public void VisitParenthesizedExpression(ParenthesizedExpression parenthesizedExpression)
		{
			Formatter.Append("( ");
			parenthesizedExpression.Expression.AcceptVisitor(this);
			Formatter.Append(" )");
		}

		public void VisitPatternPlaceholder(AstNode placeholder, Pattern pattern)
		{
			throw new NotImplementedException();
		}

		protected virtual void WriteTypeArguments(IEnumerable<AstType> typeArguments)
		{
			if (typeArguments.Any())
			{
				Formatter.Append("<");
				WriteCommaSeparatedList(typeArguments);
				Formatter.Append(">");
			}
		}
		public void VisitPointerReferenceExpression(PointerReferenceExpression pointerReferenceExpression)
		{
			pointerReferenceExpression.Target.AcceptVisitor(this);
			Formatter.Append("->");
			Formatter.Append(pointerReferenceExpression.MemberNameToken.Name);
			WriteTypeArguments(pointerReferenceExpression.TypeArguments);
		}

		public void VisitPreProcessorDirective(PreProcessorDirective preProcessorDirective)
		{
			throw new NotImplementedException();
		}

		public void VisitPrimitiveExpression(PrimitiveExpression primitiveExpression)
		{
			if (primitiveExpression.Value is Boolean)
			{
				if ((Boolean)(primitiveExpression.Value))
				{
					Formatter.Append("true");
				}
				else
				{
					Formatter.Append("false");
				}
				return;
			}
			if (primitiveExpression.Value is Char)
			{
				Formatter.Append("'");
				Formatter.Append(primitiveExpression.Value.ToString());
				Formatter.Append("'");
				return;
			}
			bool isString = primitiveExpression.Value is String;
			if (isString)
			{
				Formatter.Append("\"");
			}
			Formatter.Append(primitiveExpression.Value.ToString());
			if (isString)
			{
				Formatter.Append("\"");
			}
		}

		public void VisitPrimitiveType(PrimitiveType primitiveType)
		{
			Formatter.AppendType(primitiveType.Keyword);
		}

		protected virtual void WritePrivateImplementationType(AstType privateImplementationType)
		{
			if (!privateImplementationType.IsNull)
			{
				privateImplementationType.AcceptVisitor(this);
				Formatter.Append(".");
			}
		}
		public void VisitPropertyDeclaration(PropertyDeclaration propertyDeclaration)
		{
			return; // ToDo handle properties
			propertyDeclaration.ReturnType.AcceptVisitor(this);
			Formatter.Append(" ");
			WritePrivateImplementationType(propertyDeclaration.PrivateImplementationType);
			Formatter.Append(propertyDeclaration.NameToken.Name);
			if (propertyDeclaration.ExpressionBody.IsNull)
			{
				Formatter.Append("{");
				// output get/set in their original order
				foreach (AstNode node in propertyDeclaration.Children)
				{
					if (node.Role == IndexerDeclaration.GetterRole || node.Role == IndexerDeclaration.SetterRole)
					{
						node.AcceptVisitor(this);
					}
				}
				Formatter.Append("}");
				if (!propertyDeclaration.Initializer.IsNull)
				{
					Formatter.Append(" = ");
					propertyDeclaration.Initializer.AcceptVisitor(this);
					Formatter.Append(";");
				}
				Formatter.AppendLine("");
			}
			else
			{
				Formatter.Append(" > ");
				propertyDeclaration.ExpressionBody.AcceptVisitor(this);
				Formatter.Append(";");
			}
		}

		public void VisitQueryContinuationClause(QueryContinuationClause queryContinuationClause)
		{
			throw new NotImplementedException();
		}

		public void VisitQueryExpression(QueryExpression queryExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitQueryFromClause(QueryFromClause queryFromClause)
		{
			throw new NotImplementedException();
		}

		public void VisitQueryGroupClause(QueryGroupClause queryGroupClause)
		{
			throw new NotImplementedException();
		}

		public void VisitQueryJoinClause(QueryJoinClause queryJoinClause)
		{
			throw new NotImplementedException();
		}

		public void VisitQueryLetClause(QueryLetClause queryLetClause)
		{
			throw new NotImplementedException();
		}

		public void VisitQueryOrderClause(QueryOrderClause queryOrderClause)
		{
			throw new NotImplementedException();
		}

		public void VisitQueryOrdering(QueryOrdering queryOrdering)
		{
			throw new NotImplementedException();
		}

		public void VisitQuerySelectClause(QuerySelectClause querySelectClause)
		{
			throw new NotImplementedException();
		}

		public void VisitQueryWhereClause(QueryWhereClause queryWhereClause)
		{
			throw new NotImplementedException();
		}

		public void VisitReturnStatement(ReturnStatement returnStatement)
		{
			Formatter.Append("return");
			if (!returnStatement.Expression.IsNull)
			{
				Formatter.Append(" ");
				returnStatement.Expression.AcceptVisitor(this);
			}
			Formatter.Append(";");
		}

		public void VisitSimpleType(SimpleType simpleType)
		{
			simpleType.IdentifierToken.AcceptVisitor(this);
			IType type = simpleType.GetResolveResult().Type;
			if (type.Kind == TypeKind.Class)
				Formatter.Append("Raw");
		}

		public void VisitSizeOfExpression(SizeOfExpression sizeOfExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitStackAllocExpression(StackAllocExpression stackAllocExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitSwitchSection(SwitchSection switchSection)
		{
			bool first = true;
			foreach (var label in switchSection.CaseLabels)
			{
				if (!first)
				{
					Formatter.AppendLine("");
				}
				label.AcceptVisitor(this);
				first = false;
			}
			bool isBlock = switchSection.Statements.Count == 1 && switchSection.Statements.Single() is BlockStatement;

			if (!isBlock)
				Formatter.AppendLine("");

			foreach (var statement in switchSection.Statements)
			{
				statement.AcceptVisitor(this);
			}
		}

		public void VisitSwitchStatement(SwitchStatement switchStatement)
		{
			Formatter.Append("switch ( ");
			switchStatement.Expression.AcceptVisitor(this);
			Formatter.AppendLine(" )");
			Formatter.AppendLine("{");
			foreach (var section in switchStatement.SwitchSections)
			{
				section.AcceptVisitor(this);
			}
			Formatter.AppendLine("}");
		}

		public void VisitSyntaxTree(SyntaxTree syntaxTree)
		{
			foreach (AstNode node in syntaxTree.Children)
			{
				node.AcceptVisitor(this);
			}
		}

		public void VisitText(TextNode textNode)
		{
			throw new NotImplementedException();
		}

		public void VisitThisReferenceExpression(ThisReferenceExpression thisReferenceExpression)
		{
			Formatter.Append("this");
		}

		public void VisitThrowExpression(ThrowExpression throwExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitThrowStatement(ThrowStatement throwStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitTryCatchStatement(TryCatchStatement tryCatchStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitTupleExpression(TupleExpression tupleExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitTupleType(TupleAstType tupleType)
		{
			throw new NotImplementedException();
		}

		public void VisitTupleTypeElement(TupleTypeElement tupleTypeElement)
		{
			throw new NotImplementedException();
		}

		public virtual void VisitTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			if (typeDeclaration.ClassType != ClassType.Enum)
			{
				HeaderTypeDeclaration(typeDeclaration);
			}
		}

		protected virtual void HeaderTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			//bool isClass = false;
			//var sym = typeDeclaration.GetSymbol();
			//switch (typeDeclaration.ClassType)
			//{
			//	case ClassType.Interface:
			//		Formatter.AppendIndented("class ");
			//		isClass = true;
			//		break;
			//	case ClassType.Struct:
			//		Formatter.AppendIndented("struct ");
			//		isClass = true;
			//		break;
			//	default:
			//		Formatter.AppendIndented("class ");
			//		isClass = true;
			//		break;
			//}
			//Formatter.AppendName(typeDeclaration.Name);
			//if (isClass)
			//{
			//	Formatter.Append("Raw");
			//}
			//Formatter.AddOpenBrace();
			//if (typeDeclaration.ClassType != ClassType.Struct)
			//{
			//	Formatter.AppendIndentedLine("public:");
			//}
			CurrentClass = typeDeclaration.Name;
			foreach (var member in typeDeclaration.Members)
			{
				member.AcceptVisitor(this);
			}
			//Formatter.AddCloseBrace(true);
		}

		public void VisitTypeOfExpression(TypeOfExpression typeOfExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitTypeParameterDeclaration(TypeParameterDeclaration typeParameterDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitTypeReferenceExpression(TypeReferenceExpression typeReferenceExpression)
		{
			typeReferenceExpression.Type.AcceptVisitor(this);
		}

		static bool IsPostfixOperator(UnaryOperatorType op)
		{
			return op == UnaryOperatorType.PostIncrement
				|| op == UnaryOperatorType.PostDecrement
				|| op == UnaryOperatorType.NullConditional;
			//|| op == UnaryOperatorType.SuppressNullableWarning;
		}
		public void VisitUnaryOperatorExpression(UnaryOperatorExpression unaryOperatorExpression)
		{
			UnaryOperatorType opType = unaryOperatorExpression.Operator;
			var opSymbol = UnaryOperatorExpression.GetOperatorRole(opType);
			if (opType == UnaryOperatorType.Await)
			{
				Formatter.Append(opSymbol.ToString());
			}
			else if (!IsPostfixOperator(opType) && opSymbol != null)
			{
				Formatter.Append(opSymbol.ToString());
			}
			unaryOperatorExpression.Expression.AcceptVisitor(this);
			if (IsPostfixOperator(opType))
			{
				Formatter.Append(opSymbol.ToString());
			}
		}

		public void VisitUncheckedExpression(UncheckedExpression uncheckedExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitUncheckedStatement(UncheckedStatement uncheckedStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitUndocumentedExpression(UndocumentedExpression undocumentedExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitUnsafeStatement(UnsafeStatement unsafeStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitUsingAliasDeclaration(UsingAliasDeclaration usingAliasDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitUsingDeclaration(UsingDeclaration usingDeclaration)
		{
		}

		public void VisitUsingStatement(UsingStatement usingStatement)
		{
			//			Formatter.AppendLine("UsingStatement");
		}

		public void VisitVariableDeclarationStatement(VariableDeclarationStatement variableDeclarationStatement)
		{
			variableDeclarationStatement.Type.AcceptVisitor(this);
			Formatter.Append(" ");
			WriteCommaSeparatedList(variableDeclarationStatement.Variables);
			Formatter.Append(";");
		}

		public void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			Formatter.AppendName(variableInitializer.Name);
			if (!variableInitializer.Initializer.IsNull)
			{
				Formatter.Append(" = ");
				variableInitializer.Initializer.AcceptVisitor(this);
			}
		}

		public void VisitWhileStatement(WhileStatement whileStatement)
		{
			Formatter.Append("while (");
			whileStatement.Condition.AcceptVisitor(this);
			Formatter.Append(" )");
			WriteEmbeddedStatement(whileStatement.EmbeddedStatement);
		}

		public void VisitWhitespace(WhitespaceNode whitespaceNode)
		{
			throw new NotImplementedException();
		}

		public void VisitYieldBreakStatement(YieldBreakStatement yieldBreakStatement)
		{
			Formatter.Append("break");
		}

		public void VisitYieldReturnStatement(YieldReturnStatement yieldReturnStatement)
		{
			throw new NotImplementedException();
		}
	}
}
