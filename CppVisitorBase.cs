using System;
using System.Collections.Generic;
using System.Linq;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.CSharp.Syntax.PatternMatching;
using ICSharpCode.Decompiler.TypeSystem;

namespace CppTranslator
{
	/// <summary>
	/// Visitor for everything non-code related in in .Cpp file
	/// </summary>
	public class CppVisitorBase : IAstVisitor
	{
		/// <summary>
		/// Current class we are working one
		/// </summary>
		public IType CurrentClass { get; set; }
		/// <summary>
		/// Current method is a constructor
		/// </summary>
		public bool DoingConstructor { get; set; }
		/// <summary>
		/// Collection of fields for current class
		/// </summary>
		public AstNodeCollection<EntityDeclaration> Fields { get; private set; }
		/// <summary>
		/// visitor used for type definition
		/// </summary>
		public CppTypeVisitor TypeVisitor { get; set; }
		/// <summary>
		/// Visitor for handline IlInstructions within methods
		/// </summary>
		internal MyIlInstructionVisitor MyIlVisitor { get; set; }
		/// <summary>
		/// Used for formatting output
		/// </summary>
		public Formatter Formatter { get; set; }
		/// <summary>
		/// Name of current method
		/// </summary>
		public String CurrentMethodName { get; set; }
		/// <summary>
		/// Operator mapping to names
		/// </summary>
		private Dictionary<OperatorType, String> operators = new Dictionary<OperatorType, string>();
		/// <summary>
		/// Operator mapping to names
		/// </summary>
		internal Dictionary<OperatorType, String> Operators { get => operators; }
		/// <summary>
		/// Initializes a new instance of the <see cref="CppVisitorBase"/> class.
		/// Constructor
		/// </summary>
		/// <param name="formatter">to use</param>
		public CppVisitorBase(Formatter formatter)
		{
			Formatter = formatter;
			TypeVisitor = new CppTypeVisitor(this);
			MyIlVisitor = new MyIlInstructionVisitor(Formatter);
			MyIlVisitor.TypeVisitor = TypeVisitor;
			operators.Add(OperatorType.Addition, "op_Addition");
			operators.Add(OperatorType.Subtraction, "op_Subtraction");
			operators.Add(OperatorType.BitwiseAnd, "op_BitwiseAnd");
		}
		/// <summary>
		/// Visit accessor
		/// </summary>
		/// <param name="accessor">to visit</param>
		public void VisitAccessor(Accessor accessor)
		{
			ICSharpCode.Decompiler.IL.BlockContainer inst = accessor.Body.Annotation<ICSharpCode.Decompiler.IL.BlockContainer>();
			WriteBlock(inst);
		}
		/// <summary>
		/// Add standard header to output file
		/// </summary>
		public virtual void AddHeaders()
		{
			Formatter.AppendLine("#pragma once");
			Formatter.AppendLine("#include \"CaBlockHeader.h\"");
		}
		/// <summary>
		/// Create headers
		/// </summary>
		public virtual void CreateHeaders()
		{
		}
		/// <inheritdoc/>
		public void VisitAnonymousMethodExpression(AnonymousMethodExpression anonymousMethodExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitAnonymousTypeCreateExpression(AnonymousTypeCreateExpression anonymousTypeCreateExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitArrayCreateExpression(ArrayCreateExpression arrayCreateExpression)
		{
		}
		/// <inheritdoc/>
		public void VisitArrayInitializerExpression(ArrayInitializerExpression arrayInitializerExpression)
		{
		}
		/// <inheritdoc/>
		public void VisitArraySpecifier(ArraySpecifier arraySpecifier)
		{
		}
		/// <inheritdoc/>
		public void VisitAsExpression(AsExpression asExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitAssignmentExpression(AssignmentExpression assignmentExpression)
		{
		}
		/// <inheritdoc/>
		public void VisitAttribute(ICSharpCode.Decompiler.CSharp.Syntax.Attribute attribute)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitAttributeSection(AttributeSection attributeSection)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitBaseReferenceExpression(BaseReferenceExpression baseReferenceExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitBinaryOperatorExpression(BinaryOperatorExpression binaryOperatorExpression)
		{
		}
		/// <inheritdoc/>
		public void VisitBlockStatement(BlockStatement blockStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitBreakStatement(BreakStatement breakStatement)
		{
		}
		/// <inheritdoc/>
		public void VisitCaseLabel(CaseLabel caseLabel)
		{
		}
		/// <inheritdoc/>
		public void VisitCastExpression(CastExpression castExpression)
		{
		}
		/// <inheritdoc/>
		public void VisitCatchClause(CatchClause catchClause)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitCheckedExpression(CheckedExpression checkedExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitCheckedStatement(CheckedStatement checkedStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitComment(Comment comment)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitComposedType(ComposedType composedType)
		{
		}
		/// <inheritdoc/>
		public void VisitConditionalExpression(ConditionalExpression conditionalExpression)
		{
		}
		/// <inheritdoc/>
		public void VisitConstraint(Constraint constraint)
		{
			throw new NotImplementedException();
		}
		/// <summary>
		/// Outout method header
		/// </summary>
		/// <param name="methodName">method name</param>
		/// <param name="parameters">parameter collection</param>
		protected virtual void WriteMethodHeader(String methodName, AstNodeCollection<ParameterDeclaration> parameters)
		{
			TypeVisitor.FormatType(CurrentClass);
			Formatter.Append("::");
			Formatter.AppendName(methodName);
			WriteCommaSeparatedListInParenthesis(parameters);
		}
		/// <summary>
		/// Ouput this method
		/// </summary>
		/// <param name="methodName">method name</param>
		/// <param name="parameters">parameter collection</param>
		/// <param name="body">of method</param>
		protected virtual void WriteMethod(String methodName, AstNodeCollection<ParameterDeclaration> parameters, BlockStatement body)
		{
			CurrentMethodName = methodName;
			WriteMethodHeader(methodName, parameters);
			ICSharpCode.Decompiler.IL.BlockContainer inst = body.Annotation<ICSharpCode.Decompiler.IL.BlockContainer>();
			WriteBlock(inst);
		}
		/// <summary>
		/// Output the IlInstructions for the method
		/// </summary>
		/// <param name="inst">block with instructions</param>
		private void WriteBlock(ICSharpCode.Decompiler.IL.BlockContainer inst)
		{
			MyIlVisitor.StartMainBlock(inst);
		}
		/// <inheritdoc/>
		public void VisitConstructorInitializer(ConstructorInitializer constructorInitializer)
		{
			IType type = constructorInitializer.GetResolveResult().Type;
			Formatter.Append(": ");
			if (constructorInitializer.ConstructorInitializerType == ConstructorInitializerType.This)
			{
				Formatter.Append("this");
			}
			else
			{
				TypeVisitor.FormatType(type);
			}
			Formatter.Append(" ");
			WriteCommaSeparatedListInParenthesis(constructorInitializer.Arguments);
		}
		/// <inheritdoc/>
		public void VisitContinueStatement(ContinueStatement continueStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitCSharpTokenNode(CSharpTokenNode cSharpTokenNode)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitCustomEventDeclaration(CustomEventDeclaration customEventDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitDefaultValueExpression(DefaultValueExpression defaultValueExpression)
		{
		}
		/// <inheritdoc/>
		public void VisitDelegateDeclaration(DelegateDeclaration delegateDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitDestructorDeclaration(DestructorDeclaration destructorDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitDirectionExpression(DirectionExpression directionExpression)
		{
		}
		/// <inheritdoc/>
		public void VisitDocumentationReference(DocumentationReference documentationReference)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitDoWhileStatement(DoWhileStatement doWhileStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitEmptyStatement(EmptyStatement emptyStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public virtual void VisitEnumMemberDeclaration(EnumMemberDeclaration enumMemberDeclaration)
		{
		}
		/// <inheritdoc/>
		public void VisitErrorNode(AstNode errorNode)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitEventDeclaration(EventDeclaration eventDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitExpressionStatement(ExpressionStatement expressionStatement)
		{
		}
		/// <inheritdoc/>
		public void VisitExternAliasDeclaration(ExternAliasDeclaration externAliasDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public virtual void VisitFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
		}
		/// <inheritdoc/>
		public void VisitFixedFieldDeclaration(FixedFieldDeclaration fixedFieldDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitFixedStatement(FixedStatement fixedStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitFixedVariableInitializer(FixedVariableInitializer fixedVariableInitializer)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitForeachStatement(ForeachStatement foreachStatement)
		{
		}
		/// <inheritdoc/>
		public void VisitForStatement(ForStatement forStatement)
		{
		}
		/// <inheritdoc/>
		public void VisitGotoCaseStatement(GotoCaseStatement gotoCaseStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitGotoDefaultStatement(GotoDefaultStatement gotoDefaultStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitGotoStatement(GotoStatement gotoStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitIdentifier(Identifier identifier)
		{
			Formatter.AppendName(identifier.Name);
		}
		/// <inheritdoc/>
		public void VisitIdentifierExpression(IdentifierExpression identifierExpression)
		{
			Formatter.AppendName(identifierExpression.Identifier);
		}
		/// <inheritdoc/>
		public void VisitIfElseStatement(IfElseStatement ifElseStatement)
		{
		}
		/// <inheritdoc/>
		public void VisitIndexerDeclaration(IndexerDeclaration indexerDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitIndexerExpression(IndexerExpression indexerExpression)
		{
		}
		/// <inheritdoc/>
		public void VisitInterpolatedStringExpression(InterpolatedStringExpression interpolatedStringExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitInterpolatedStringText(InterpolatedStringText interpolatedStringText)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitInterpolation(Interpolation interpolation)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitInvocationExpression(InvocationExpression invocationExpression)
		{
		}
		/// <summary>
		/// Ouput a comma separated list surrounded by parens
		/// </summary>
		/// <param name="nodes">list to output</param>
		protected void WriteCommaSeparatedListInParenthesis(IEnumerable<AstNode> nodes)
		{
			Formatter.Append("(");
			WriteCommaSeparatedList(nodes);
			Formatter.Append(")");
		}
		/// <summary>
		/// Output a comma separated list
		/// </summary>
		/// <param name="nodes">list to output</param>
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
		/// <inheritdoc/>
		public void VisitIsExpression(IsExpression isExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitLabelStatement(LabelStatement labelStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitLambdaExpression(LambdaExpression lambdaExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitLocalFunctionDeclarationStatement(LocalFunctionDeclarationStatement localFunctionDeclarationStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitLockStatement(LockStatement lockStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitMemberReferenceExpression(MemberReferenceExpression memberReferenceExpression)
		{
		}
		/// <summary>
		/// Is this a property
		/// </summary>
		/// <param name="memberReferenceExpression">item to test</param>
		/// <returns>true if is property</returns>
		private bool IsProperty(MemberReferenceExpression memberReferenceExpression)
		{
			return (IsGetProperty(memberReferenceExpression) || IsSetProperty(memberReferenceExpression));
		}
		/// <summary>
		/// Is this a setter
		/// </summary>
		/// <param name="memberReferenceExpression">item to test</param>
		/// <returns>true if setter</returns>
		private static bool IsSetProperty(MemberReferenceExpression memberReferenceExpression)
		{
			var sym = memberReferenceExpression.GetSymbol();
			return (sym != null && sym.SymbolKind == SymbolKind.Property);
		}
		/// <summary>
		/// Is this a getter
		/// </summary>
		/// <param name="memberReferenceExpression">item to test</param>
		/// <returns>true if setter</returns>
		private static bool IsGetProperty(MemberReferenceExpression memberReferenceExpression)
		{
			ICSharpCode.Decompiler.IL.ILInstruction inst = memberReferenceExpression.Annotation<ICSharpCode.Decompiler.IL.ILInstruction>();
			if (inst == null || !(inst is ICSharpCode.Decompiler.IL.CallInstruction))
			{
				return (false);
			}
			ICSharpCode.Decompiler.IL.CallInstruction call = inst as ICSharpCode.Decompiler.IL.CallInstruction;
			return (call.Method.Name.StartsWith("get_", StringComparison.InvariantCulture));
		}
		/// <inheritdoc/>
		public void VisitMemberType(MemberType memberType)
		{
			memberType.Target.AcceptVisitor(this);
		}
		/// <inheritdoc/>
		public virtual void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
			if (methodDeclaration.Body.IsNull)
			{
				return;
			}
			Formatter.AppendIndented(String.Empty);
			IType type = methodDeclaration.ReturnType.GetResolveResult().Type;
			MyIlVisitor.MethodReturnType = type;
			TypeVisitor.FormatTypeDelaration(type);
			Formatter.Append(" ");
			WriteMethod(methodDeclaration.NameToken.Name, methodDeclaration.Parameters, methodDeclaration.Body);
		}
		/// <summary>
		/// output method modifiers
		/// </summary>
		/// <param name="modifierTokens">collection of modifiers</param>
		protected virtual void WriteModifiers(IEnumerable<CSharpModifierToken> modifierTokens)
		{
			foreach (CSharpModifierToken modifier in modifierTokens)
			{
				if (modifier.Modifier == Modifiers.Static)
				{
					Formatter.Append("static ");
				}
				if (modifier.Modifier == Modifiers.Abstract)
				{
					Formatter.Append("virtual ");
				}
				if (modifier.Modifier == Modifiers.Virtual)
				{
					Formatter.Append("virtual ");
				}
			}
		}
		/// <inheritdoc/>
		public void VisitNamedArgumentExpression(NamedArgumentExpression namedArgumentExpression)
		{
			namedArgumentExpression.Expression.AcceptVisitor(this);
		}
		/// <inheritdoc/>
		public void VisitNamedExpression(NamedExpression namedExpression)
		{
			Formatter.AppendName(namedExpression.NameToken.Name);
			Formatter.Append(" = ");
			namedExpression.Expression.AcceptVisitor(this);
		}
		/// <inheritdoc/>
		public void VisitNamespaceDeclaration(NamespaceDeclaration namespaceDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitNewLine(NewLineNode newLineNode)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitNullNode(AstNode nullNode)
		{
		}
		/// <inheritdoc/>
		public void VisitNullReferenceExpression(NullReferenceExpression nullReferenceExpression)
		{
			Formatter.Append("nullptr");
		}
		/// <inheritdoc/>
		public void VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression)
		{
		}
		/// <inheritdoc/>
		public virtual void VisitOperatorDeclaration(OperatorDeclaration operatorDeclaration)
		{
			Formatter.AppendIndented(String.Empty);
			operatorDeclaration.ReturnType.AcceptVisitor(this);
			Formatter.Append(" ");
			operatorDeclaration.ReturnType.AcceptVisitor(this);
			Formatter.Append("::");
			Formatter.Append(Operators[operatorDeclaration.OperatorType]);
			WriteCommaSeparatedListInParenthesis(operatorDeclaration.Parameters);
			ICSharpCode.Decompiler.IL.BlockContainer inst = operatorDeclaration.Body.Annotation<ICSharpCode.Decompiler.IL.BlockContainer>();
			WriteBlock(inst);
		}
		/// <inheritdoc/>
		public void VisitOutVarDeclarationExpression(OutVarDeclarationExpression outVarDeclarationExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitParameterDeclaration(ParameterDeclaration parameterDeclaration)
		{
			IType type = parameterDeclaration.Type.GetResolveResult().Type;
			TypeVisitor.FormatTypeDelaration(type);
			AddParameterModifiers(parameterDeclaration);
			Formatter.Append(" ");
			Formatter.AppendName(parameterDeclaration.NameToken.Name);
		}
		/// <summary>
		/// Output parameter modifiers
		/// </summary>
		/// <param name="parameterDeclaration">parameter Declaration</param>
		protected void AddParameterModifiers(ParameterDeclaration parameterDeclaration)
		{
			switch (parameterDeclaration.ParameterModifier)
			{
				case ParameterModifier.Ref:
					Formatter.Append("& ");
					break;
				case ParameterModifier.Out:
					Formatter.Append("* ");
					break;
				case ParameterModifier.Params:
					break;
				case ParameterModifier.In:
					break;
			}
		}
		/// <inheritdoc/>
		public void VisitParenthesizedExpression(ParenthesizedExpression parenthesizedExpression)
		{
			Formatter.Append("( ");
			parenthesizedExpression.Expression.AcceptVisitor(this);
			Formatter.Append(" )");
		}
		/// <inheritdoc/>
		public void VisitPatternPlaceholder(AstNode placeholder, Pattern pattern)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitPointerReferenceExpression(PointerReferenceExpression pointerReferenceExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitPreProcessorDirective(PreProcessorDirective preProcessorDirective)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitPrimitiveExpression(PrimitiveExpression primitiveExpression)
		{
			IType type = primitiveExpression.GetResolveResult().Type;
			bool isString = primitiveExpression.Value is String;
			if (isString)
			{
				Formatter.Append("(new String(");
				Formatter.AppendStringsWithControl(primitiveExpression.Value.ToString());
				Formatter.Append("))");
				return;
			}
			ICSharpCode.Decompiler.IL.Box box = primitiveExpression.Annotation<ICSharpCode.Decompiler.IL.Box>();
			if (box != null)
			{
				Formatter.Append("new ");
				Formatter.Append(type.Name);
				Formatter.Append("Value(");
			}
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
			}
			else if (primitiveExpression.Value is Char)
			{
				Char v = (Char)primitiveExpression.Value;
				Formatter.AppendCharWithControls(v, false);
			}
			else if (type.Name == "Single")
			{
				Formatter.Append("((Single)");
				Formatter.Append(primitiveExpression.Value.ToString());
				Formatter.Append(")");
			}
			else
			{
				Formatter.Append(primitiveExpression.Value.ToString());
			}
			if (box != null)
			{
				Formatter.Append(")");
			}
		}
		/// <inheritdoc/>
		public void VisitPrimitiveType(PrimitiveType primitiveType)
		{
			TypeVisitor.AppendType(primitiveType.Keyword);
		}
		/// <inheritdoc/>
		public virtual void VisitPropertyDeclaration(PropertyDeclaration propertyDeclaration)
		{
			IType type = propertyDeclaration.ReturnType.GetResolveResult().Type;
			if (propertyDeclaration.Getter != null)
			{
				Formatter.AppendIndented(String.Empty);
				TypeVisitor.FormatTypeDelaration(type);
				Formatter.Append(" ");
				TypeVisitor.FormatType(CurrentClass);
				Formatter.Append("::");
				Formatter.Append("get_");
				Formatter.Append(propertyDeclaration.NameToken.Name);
				Formatter.AppendLine("()");
				ICSharpCode.Decompiler.IL.ILFunction inst = propertyDeclaration.Getter.Annotation<ICSharpCode.Decompiler.IL.ILFunction>();
				WriteBlock(inst.Body as ICSharpCode.Decompiler.IL.BlockContainer);
			}
			if (propertyDeclaration.Setter != null)
			{
				Formatter.AppendIndented("void ");
				TypeVisitor.FormatType(CurrentClass);
				Formatter.Append("::");
				Formatter.Append("set_");
				Formatter.Append(propertyDeclaration.NameToken.Name);
				Formatter.Append("(");
				TypeVisitor.FormatTypeDelaration(type);
				Formatter.AppendLine(" x_value )");
				ICSharpCode.Decompiler.IL.ILFunction inst = propertyDeclaration.Setter.Annotation<ICSharpCode.Decompiler.IL.ILFunction>();
				WriteBlock(inst.Body as ICSharpCode.Decompiler.IL.BlockContainer);
			}
		}
		/// <inheritdoc/>
		public void VisitQueryContinuationClause(QueryContinuationClause queryContinuationClause)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitQueryExpression(QueryExpression queryExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitQueryFromClause(QueryFromClause queryFromClause)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitQueryGroupClause(QueryGroupClause queryGroupClause)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitQueryJoinClause(QueryJoinClause queryJoinClause)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitQueryLetClause(QueryLetClause queryLetClause)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitQueryOrderClause(QueryOrderClause queryOrderClause)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitQueryOrdering(QueryOrdering queryOrdering)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitQuerySelectClause(QuerySelectClause querySelectClause)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitQueryWhereClause(QueryWhereClause queryWhereClause)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitReturnStatement(ReturnStatement returnStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitSimpleType(SimpleType simpleType)
		{
			simpleType.IdentifierToken.AcceptVisitor(this);
		}
		/// <inheritdoc/>
		public void VisitSizeOfExpression(SizeOfExpression sizeOfExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitStackAllocExpression(StackAllocExpression stackAllocExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitSwitchSection(SwitchSection switchSection)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitSwitchStatement(SwitchStatement switchStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public virtual void VisitSyntaxTree(SyntaxTree syntaxTree)
		{
			foreach (AstNode node in syntaxTree.Children)
			{
				node.AcceptVisitor(this);
			}
		}
		/// <inheritdoc/>
		public void VisitText(TextNode textNode)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitThisReferenceExpression(ThisReferenceExpression thisReferenceExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitThrowExpression(ThrowExpression throwExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitThrowStatement(ThrowStatement throwStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitTryCatchStatement(TryCatchStatement tryCatchStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitTupleExpression(TupleExpression tupleExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitTupleType(TupleAstType tupleType)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitTupleTypeElement(TupleTypeElement tupleTypeElement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public virtual void VisitTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			if (typeDeclaration.ClassType != ClassType.Enum)
			{
				HeaderTypeDeclaration(typeDeclaration);
			}
		}
		/// <summary>
		/// Header type declaration
		/// </summary>
		/// <param name="typeDeclaration">type declaration</param>
		protected virtual void HeaderTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			CurrentClass = typeDeclaration.GetResolveResult().Type;
			Formatter.NameSpace = CurrentClass.Namespace;
			Fields = typeDeclaration.Members;
			CreateStaticVariables();
			foreach (var member in typeDeclaration.Members)
			{
				member.AcceptVisitor(this);
			}
			Fields = null;
		}
		/// <summary>
		/// Add any static field storage to cpp file
		/// </summary>
		private void CreateStaticVariables()
		{
			if (Fields == null)
			{
				return;
			}
			foreach (var member in Fields)
			{
				if (member is FieldDeclaration)
				{
					FormatStaticFieldDeclaration((FieldDeclaration)member);
				}
			}
		}
		/// <inheritdoc/>
		public virtual void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
			DoingConstructor = true;
			TypeDeclaration type = constructorDeclaration.Parent as TypeDeclaration;
			String name = null;
			if (type != null && type.Name != constructorDeclaration.Name)
				name = type.NameToken.Name;
			else
				name = constructorDeclaration.NameToken.Name;
			Formatter.AppendIndented(String.Empty);
			CurrentMethodName = name;
			WriteMethodHeader(name, constructorDeclaration.Parameters);
			if (!constructorDeclaration.Initializer.IsNull)
			{
				Formatter.Append(" ");
				constructorDeclaration.Initializer.AcceptVisitor(this);
			}
			WriteMethodBody(constructorDeclaration.Body);
			DoingConstructor = false;
		}
		/// <summary>
		/// Output method body
		/// </summary>
		/// <param name="body">to output</param>
		protected virtual void WriteMethodBody(BlockStatement body)
		{
			if (body.IsNull)
			{
				Formatter.Append(";");
			}
			else
			{
				ICSharpCode.Decompiler.IL.BlockContainer inst = body.Annotation<ICSharpCode.Decompiler.IL.BlockContainer>();
				WriteBlock(inst);
			}
		}
		/// <summary>
		/// Output static field declarations
		/// </summary>
		/// <param name="fieldDeclaration">field to declare</param>
		private void FormatStaticFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
			VariableInitializer variable = fieldDeclaration.Variables.First<VariableInitializer>();
			var sym = fieldDeclaration.GetSymbol() as IEntity;
			if (sym.IsStatic)
			{
				Formatter.AppendIndented(String.Empty);
				fieldDeclaration.ReturnType.GetResolveResult().Type.AcceptVisitor(TypeVisitor);
				Formatter.Append(" ");
				TypeVisitor.FormatType(CurrentClass);
				Formatter.Append("::");
				WriteCommaSeparatedList(fieldDeclaration.Variables);
				Formatter.AppendLine(";");
			}
		}
		/// <inheritdoc/>
		public virtual void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			Formatter.AppendName(variableInitializer.Name);
			Formatter.Append(" = ");
			variableInitializer.Initializer.AcceptVisitor(this);
		}
		/// <inheritdoc/>
		public void VisitTypeOfExpression(TypeOfExpression typeOfExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitTypeParameterDeclaration(TypeParameterDeclaration typeParameterDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitTypeReferenceExpression(TypeReferenceExpression typeReferenceExpression)
		{
			typeReferenceExpression.Type.AcceptVisitor(this);
		}
		/// <inheritdoc/>
		public void VisitUnaryOperatorExpression(UnaryOperatorExpression unaryOperatorExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitUncheckedExpression(UncheckedExpression uncheckedExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitUncheckedStatement(UncheckedStatement uncheckedStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitUndocumentedExpression(UndocumentedExpression undocumentedExpression)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitUnsafeStatement(UnsafeStatement unsafeStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitUsingAliasDeclaration(UsingAliasDeclaration usingAliasDeclaration)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitUsingDeclaration(UsingDeclaration usingDeclaration)
		{
		}
		/// <inheritdoc/>
		public void VisitUsingStatement(UsingStatement usingStatement)
		{
		}
		/// <inheritdoc/>
		public void VisitVariableDeclarationStatement(VariableDeclarationStatement variableDeclarationStatement)
		{
			IType variableType = variableDeclarationStatement.Type.GetResolveResult().Type;
			TypeVisitor.FormatTypeDelaration(variableType);
			Formatter.Append(" ");
			WriteCommaSeparatedList(variableDeclarationStatement.Variables);
			if (!(variableDeclarationStatement.Parent is ForStatement))
				Formatter.Append(";");
		}
		/// <inheritdoc/>
		public void VisitWhileStatement(WhileStatement whileStatement)
		{
		}
		/// <inheritdoc/>
		public void VisitWhitespace(WhitespaceNode whitespaceNode)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitYieldBreakStatement(YieldBreakStatement yieldBreakStatement)
		{
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitYieldReturnStatement(YieldReturnStatement yieldReturnStatement)
		{
			throw new NotImplementedException();
		}
	}
}
