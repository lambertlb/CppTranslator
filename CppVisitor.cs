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
	class CppVisitor : Formatter, IAstVisitor
	{
		private CppTypeVisitor typeVisitor;
		Boolean doingPrototyping;
		public bool DoingPrototyping { get => doingPrototyping; set => doingPrototyping = value; }
		public bool DoingDelcaration { get; set; }
		public CppVisitor()
		{
			typeVisitor = new CppTypeVisitor(this);
		}
		public void VisitAccessor(Accessor accessor)
		{
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
			Append("new ");
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
			Append("[");
			WriteCommaSeparatedList(arguments);
			Append("]");
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
			Append("[");
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
					Append(",");
				}
				last = node;
				node.AcceptVisitor(this);
			}
			Append("]");
		}
		protected bool CanBeConfusedWithObjectInitializer(Expression expr)
		{
			// "int a; new List<int> { a = 1 };" is an object initalizers and invalid, but
			// "int a; new List<int> { { a = 1 } };" is a valid collection initializer.
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
			Append("[");
			foreach (var comma in arraySpecifier.GetChildrenByRole(Roles.Comma))
			{
				Append(",");
			}
			Append("]");
		}

		public void VisitAsExpression(AsExpression asExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitAssignmentExpression(AssignmentExpression assignmentExpression)
		{
			assignmentExpression.Left.AcceptVisitor(this);
			Append(" ");
			Append(AssignmentExpression.GetOperatorRole(assignmentExpression.Operator).ToString());
			Append(" ");
			assignmentExpression.Right.AcceptVisitor(this);
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
			Append(" ");
			Append(BinaryOperatorExpression.GetOperatorRole(binaryOperatorExpression.Operator).ToString());
			Append(" ");
			binaryOperatorExpression.Right.AcceptVisitor(this);
		}

		public void VisitBlockStatement(BlockStatement blockStatement)
		{
			throw new NotImplementedException();
		}

		public void VisitBreakStatement(BreakStatement breakStatement)
		{
			Append("break;");
		}

		public void VisitCaseLabel(CaseLabel caseLabel)
		{
			if (caseLabel.Expression.IsNull)
			{
				Append("default");
			}
			else
			{
				Append("case ");
				caseLabel.Expression.AcceptVisitor(this);
			}
			Append(":");
		}

		public void VisitCastExpression(CastExpression castExpression)
		{
			Append("( ");
			castExpression.Type.AcceptVisitor(this);
			Append(" ) ");
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
				composedType.GetResolveResult().Type.AcceptVisitor(typeVisitor);
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
			Append(" ? ");
			conditionalExpression.TrueExpression.AcceptVisitor(this);
			Append(" : ");
			conditionalExpression.FalseExpression.AcceptVisitor(this);
		}

		public void VisitConstraint(Constraint constraint)
		{
			throw new NotImplementedException();
		}

		protected virtual void WriteMethodHeader(String medodName, AstNodeCollection<ParameterDeclaration> parameters)
		{
			AppendName(medodName);
			WriteCommaSeparatedListInParenthesis(parameters);
		}
		protected virtual void WriteMethod(String medodName, AstNodeCollection<ParameterDeclaration> parameters, BlockStatement body)
		{
			WriteMethodHeader(medodName, parameters);
			WriteBlock(body);
		}

		private void WriteBlock(BlockStatement body)
		{
			AppendLine("{");
			foreach (var node in body.Statements)
			{
				node.AcceptVisitor(this);
				AppendLine("");
			}
			AppendLine("}");
		}

		public void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
			TypeDeclaration type = constructorDeclaration.Parent as TypeDeclaration;
			String name = null;
			if (type != null && type.Name != constructorDeclaration.Name)
				name = type.NameToken.Name;
			else
				name = constructorDeclaration.NameToken.Name;
			AppendIndented("");
			if (DoHeaderFile)
			{
				WriteMethodHeader(name + "Raw", constructorDeclaration.Parameters);
				AppendLine(";");
				return;
			}
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
			Append("default ");
			Append("(");
			Append(" ");
			defaultValueExpression.Type.AcceptVisitor(this);
			Append(" ");
			Append(")");
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
					Append("out");
					break;
				case FieldDirection.Ref:
					Append("ref");
					break;
				case FieldDirection.In:
					Append("in");
					break;
				default:
					throw new NotSupportedException("Invalid value for FieldDirection");
			}
			Append(" ");
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
			AppendIndentedName(enumMemberDeclaration.NameToken.Name);
			Append("_");
			Append(EnumName);
			if (!enumMemberDeclaration.Initializer.IsNull)
			{
				Append(" = ");
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
			Append(";");
		}

		public void VisitExternAliasDeclaration(ExternAliasDeclaration externAliasDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
			if (!DoHeaderFile)
			{
				return;
			}
			VariableInitializer variable = fieldDeclaration.Variables.First<VariableInitializer>();
			AppendIndented("");
			fieldDeclaration.ReturnType.GetResolveResult().Type.AcceptVisitor(typeVisitor);
			Append(" ");
			AppendName(variable.Name);
			AppendLine(";");
		}

		private void AssignVariableName(IType type, String name)
		{
			if (type != null && IsPointerType(type))
			{
				Append(".Assign(");
				Append(name);
				Append(")");
			}
			else
			{
				Append(" ");
				Append(name);
			}
		}

		public void FormatTypeDelaration(IType type, String typeName)
		{
			if (type != null && IsPointerType(type))
			{
				Append("Pointer<");
				Append(typeName);
				Append(">");
				return;
			}
			Append(typeName);
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
			Append("foreach ");
			Append("(");
			foreachStatement.VariableType.AcceptVisitor(this);
			Append(" ");
			WriteVariableName(foreachStatement.VariableNameToken);
			Append(" in ");
			foreachStatement.InExpression.AcceptVisitor(this);
			Append(" ");
			Append(")");
			WriteEmbeddedStatement(foreachStatement.EmbeddedStatement);
		}

		private void WriteVariableName(Identifier nameIdentifier)
		{
			Append(nameIdentifier.Name);
		}

		protected virtual void WriteEmbeddedStatement(Statement embeddedStatement)
		{
			AppendLine("");
			BlockStatement block = embeddedStatement as BlockStatement;
			if (block != null)
			{
				WriteBlock(block);
				AppendLine("");
			}
			else
			{
				AppendLine("");
				embeddedStatement.AcceptVisitor(this);
			}
		}
		public void VisitForStatement(ForStatement forStatement)
		{
			Append("for ( ");
			WriteCommaSeparatedList(forStatement.Initializers);
			Append(" ;  ");
			forStatement.Condition.AcceptVisitor(this);
			Append(" ;  ");
			if (forStatement.Iterators.Any())
			{
				Append(" ");
				WriteCommaSeparatedList(forStatement.Iterators);
			}

			Append(" )");
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
			Append(identifier.Name);
		}

		public void VisitIdentifierExpression(IdentifierExpression identifierExpression)
		{
			Append(identifierExpression.IdentifierToken.Name);
		}

		public void VisitIfElseStatement(IfElseStatement ifElseStatement)
		{
			Append("if ( ");
			ifElseStatement.Condition.AcceptVisitor(this);
			Append(" )");
			if (ifElseStatement.FalseStatement.IsNull)
			{
				WriteEmbeddedStatement(ifElseStatement.TrueStatement);
			}
			else
			{
				WriteEmbeddedStatement(ifElseStatement.TrueStatement);
				Append("else");
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
			Append(" ");
			NewMethod(indexerExpression.Arguments);
		}

		private void NewMethod(IEnumerable<AstNode> nodes)
		{
			Append("[ ");
			WriteCommaSeparatedList(nodes);
			Append(" ]");
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
			Append(" ");
			WriteCommaSeparatedListInParenthesis(invocationExpression.Arguments);
		}

		private void WriteCommaSeparatedListInParenthesis(IEnumerable<AstNode> nodes)
		{
			Append("(");
			WriteCommaSeparatedList(nodes);
			Append(")");
		}

		private void WriteCommaSeparatedList(IEnumerable<AstNode> nodes)
		{
			bool isFirst = true;
			foreach (AstNode node in nodes)
			{
				if (!isFirst)
				{
					Append(",");
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
			var sym = memberReferenceExpression.GetSymbol() as IEntity;
			memberReferenceExpression.Target.AcceptVisitor(this);
			if (sym.IsStatic)
			{
				Append("::");
			}
			else
			{
				Append(".");
			}
			Append(memberReferenceExpression.MemberNameToken.Name);
			Append("()");
		}

		public void VisitMemberType(MemberType memberType)
		{
			memberType.Target.AcceptVisitor(this);
		}

		public void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
			AppendIndented("");
			methodDeclaration.ReturnType.AcceptVisitor(this);
			Append(" ");
			if (DoHeaderFile)
			{
				WriteMethodHeader(methodDeclaration.NameToken.Name, methodDeclaration.Parameters);
				AppendLine(";");
				return;
			}
			WriteMethod(methodDeclaration.NameToken.Name, methodDeclaration.Parameters, methodDeclaration.Body);
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
			Append("null");
		}

		public void VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression)
		{
			Append("new ");
			objectCreateExpression.Type.AcceptVisitor(this);
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
			Append(" ");
			AppendName(parameterDeclaration.NameToken.Name);
		}

		public void VisitParenthesizedExpression(ParenthesizedExpression parenthesizedExpression)
		{
			Append("( ");
			parenthesizedExpression.Expression.AcceptVisitor(this);
			Append(" )");
		}

		public void VisitPatternPlaceholder(AstNode placeholder, Pattern pattern)
		{
			throw new NotImplementedException();
		}

		protected virtual void WriteTypeArguments(IEnumerable<AstType> typeArguments)
		{
			if (typeArguments.Any())
			{
				Append("<");
				WriteCommaSeparatedList(typeArguments);
				Append(">");
			}
		}
		public void VisitPointerReferenceExpression(PointerReferenceExpression pointerReferenceExpression)
		{
			pointerReferenceExpression.Target.AcceptVisitor(this);
			Append("->");
			Append(pointerReferenceExpression.MemberNameToken.Name);
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
					Append("true");
				}
				else
				{
					Append("false");
				}
				return;
			}
			if (primitiveExpression.Value is Char)
			{
				Append("'");
				Append(primitiveExpression.Value.ToString());
				Append("'");
				return;
			}
			bool isString = primitiveExpression.Value is String;
			if (isString)
			{
				Append("\"");
			}
			Append(primitiveExpression.Value.ToString());
			if (isString)
			{
				Append("\"");
			}
		}

		public void VisitPrimitiveType(PrimitiveType primitiveType)
		{
			AppendType(primitiveType.Keyword);
		}

		protected virtual void WritePrivateImplementationType(AstType privateImplementationType)
		{
			if (!privateImplementationType.IsNull)
			{
				privateImplementationType.AcceptVisitor(this);
				Append(".");
			}
		}
		public void VisitPropertyDeclaration(PropertyDeclaration propertyDeclaration)
		{
			return;
			propertyDeclaration.ReturnType.AcceptVisitor(this);
			Append(" ");
			WritePrivateImplementationType(propertyDeclaration.PrivateImplementationType);
			Append(propertyDeclaration.NameToken.Name);
			if (propertyDeclaration.ExpressionBody.IsNull)
			{
				Append("{");
				// output get/set in their original order
				foreach (AstNode node in propertyDeclaration.Children)
				{
					if (node.Role == IndexerDeclaration.GetterRole || node.Role == IndexerDeclaration.SetterRole)
					{
						node.AcceptVisitor(this);
					}
				}
				Append("}");
				if (!propertyDeclaration.Initializer.IsNull)
				{
					Append(" = ");
					propertyDeclaration.Initializer.AcceptVisitor(this);
					Append(";");
				}
				AppendLine("");
			}
			else
			{
				Append(" > ");
				propertyDeclaration.ExpressionBody.AcceptVisitor(this);
				Append(";");
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
			Append("return");
			if (!returnStatement.Expression.IsNull)
			{
				Append(" ");
				returnStatement.Expression.AcceptVisitor(this);
			}
			Append(";");
		}

		public void VisitSimpleType(SimpleType simpleType)
		{
			var sym = simpleType.GetSymbol();
			simpleType.IdentifierToken.AcceptVisitor(this);
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
					AppendLine("");
				}
				label.AcceptVisitor(this);
				first = false;
			}
			bool isBlock = switchSection.Statements.Count == 1 && switchSection.Statements.Single() is BlockStatement;

			if (!isBlock)
				AppendLine("");

			foreach (var statement in switchSection.Statements)
			{
				statement.AcceptVisitor(this);
			}
		}

		public void VisitSwitchStatement(SwitchStatement switchStatement)
		{
			Append("switch ( ");
			switchStatement.Expression.AcceptVisitor(this);
			AppendLine(" )");
			AppendLine("{");
			foreach (var section in switchStatement.SwitchSections)
			{
				section.AcceptVisitor(this);
			}
			AppendLine("}");
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
			Append("this");
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

		public void VisitTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			if (DoProtyping)
			{
				PrototypeTypeDeclaration(typeDeclaration);
				return;
			}
			if (typeDeclaration.ClassType != ClassType.Enum)
			{
				HeaderTypeDeclaration(typeDeclaration);
				return;
			}
		}

		private void HeaderTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			bool isClass = false;
			var sym = typeDeclaration.GetSymbol();
			switch (typeDeclaration.ClassType)
			{
				case ClassType.Interface:
					AppendIndented("class ");
					isClass = true;
					break;
				case ClassType.Struct:
					AppendIndented("struct ");
					isClass = true;
					break;
				default:
					AppendIndented("class ");
					isClass = true;
					break;
			}
			AppendName(typeDeclaration.Name);
			if (isClass)
			{
				Append("Raw");
			}
			AddOpenBrace();
			if (typeDeclaration.ClassType != ClassType.Struct)
			{
				AppendIndentedLine("public:");
			}
			foreach (var member in typeDeclaration.Members)
			{
				member.AcceptVisitor(this);
			}
			AddCloseBrace(true);
		}

		private void PrototypeTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			bool isClass = false;
			switch (typeDeclaration.ClassType)
			{
				case ClassType.Enum:
					AppendIndented("enum ");
					break;
				case ClassType.Interface:
					AppendIndented("class ");
					isClass = true;
					break;
				case ClassType.Struct:
					AppendIndented("struct ");
					isClass = true;
					break;
				default:
					AppendIndented("class ");
					isClass = true;
					break;
			}
			AppendName(typeDeclaration.Name);
			if (isClass)
			{
				Append("Raw");
			}
			if (typeDeclaration.ClassType == ClassType.Enum)
			{
				OutputEnumValues(typeDeclaration);
			}
			else
			{
				Append(";");
			}
			if (isClass)
			{
				AppendLine("");
				AppendIndented("typedef PointerType<");
				AppendName(typeDeclaration.Name);
				Append("Raw>\t");
				AppendName(typeDeclaration.Name);
				Append(";");
			}
		}

		private void OutputEnumValues(TypeDeclaration typeDeclaration)
		{
			EnumName = typeDeclaration.Name;
			AddOpenBrace();
			bool first = true;
			foreach (var member in typeDeclaration.Members)
			{
				if (!first)
				{
					AppendLine(",");
				}
				member.AcceptVisitor(this);
				first = false;
			}
			AddCloseBrace(true);
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
				Append(opSymbol.ToString());
			}
			else if (!IsPostfixOperator(opType) && opSymbol != null)
			{
				Append(opSymbol.ToString());
			}
			unaryOperatorExpression.Expression.AcceptVisitor(this);
			if (IsPostfixOperator(opType))
			{
				Append(opSymbol.ToString());
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
			//			AppendLine("UsingStatement");
		}

		public void VisitVariableDeclarationStatement(VariableDeclarationStatement variableDeclarationStatement)
		{
			variableDeclarationStatement.Type.AcceptVisitor(this);
			Append(" ");
			WriteCommaSeparatedList(variableDeclarationStatement.Variables);
			Append(";");
		}

		public void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			AppendName(variableInitializer.Name);
			if (!variableInitializer.Initializer.IsNull)
			{
				Append(" = ");
				variableInitializer.Initializer.AcceptVisitor(this);
			}
		}

		public void VisitWhileStatement(WhileStatement whileStatement)
		{
			Append("while (");
			whileStatement.Condition.AcceptVisitor(this);
			Append(" )");
			WriteEmbeddedStatement(whileStatement.EmbeddedStatement);
		}

		public void VisitWhitespace(WhitespaceNode whitespaceNode)
		{
			throw new NotImplementedException();
		}

		public void VisitYieldBreakStatement(YieldBreakStatement yieldBreakStatement)
		{
			Append("break");
		}

		public void VisitYieldReturnStatement(YieldReturnStatement yieldReturnStatement)
		{
			throw new NotImplementedException();
		}
	}
}
