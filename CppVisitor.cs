using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.CSharp.Syntax.PatternMatching;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CppTranslator
{
	class CppVisitor : IAstVisitor
	{
		public void VisitAccessor(Accessor accessor)
		{
		}

		public void VisitAnonymousMethodExpression(AnonymousMethodExpression anonymousMethodExpression)
		{
			Console.WriteLine("AnonymousMethodExpression");
		}

		public void VisitAnonymousTypeCreateExpression(AnonymousTypeCreateExpression anonymousTypeCreateExpression)
		{
			Console.WriteLine("AnonymousTypeCreateExpression");
		}

		public void VisitArrayCreateExpression(ArrayCreateExpression arrayCreateExpression)
		{
			Console.Write("new ");
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
			Console.Write("[");
			WriteCommaSeparatedList(arguments);
			Console.Write("]");
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
			Console.Write("[");
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
					Console.Write(",");
				}
				last = node;
				node.AcceptVisitor(this);
			}
			Console.Write("]");
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
			Console.Write("[");
			foreach (var comma in arraySpecifier.GetChildrenByRole(Roles.Comma))
			{
				Console.Write(",");
			}
			Console.Write("]");
		}

		public void VisitAsExpression(AsExpression asExpression)
		{
			Console.WriteLine("AsExpression");
		}

		public void VisitAssignmentExpression(AssignmentExpression assignmentExpression)
		{
			assignmentExpression.Left.AcceptVisitor(this);
			Console.Write(" ");
			Console.Write(AssignmentExpression.GetOperatorRole(assignmentExpression.Operator));
			Console.Write(" ");
			assignmentExpression.Right.AcceptVisitor(this);
		}

		public void VisitAttribute(ICSharpCode.Decompiler.CSharp.Syntax.Attribute attribute)
		{
			Console.WriteLine("Attribute");
		}

		public void VisitAttributeSection(AttributeSection attributeSection)
		{
			Console.WriteLine("AttributeSection");
		}

		public void VisitBaseReferenceExpression(BaseReferenceExpression baseReferenceExpression)
		{
			Console.WriteLine("BaseReferenceExpression");
		}

		public void VisitBinaryOperatorExpression(BinaryOperatorExpression binaryOperatorExpression)
		{
			binaryOperatorExpression.Left.AcceptVisitor(this);
			Console.Write(" ");
			Console.Write(BinaryOperatorExpression.GetOperatorRole(binaryOperatorExpression.Operator));
			Console.Write(" ");
			binaryOperatorExpression.Right.AcceptVisitor(this);
		}

		public void VisitBlockStatement(BlockStatement blockStatement)
		{
			Console.WriteLine("BlockStatement");
		}

		public void VisitBreakStatement(BreakStatement breakStatement)
		{
			Console.WriteLine("BreakStatement");
		}

		public void VisitCaseLabel(CaseLabel caseLabel)
		{
			Console.WriteLine("CaseLabel");
		}

		public void VisitCastExpression(CastExpression castExpression)
		{
			Console.WriteLine("CastExpression");
		}

		public void VisitCatchClause(CatchClause catchClause)
		{
			Console.WriteLine("CatchClause");
		}

		public void VisitCheckedExpression(CheckedExpression checkedExpression)
		{
			Console.WriteLine("CheckedExpression");
		}

		public void VisitCheckedStatement(CheckedStatement checkedStatement)
		{
			Console.WriteLine("CheckedStatement");
		}

		public void VisitComment(Comment comment)
		{
			Console.WriteLine("comment");
		}

		public void VisitComposedType(ComposedType composedType)
		{
			composedType.BaseType.AcceptVisitor(this);
			foreach (var node in composedType.ArraySpecifiers)
			{
				node.AcceptVisitor(this);
			}
		}

		public void VisitConditionalExpression(ConditionalExpression conditionalExpression)
		{
			Console.WriteLine("ConditionalExpression");
		}

		public void VisitConstraint(Constraint constraint)
		{
			Console.WriteLine("Constraint");
		}

		protected virtual void WriteMethod(String medodName, AstNodeCollection<ParameterDeclaration> parameters, BlockStatement body)
		{
			Console.Write(medodName);
			WriteCommaSeparatedListInParenthesis(parameters);
			WriteBlock(body);
		}

		private void WriteBlock(BlockStatement body)
		{
			Console.WriteLine("{");
			foreach (var node in body.Statements)
			{
				node.AcceptVisitor(this);
			}
			Console.WriteLine("}");
		}

		public void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
			TypeDeclaration type = constructorDeclaration.Parent as TypeDeclaration;
			String name = null;
			if (type != null && type.Name != constructorDeclaration.Name)
				name = type.NameToken.Name;
			else
				name = constructorDeclaration.NameToken.Name;
			WriteMethod(name, constructorDeclaration.Parameters, constructorDeclaration.Body);
		}

		public void VisitConstructorInitializer(ConstructorInitializer constructorInitializer)
		{
			Console.WriteLine("ConstructorInitializer");
		}

		public void VisitContinueStatement(ContinueStatement continueStatement)
		{
			Console.WriteLine("ContinueStatement");
		}

		public void VisitCSharpTokenNode(CSharpTokenNode cSharpTokenNode)
		{
			Console.WriteLine("CSharpTokenNode");
		}

		public void VisitCustomEventDeclaration(CustomEventDeclaration customEventDeclaration)
		{
			Console.WriteLine("CustomEventDeclaration");
		}

		public void VisitDefaultValueExpression(DefaultValueExpression defaultValueExpression)
		{
			Console.WriteLine("DefaultValueExpression");
		}

		public void VisitDelegateDeclaration(DelegateDeclaration delegateDeclaration)
		{
			Console.WriteLine("DelegateDeclaration");
		}

		public void VisitDestructorDeclaration(DestructorDeclaration destructorDeclaration)
		{
			Console.WriteLine("DestructorDeclaration");
		}

		public void VisitDirectionExpression(DirectionExpression directionExpression)
		{
			Console.WriteLine("DirectionExpression");
		}

		public void VisitDocumentationReference(DocumentationReference documentationReference)
		{
			Console.WriteLine("DocumentationReference");
		}

		public void VisitDoWhileStatement(DoWhileStatement doWhileStatement)
		{
			Console.WriteLine("DoWhileStatement");
		}

		public void VisitEmptyStatement(EmptyStatement emptyStatement)
		{
			Console.WriteLine("EmptyStatement");
		}

		public void VisitEnumMemberDeclaration(EnumMemberDeclaration enumMemberDeclaration)
		{
			Console.WriteLine("EnumMemberDeclaration");
		}

		public void VisitErrorNode(AstNode errorNode)
		{
			Console.WriteLine("errorNode");
		}

		public void VisitEventDeclaration(EventDeclaration eventDeclaration)
		{
			Console.WriteLine("EventDeclaration");
		}

		public void VisitExpressionStatement(ExpressionStatement expressionStatement)
		{
			expressionStatement.Expression.AcceptVisitor(this);
			Console.WriteLine(";");
		}

		public void VisitExternAliasDeclaration(ExternAliasDeclaration externAliasDeclaration)
		{
			Console.WriteLine("ExternAliasDeclaration");
		}

		public void VisitFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
			Console.Write("Field: ");
			fieldDeclaration.ReturnType.AcceptVisitor(this);
			foreach (AstNode node in fieldDeclaration.Variables)
			{
				Console.Write(" ");
				node.AcceptVisitor(this);
			}
		}

		public void VisitFixedFieldDeclaration(FixedFieldDeclaration fixedFieldDeclaration)
		{
			Console.WriteLine("FixedFieldDeclaration");
		}

		public void VisitFixedStatement(FixedStatement fixedStatement)
		{
			Console.WriteLine("FixedStatement");
		}

		public void VisitFixedVariableInitializer(FixedVariableInitializer fixedVariableInitializer)
		{
			Console.WriteLine("FixedVariableInitializer");
		}

		public void VisitForeachStatement(ForeachStatement foreachStatement)
		{
			Console.WriteLine("ForeachStatement");
		}

		public void VisitForStatement(ForStatement forStatement)
		{
			Console.WriteLine("ForStatement");
		}

		public void VisitGotoCaseStatement(GotoCaseStatement gotoCaseStatement)
		{
			Console.WriteLine("GotoCaseStatement");
		}

		public void VisitGotoDefaultStatement(GotoDefaultStatement gotoDefaultStatement)
		{
			Console.WriteLine("GotoDefaultStatement");
		}

		public void VisitGotoStatement(GotoStatement gotoStatement)
		{
			Console.WriteLine("GotoStatement");
		}

		public void VisitIdentifier(Identifier identifier)
		{
			Console.WriteLine("Identifier");
		}

		public void VisitIdentifierExpression(IdentifierExpression identifierExpression)
		{
			Console.Write(identifierExpression.IdentifierToken.Name);
		}

		public void VisitIfElseStatement(IfElseStatement ifElseStatement)
		{
			Console.WriteLine("IfElseStatement");
		}

		public void VisitIndexerDeclaration(IndexerDeclaration indexerDeclaration)
		{
			Console.WriteLine("IndexerDeclaration");
		}

		public void VisitIndexerExpression(IndexerExpression indexerExpression)
		{
			indexerExpression.Target.AcceptVisitor(this);
			Console.Write(" ");
			NewMethod(indexerExpression.Arguments);
		}

		private void NewMethod(IEnumerable<AstNode> nodes)
		{
			Console.Write("[ ");
			WriteCommaSeparatedList(nodes);
			Console.Write(" ]");
		}

		public void VisitInterpolatedStringExpression(InterpolatedStringExpression interpolatedStringExpression)
		{
			Console.WriteLine("InterpolatedStringExpression");
		}

		public void VisitInterpolatedStringText(InterpolatedStringText interpolatedStringText)
		{
			Console.WriteLine("InterpolatedStringText");
		}

		public void VisitInterpolation(Interpolation interpolation)
		{
			Console.WriteLine("Interpolation");
		}

		public void VisitInvocationExpression(InvocationExpression invocationExpression)
		{
			invocationExpression.Target.AcceptVisitor(this);
			Console.Write(" ");
			WriteCommaSeparatedListInParenthesis(invocationExpression.Arguments);
		}

		private void WriteCommaSeparatedListInParenthesis(IEnumerable<AstNode> nodes)
		{
			Console.Write("(");
			WriteCommaSeparatedList(nodes);
			Console.Write(")");
		}

		private void WriteCommaSeparatedList(IEnumerable<AstNode> nodes)
		{
			bool isFirst = true;
			foreach (AstNode node in nodes)
			{
				if (!isFirst)
				{
					Console.Write(",");
				}
				node.AcceptVisitor(this);
				isFirst = false;
			}
		}

		public void VisitIsExpression(IsExpression isExpression)
		{
			Console.WriteLine("IsExpression");
		}

		public void VisitLabelStatement(LabelStatement labelStatement)
		{
			Console.WriteLine("LabelStatement");
		}

		public void VisitLambdaExpression(LambdaExpression lambdaExpression)
		{
			Console.WriteLine("LambdaExpression");
		}

		public void VisitLocalFunctionDeclarationStatement(LocalFunctionDeclarationStatement localFunctionDeclarationStatement)
		{
			Console.WriteLine("LocalFunctionDeclarationStatement");
		}

		public void VisitLockStatement(LockStatement lockStatement)
		{
			Console.WriteLine("LockStatement");
		}

		public void VisitMemberReferenceExpression(MemberReferenceExpression memberReferenceExpression)
		{
			memberReferenceExpression.Target.AcceptVisitor(this);
			Console.Write(".");
			Console.Write(memberReferenceExpression.MemberNameToken.Name);
		}

		public void VisitMemberType(MemberType memberType)
		{
			memberType.Target.AcceptVisitor(this);
		}

		public void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
			methodDeclaration.ReturnType.AcceptVisitor(this);
			Console.Write(" ");
			WriteMethod(methodDeclaration.NameToken.Name, methodDeclaration.Parameters, methodDeclaration.Body);
		}

		public void VisitNamedArgumentExpression(NamedArgumentExpression namedArgumentExpression)
		{
			Console.WriteLine("NamedArgumentExpression");
		}

		public void VisitNamedExpression(NamedExpression namedExpression)
		{
			Console.WriteLine("NamedExpression");
		}

		public void VisitNamespaceDeclaration(NamespaceDeclaration namespaceDeclaration)
		{
			Console.WriteLine("NamespaceDeclaration");
		}

		public void VisitNewLine(NewLineNode newLineNode)
		{
			Console.WriteLine("NewLineNode");
		}

		public void VisitNullNode(AstNode nullNode)
		{
		}

		public void VisitNullReferenceExpression(NullReferenceExpression nullReferenceExpression)
		{
			Console.WriteLine("NullReferenceExpression");
		}

		public void VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression)
		{
			Console.WriteLine("ObjectCreateExpression");
		}

		public void VisitOperatorDeclaration(OperatorDeclaration operatorDeclaration)
		{
			Console.WriteLine("OperatorDeclaration");
		}

		public void VisitOutVarDeclarationExpression(OutVarDeclarationExpression outVarDeclarationExpression)
		{
			Console.WriteLine("OutVarDeclarationExpression");
		}

		public void VisitParameterDeclaration(ParameterDeclaration parameterDeclaration)
		{
			parameterDeclaration.Type.AcceptVisitor(this);
			Console.Write(" ");
			Console.Write(parameterDeclaration.NameToken.Name);
		}

		public void VisitParenthesizedExpression(ParenthesizedExpression parenthesizedExpression)
		{
			Console.WriteLine("ParenthesizedExpression");
		}

		public void VisitPatternPlaceholder(AstNode placeholder, Pattern pattern)
		{
			Console.WriteLine("placeholder");
		}

		public void VisitPointerReferenceExpression(PointerReferenceExpression pointerReferenceExpression)
		{
			Console.WriteLine("PointerReferenceExpression");
		}

		public void VisitPreProcessorDirective(PreProcessorDirective preProcessorDirective)
		{
			Console.WriteLine("PreProcessorDirective");
		}

		public void VisitPrimitiveExpression(PrimitiveExpression primitiveExpression)
		{
			Console.Write(primitiveExpression.Value.ToString());
		}

		public void VisitPrimitiveType(PrimitiveType primitiveType)
		{
			Console.Write(primitiveType.Keyword);
		}

		public void VisitPropertyDeclaration(PropertyDeclaration propertyDeclaration)
		{
			Console.WriteLine("PropertyDeclaration");
		}

		public void VisitQueryContinuationClause(QueryContinuationClause queryContinuationClause)
		{
			Console.WriteLine("QueryContinuationClause");
		}

		public void VisitQueryExpression(QueryExpression queryExpression)
		{
			Console.WriteLine("QueryExpression");
		}

		public void VisitQueryFromClause(QueryFromClause queryFromClause)
		{
			Console.WriteLine("QueryFromClause");
		}

		public void VisitQueryGroupClause(QueryGroupClause queryGroupClause)
		{
			Console.WriteLine("QueryGroupClause");
		}

		public void VisitQueryJoinClause(QueryJoinClause queryJoinClause)
		{
			Console.WriteLine("QueryJoinClause");
		}

		public void VisitQueryLetClause(QueryLetClause queryLetClause)
		{
			Console.WriteLine("QueryLetClause");
		}

		public void VisitQueryOrderClause(QueryOrderClause queryOrderClause)
		{
			Console.WriteLine("QueryOrderClause");
		}

		public void VisitQueryOrdering(QueryOrdering queryOrdering)
		{
			Console.WriteLine("QueryOrdering");
		}

		public void VisitQuerySelectClause(QuerySelectClause querySelectClause)
		{
			Console.WriteLine("QuerySelectClause");
		}

		public void VisitQueryWhereClause(QueryWhereClause queryWhereClause)
		{
			Console.WriteLine("QueryWhereClause");
		}

		public void VisitReturnStatement(ReturnStatement returnStatement)
		{
			Console.Write("return");
			if (!returnStatement.Expression.IsNull)
			{
				Console.Write(" ");
				returnStatement.Expression.AcceptVisitor(this);
			}
			Console.WriteLine(";");
		}

		public void VisitSimpleType(SimpleType simpleType)
		{
			Console.Write(simpleType.IdentifierToken.Name);
		}

		public void VisitSizeOfExpression(SizeOfExpression sizeOfExpression)
		{
			Console.WriteLine("SizeOfExpression");
		}

		public void VisitStackAllocExpression(StackAllocExpression stackAllocExpression)
		{
			Console.WriteLine("StackAllocExpression");
		}

		public void VisitSwitchSection(SwitchSection switchSection)
		{
			Console.WriteLine("SwitchSection");
		}

		public void VisitSwitchStatement(SwitchStatement switchStatement)
		{
			Console.WriteLine("SwitchStatement");
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
			Console.WriteLine("TextNode");
		}

		public void VisitThisReferenceExpression(ThisReferenceExpression thisReferenceExpression)
		{
			Console.WriteLine("ThisReferenceExpression");
		}

		public void VisitThrowExpression(ThrowExpression throwExpression)
		{
			Console.WriteLine("ThrowExpression");
		}

		public void VisitThrowStatement(ThrowStatement throwStatement)
		{
			Console.WriteLine("ThrowStatement");
		}

		public void VisitTryCatchStatement(TryCatchStatement tryCatchStatement)
		{
			Console.WriteLine("TryCatchStatement");
		}

		public void VisitTupleExpression(TupleExpression tupleExpression)
		{
			Console.WriteLine("TupleExpression");
		}

		public void VisitTupleType(TupleAstType tupleType)
		{
			Console.WriteLine("TupleAstType");
		}

		public void VisitTupleTypeElement(TupleTypeElement tupleTypeElement)
		{
			Console.WriteLine("TupleTypeElement");
		}

		public void VisitTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			switch (typeDeclaration.ClassType)
			{
				case ClassType.Enum:
					Console.Write("enum ");
					break;
				case ClassType.Interface:
					Console.Write("interface ");
					break;
				case ClassType.Struct:
					Console.Write("struct ");
					break;
				default:
					Console.Write("class ");
					break;
			}
			Console.WriteLine(typeDeclaration.Name);
			if (typeDeclaration.ClassType != ClassType.Enum)
			{
				foreach (var member in typeDeclaration.Members)
				{
					member.AcceptVisitor(this);
				}
			}
		}

		public void VisitTypeOfExpression(TypeOfExpression typeOfExpression)
		{
			Console.WriteLine("TypeOfExpression");
		}

		public void VisitTypeParameterDeclaration(TypeParameterDeclaration typeParameterDeclaration)
		{
			Console.WriteLine("TypeParameterDeclaration");
		}

		public void VisitTypeReferenceExpression(TypeReferenceExpression typeReferenceExpression)
		{
			typeReferenceExpression.Type.AcceptVisitor(this);
		}

		public void VisitUnaryOperatorExpression(UnaryOperatorExpression unaryOperatorExpression)
		{
			Console.WriteLine("UnaryOperatorExpression");
		}

		public void VisitUncheckedExpression(UncheckedExpression uncheckedExpression)
		{
			Console.WriteLine("UncheckedExpression");
		}

		public void VisitUncheckedStatement(UncheckedStatement uncheckedStatement)
		{
			Console.WriteLine("UncheckedStatement");
		}

		public void VisitUndocumentedExpression(UndocumentedExpression undocumentedExpression)
		{
			Console.WriteLine("UndocumentedExpression");
		}

		public void VisitUnsafeStatement(UnsafeStatement unsafeStatement)
		{
			Console.WriteLine("UnsafeStatement");
		}

		public void VisitUsingAliasDeclaration(UsingAliasDeclaration usingAliasDeclaration)
		{
			Console.WriteLine("UsingAliasDeclaration");
		}

		public void VisitUsingDeclaration(UsingDeclaration usingDeclaration)
		{
			Console.WriteLine("UsingDeclaration");
		}

		public void VisitUsingStatement(UsingStatement usingStatement)
		{
			Console.WriteLine("UsingStatement");
		}

		public void VisitVariableDeclarationStatement(VariableDeclarationStatement variableDeclarationStatement)
		{
			variableDeclarationStatement.Type.AcceptVisitor(this);
			Console.Write(" ");
			WriteCommaSeparatedList(variableDeclarationStatement.Variables);
			Console.WriteLine(";");
		}

		public void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			Console.Write(variableInitializer.Name);
		}

		public void VisitWhileStatement(WhileStatement whileStatement)
		{
			Console.WriteLine("whileStatement");
		}

		public void VisitWhitespace(WhitespaceNode whitespaceNode)
		{
			Console.WriteLine("whitespaceNode");
		}

		public void VisitYieldBreakStatement(YieldBreakStatement yieldBreakStatement)
		{
			Console.WriteLine("YieldBreakStatement");
		}

		public void VisitYieldReturnStatement(YieldReturnStatement yieldReturnStatement)
		{
			Console.WriteLine("YieldReturnStatement");
		}
	}
}
