using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.CSharp.Syntax.PatternMatching;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;
using System.Linq;

namespace CppTranslator
{
	class ArrayInitializerVisitor : IAstVisitor
	{
		private CppTypeVisitor typeVisitor;
		public CppTypeVisitor TypeVisitor { get => typeVisitor; }
		private CppVisitorBase baseVisitor;
		private Formatter formatter;
		public Formatter Formatter { get => formatter; }
		public int StaticArrayCount { get; set; }
		public String CurrentMethod { get; set; }
		public bool DoingArrayInitialize { get; set; }

		public ArrayInitializerVisitor(CppVisitorBase baseVisitor, String currentMethod)
		{
			this.baseVisitor = baseVisitor;
			this.formatter = baseVisitor.Formatter;
			CurrentMethod = currentMethod;
			typeVisitor = new CppTypeVisitor(baseVisitor);
		}
		public void VisitAccessor(Accessor accessor)
		{
		}
		public virtual void AddHeaders()
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
			if (arrayCreateExpression.Initializer.IsNull)
			{
				return;
			}
			DoingArrayInitialize = true;
			Formatter.AppendIndented("static ");
			arrayCreateExpression.Type.AcceptVisitor(this);
			Formatter.Append(" ");
			Formatter.Append(CurrentMethod);
			Formatter.Append("Array");
			Formatter.Append(StaticArrayCount.ToString());
			++StaticArrayCount;
			if (arrayCreateExpression.Arguments.Count > 0)
			{
				WriteCommaSeparatedListInBrackets(arrayCreateExpression.Arguments);
			}
			Formatter.Append(" = ");
			arrayCreateExpression.Initializer.AcceptVisitor(this);
			Formatter.AppendLine(";");
		}
		protected void WriteCommaSeparatedListInBrackets(IEnumerable<Expression> list)
		{
			foreach (AstNode node in list)
			{
				Formatter.Append("[");
				node.AcceptVisitor(this);
				Formatter.Append("]");
			}
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
			Formatter.Append("{");
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
			Formatter.Append("}");
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
			if (assignmentExpression.Right is ArrayCreateExpression)
			{
				assignmentExpression.Right.AcceptVisitor(this);
			}
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
		}

		public void VisitBlockStatement(BlockStatement blockStatement)
		{
			foreach (var node in blockStatement.Statements)
			{
				DoingArrayInitialize = false;
				node.AcceptVisitor(this);
			}
		}

		public void VisitBreakStatement(BreakStatement breakStatement)
		{
		}

		public void VisitCaseLabel(CaseLabel caseLabel)
		{
		}

		public void VisitCastExpression(CastExpression castExpression)
		{
		}

		public void VisitCatchClause(CatchClause catchClause)
		{
		}

		public void VisitCheckedExpression(CheckedExpression checkedExpression)
		{
		}

		public void VisitCheckedStatement(CheckedStatement checkedStatement)
		{
		}

		public void VisitComment(Comment comment)
		{
		}

		public void VisitComposedType(ComposedType composedType)
		{
		}

		public void VisitConditionalExpression(ConditionalExpression conditionalExpression)
		{
		}

		public void VisitConstraint(Constraint constraint)
		{
		}

		protected virtual void WriteMethodHeader(String medodName, AstNodeCollection<ParameterDeclaration> parameters)
		{
		}
		protected virtual void WriteMethod(String medodName, AstNodeCollection<ParameterDeclaration> parameters, BlockStatement body)
		{
			WriteMethodHeader(medodName, parameters);
			WriteBlock(body);
		}

		private void WriteBlock(BlockStatement body)
		{
			foreach (var node in body.Statements)
			{
				node.AcceptVisitor(this);
			}
		}

		public void VisitConstructorInitializer(ConstructorInitializer constructorInitializer)
		{
		}

		public void VisitContinueStatement(ContinueStatement continueStatement)
		{
		}

		public void VisitCSharpTokenNode(CSharpTokenNode cSharpTokenNode)
		{
		}

		public void VisitCustomEventDeclaration(CustomEventDeclaration customEventDeclaration)
		{
		}

		public void VisitDefaultValueExpression(DefaultValueExpression defaultValueExpression)
		{
			defaultValueExpression.Type.AcceptVisitor(this);
		}

		public void VisitDelegateDeclaration(DelegateDeclaration delegateDeclaration)
		{
		}

		public void VisitDestructorDeclaration(DestructorDeclaration destructorDeclaration)
		{
		}

		public void VisitDirectionExpression(DirectionExpression directionExpression)
		{
			directionExpression.Expression.AcceptVisitor(this);
		}

		public void VisitDocumentationReference(DocumentationReference documentationReference)
		{
		}

		public void VisitDoWhileStatement(DoWhileStatement doWhileStatement)
		{
		}

		public void VisitEmptyStatement(EmptyStatement emptyStatement)
		{
		}

		public void VisitEnumMemberDeclaration(EnumMemberDeclaration enumMemberDeclaration)
		{
		}

		public void VisitErrorNode(AstNode errorNode)
		{
		}

		public void VisitEventDeclaration(EventDeclaration eventDeclaration)
		{
		}

		public void VisitExpressionStatement(ExpressionStatement expressionStatement)
		{
			expressionStatement.Expression.AcceptVisitor(this);
		}

		public void VisitExternAliasDeclaration(ExternAliasDeclaration externAliasDeclaration)
		{
		}

		public virtual void VisitFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
		}

		private void AssignVariableName(IType type, String name)
		{
		}

		public void VisitFixedFieldDeclaration(FixedFieldDeclaration fixedFieldDeclaration)
		{
		}

		public void VisitFixedStatement(FixedStatement fixedStatement)
		{
		}

		public void VisitFixedVariableInitializer(FixedVariableInitializer fixedVariableInitializer)
		{
		}

		public void VisitForeachStatement(ForeachStatement foreachStatement)
		{
		}

		private void WriteVariableName(Identifier nameIdentifier)
		{
		}

		protected virtual void WriteEmbeddedStatement(Statement embeddedStatement)
		{
		}
		public void VisitForStatement(ForStatement forStatement)
		{
		}

		public void VisitGotoCaseStatement(GotoCaseStatement gotoCaseStatement)
		{
		}

		public void VisitGotoDefaultStatement(GotoDefaultStatement gotoDefaultStatement)
		{
		}

		public void VisitGotoStatement(GotoStatement gotoStatement)
		{
		}

		public void VisitIdentifier(Identifier identifier)
		{
			if (DoingArrayInitialize)
				Formatter.Append(identifier.Name);
		}

		public void VisitIdentifierExpression(IdentifierExpression identifierExpression)
		{
			if (DoingArrayInitialize)
				Formatter.AppendName(identifierExpression.IdentifierToken.Name);
		}

		public void VisitIfElseStatement(IfElseStatement ifElseStatement)
		{
			ifElseStatement.Condition.AcceptVisitor(this);
			if (ifElseStatement.FalseStatement.IsNull)
			{
				WriteEmbeddedStatement(ifElseStatement.TrueStatement);
			}
			else
			{
				WriteEmbeddedStatement(ifElseStatement.TrueStatement);
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
		}

		public void VisitIndexerExpression(IndexerExpression indexerExpression)
		{
			indexerExpression.Target.AcceptVisitor(this);
			WriteCommaSeparatedList(indexerExpression.Arguments);
		}

		public void VisitInterpolatedStringExpression(InterpolatedStringExpression interpolatedStringExpression)
		{
		}

		public void VisitInterpolatedStringText(InterpolatedStringText interpolatedStringText)
		{
		}

		public void VisitInterpolation(Interpolation interpolation)
		{
		}

		public void VisitInvocationExpression(InvocationExpression invocationExpression)
		{
		}

		protected void WriteCommaSeparatedListInParenthesis(IEnumerable<AstNode> nodes)
		{
			Formatter.Append("(");
			WriteCommaSeparatedList(nodes);
			Formatter.Append(")");
		}

		protected void WriteCommaSeparatedList(IEnumerable<AstNode> nodes)
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
		}

		public void VisitLabelStatement(LabelStatement labelStatement)
		{
		}

		public void VisitLambdaExpression(LambdaExpression lambdaExpression)
		{
		}

		public void VisitLocalFunctionDeclarationStatement(LocalFunctionDeclarationStatement localFunctionDeclarationStatement)
		{
		}

		public void VisitLockStatement(LockStatement lockStatement)
		{
		}

		public void VisitMemberReferenceExpression(MemberReferenceExpression memberReferenceExpression)
		{
		}

		private bool HandleConstants(String instance, String field)
		{
			return (false);
		}

		private void HandleEnumExpression(IType type, IEntity sym)
		{
		}

		public void VisitMemberType(MemberType memberType)
		{
			memberType.Target.AcceptVisitor(this);
		}

		public virtual void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
		}
		protected virtual void WriteModifiers(IEnumerable<CSharpModifierToken> modifierTokens)
		{
		}

		public void VisitNamedArgumentExpression(NamedArgumentExpression namedArgumentExpression)
		{
		}

		public void VisitNamedExpression(NamedExpression namedExpression)
		{
		}

		public void VisitNamespaceDeclaration(NamespaceDeclaration namespaceDeclaration)
		{
		}

		public void VisitNewLine(NewLineNode newLineNode)
		{
		}

		public void VisitNullNode(AstNode nullNode)
		{
		}

		public void VisitNullReferenceExpression(NullReferenceExpression nullReferenceExpression)
		{
		}

		public void VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression)
		{
			if (!DoingArrayInitialize)
			{
				return;
			}
			IType type = objectCreateExpression.GetResolveResult().Type;
			if (type.Kind == TypeKind.Class)
				Formatter.Append("new ");
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
		}

		public void VisitOutVarDeclarationExpression(OutVarDeclarationExpression outVarDeclarationExpression)
		{
		}

		public void VisitParameterDeclaration(ParameterDeclaration parameterDeclaration)
		{
		}

		public void VisitParenthesizedExpression(ParenthesizedExpression parenthesizedExpression)
		{
			parenthesizedExpression.Expression.AcceptVisitor(this);
		}

		public void VisitPatternPlaceholder(AstNode placeholder, Pattern pattern)
		{
		}

		protected virtual void WriteTypeArguments(IEnumerable<AstType> typeArguments)
		{
			if (typeArguments.Any())
			{
				WriteCommaSeparatedList(typeArguments);
			}
		}
		public void VisitPointerReferenceExpression(PointerReferenceExpression pointerReferenceExpression)
		{
		}

		public void VisitPreProcessorDirective(PreProcessorDirective preProcessorDirective)
		{
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
				Formatter.Append("new StringRaw(");
				Formatter.AppendStringsWithControl(primitiveExpression.Value.ToString());
				Formatter.Append(")");
			}
			else
			{
				Formatter.Append(primitiveExpression.Value.ToString());
			}
		}

		public void VisitPrimitiveType(PrimitiveType primitiveType)
		{
			Formatter.AppendType(primitiveType.Keyword);
		}

		protected virtual void WritePrivateImplementationType(AstType privateImplementationType)
		{
		}
		public void VisitPropertyDeclaration(PropertyDeclaration propertyDeclaration)
		{
		}

		public void VisitQueryContinuationClause(QueryContinuationClause queryContinuationClause)
		{
		}

		public void VisitQueryExpression(QueryExpression queryExpression)
		{
		}

		public void VisitQueryFromClause(QueryFromClause queryFromClause)
		{
		}

		public void VisitQueryGroupClause(QueryGroupClause queryGroupClause)
		{
		}

		public void VisitQueryJoinClause(QueryJoinClause queryJoinClause)
		{
		}

		public void VisitQueryLetClause(QueryLetClause queryLetClause)
		{
		}

		public void VisitQueryOrderClause(QueryOrderClause queryOrderClause)
		{
		}

		public void VisitQueryOrdering(QueryOrdering queryOrdering)
		{
		}

		public void VisitQuerySelectClause(QuerySelectClause querySelectClause)
		{
		}

		public void VisitQueryWhereClause(QueryWhereClause queryWhereClause)
		{
		}

		public void VisitReturnStatement(ReturnStatement returnStatement)
		{
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
		}

		public void VisitStackAllocExpression(StackAllocExpression stackAllocExpression)
		{
		}

		public void VisitSwitchSection(SwitchSection switchSection)
		{
		}

		public void VisitSwitchStatement(SwitchStatement switchStatement)
		{
		}

		public void VisitSyntaxTree(SyntaxTree syntaxTree)
		{
		}

		public void VisitText(TextNode textNode)
		{
		}

		public void VisitThisReferenceExpression(ThisReferenceExpression thisReferenceExpression)
		{
		}

		public void VisitThrowExpression(ThrowExpression throwExpression)
		{
		}

		public void VisitThrowStatement(ThrowStatement throwStatement)
		{
		}

		public void VisitTryCatchStatement(TryCatchStatement tryCatchStatement)
		{
		}

		public void VisitTupleExpression(TupleExpression tupleExpression)
		{
		}

		public void VisitTupleType(TupleAstType tupleType)
		{
		}

		public void VisitTupleTypeElement(TupleTypeElement tupleTypeElement)
		{
		}

		public virtual void VisitTypeDeclaration(TypeDeclaration typeDeclaration)
		{
		}

		protected virtual void HeaderTypeDeclaration(TypeDeclaration typeDeclaration)
		{
		}

		public virtual void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
		}
		public virtual void CreateDefaultConstructor(TypeDeclaration typeDeclaration)
		{
		}

		private void InitializeFields()
		{
		}
		private void FormatFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
		}

		private void FormatStaticFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
		}
		public virtual void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			IType type = variableInitializer.GetResolveResult().Type;
			if (type.Kind == TypeKind.Array)
			{
				variableInitializer.Initializer.AcceptVisitor(this);
			}
		}

		public void VisitTypeOfExpression(TypeOfExpression typeOfExpression)
		{
		}

		public void VisitTypeParameterDeclaration(TypeParameterDeclaration typeParameterDeclaration)
		{
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
		}
		public void VisitUnaryOperatorExpression(UnaryOperatorExpression unaryOperatorExpression)
		{
		}

		public void VisitUncheckedExpression(UncheckedExpression uncheckedExpression)
		{
		}

		public void VisitUncheckedStatement(UncheckedStatement uncheckedStatement)
		{
		}

		public void VisitUndocumentedExpression(UndocumentedExpression undocumentedExpression)
		{
		}

		public void VisitUnsafeStatement(UnsafeStatement unsafeStatement)
		{
		}

		public void VisitUsingAliasDeclaration(UsingAliasDeclaration usingAliasDeclaration)
		{
		}

		public void VisitUsingDeclaration(UsingDeclaration usingDeclaration)
		{
		}

		public void VisitUsingStatement(UsingStatement usingStatement)
		{
		}

		public void VisitVariableDeclarationStatement(VariableDeclarationStatement variableDeclarationStatement)
		{
			SimpleType simpleType = variableDeclarationStatement.Type as SimpleType;
			WriteCommaSeparatedList(variableDeclarationStatement.Variables);
		}
		public void FormatTypeDelaration(IType type, String typeName)
		{
		}

		private bool IsPointerType(IType type)
		{
			return (type.Kind == TypeKind.Class || type.Kind == TypeKind.Array || type.IsByRefLike);
		}

		public void VisitWhileStatement(WhileStatement whileStatement)
		{
		}

		public void VisitWhitespace(WhitespaceNode whitespaceNode)
		{
		}

		public void VisitYieldBreakStatement(YieldBreakStatement yieldBreakStatement)
		{
		}

		public void VisitYieldReturnStatement(YieldReturnStatement yieldReturnStatement)
		{
		}
	}
}
