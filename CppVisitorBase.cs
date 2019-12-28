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
using ICSharpCode.Decompiler.CSharp.Syntax.PatternMatching;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;

namespace CppTranslator
{
	/// <summary>
	/// Visitor for everything non-code related in in .Cpp file
	/// The main function is to is to create the .h file to support the .cpp file.
	/// </summary>
	public class CppVisitorBase : IAstVisitor
	{
		/// <summary>
		/// Current class we are working one
		/// </summary>
		public IType CurrentClass { get; set; }
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
			MyIlVisitor.StartMainBlock(inst, null);
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
			WriteMethodHeader(methodName, parameters);
			ICSharpCode.Decompiler.IL.BlockContainer inst = body.Annotation<ICSharpCode.Decompiler.IL.BlockContainer>();
			MyIlVisitor.StartMainBlock(inst, null);
		}
		/// <summary>
		/// output method modifiers
		/// </summary>
		/// <param name="modifierTokens">collection of modifiers</param>
		protected virtual void WriteModifiers(IEnumerable<CSharpModifierToken> modifierTokens)
		{
			foreach (CSharpModifierToken modifier in modifierTokens)
			{
				if ((modifier.Modifier & Modifiers.Static) != 0)
				{
					Formatter.Append("static ");
				}
				if ((modifier.Modifier & Modifiers.Abstract) != 0)
				{
					Formatter.Append("virtual ");
				}
				if ((modifier.Modifier & Modifiers.Virtual) != 0)
				{
					Formatter.Append("virtual ");
				}
			}
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
		/// <summary>
		/// Header type declaration
		/// </summary>
		/// <param name="typeDeclaration">type declaration</param>
		protected virtual void HeaderTypeDeclaration(TypeDeclaration typeDeclaration)
		{
			CurrentClass = typeDeclaration.GetResolveResult().Type;
			Formatter.NameSpace = CurrentClass.Namespace;
			foreach (var member in typeDeclaration.Members)
			{
				member.AcceptVisitor(this);
			}
		}
		/// <summary>
		/// Output method body
		/// </summary>
		/// <param name="body">to output</param>
		/// <param name="injection">statements to inject</param>
		protected virtual void WriteMethodBody(BlockStatement body, String injection)
		{
			if (body.IsNull)
			{
				Formatter.Append(";");
			}
			else
			{
				ICSharpCode.Decompiler.IL.BlockContainer inst = body.Annotation<ICSharpCode.Decompiler.IL.BlockContainer>();
				MyIlVisitor.StartMainBlock(inst, injection);
			}
		}
		/// <summary>
		/// Output static field declarations
		/// </summary>
		/// <param name="fieldDeclaration">field to declare</param>
		private void FormatStaticFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
			Formatter.AppendIndented(String.Empty);
			fieldDeclaration.ReturnType.GetResolveResult().Type.AcceptVisitor(TypeVisitor);
			Formatter.Append(" ");
			TypeVisitor.FormatType(CurrentClass);
			Formatter.Append("::");
			WriteCommaSeparatedList(fieldDeclaration.Variables);
			Formatter.AppendLine(";");
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
			if ((fieldDeclaration.Modifiers & Modifiers.Static) != 0)
				FormatStaticFieldDeclaration(fieldDeclaration);
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
		/// <inheritdoc/>
		public void VisitMemberType(MemberType memberType)
		{
			memberType.Target.AcceptVisitor(this);
		}
		/// <inheritdoc/>
		public virtual void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
			if (!methodDeclaration.Body.IsNull)
			{
				Formatter.AppendIndented(String.Empty);
				IType type = methodDeclaration.ReturnType.GetResolveResult().Type;
				MyIlVisitor.MethodReturnType = type;
				TypeVisitor.FormatTypeDelaration(type);
				Formatter.Append(" ");
				WriteMethod(methodDeclaration.NameToken.Name, methodDeclaration.Parameters, methodDeclaration.Body);
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
			throw new NotImplementedException();
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
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitNullReferenceExpression(NullReferenceExpression nullReferenceExpression)
		{
			Formatter.Append("nullptr");
		}
		/// <inheritdoc/>
		public void VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression)
		{
			throw new NotImplementedException();
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
			MyIlVisitor.StartMainBlock(inst, null);
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
		/// <inheritdoc/>
		public void VisitParenthesizedExpression(ParenthesizedExpression parenthesizedExpression)
		{
			throw new NotImplementedException();
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
				Formatter.Append((Boolean)primitiveExpression.Value ? "true" : "false");
			else if (primitiveExpression.Value is Char)
				Formatter.AppendCharWithControls((Char)primitiveExpression.Value, false);
			else if (type.Name == "Single")
			{
				Formatter.Append("((Single)");
				Formatter.Append(primitiveExpression.Value.ToString());
				Formatter.Append(")");
			}
			else
				Formatter.Append(primitiveExpression.Value.ToString());
			if (box != null)
				Formatter.Append(")");
		}
		/// <inheritdoc/>
		public void VisitPrimitiveType(PrimitiveType primitiveType)
		{
			throw new NotImplementedException();
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
				MyIlVisitor.StartMainBlock(inst.Body as ICSharpCode.Decompiler.IL.BlockContainer, null);
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
				MyIlVisitor.StartMainBlock(inst.Body as ICSharpCode.Decompiler.IL.BlockContainer, null);
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
		/// <inheritdoc/>
		public virtual void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
			bool isStatic = (constructorDeclaration.Modifiers & Modifiers.Static) != 0;
			TypeDeclaration type = constructorDeclaration.Parent as TypeDeclaration;
			String name;
			if (type != null && type.Name != constructorDeclaration.Name)
				name = type.NameToken.Name;
			else
				name = constructorDeclaration.NameToken.Name;
			Formatter.AppendIndented(String.Empty);
			if (isStatic)
			{
				WriteStaticConstructor(constructorDeclaration, name);
				return;
			}
			WriteMethodHeader(name, constructorDeclaration.Parameters);
			if (!constructorDeclaration.Initializer.IsNull)
			{
				Formatter.Append(" ");
				constructorDeclaration.Initializer.AcceptVisitor(this);
			}
			WriteMethodBody(constructorDeclaration.Body, null);
		}
		private void WriteStaticConstructor(ConstructorDeclaration constructorDeclaration, string name)
		{
			Formatter.Append("Boolean ");
			TypeVisitor.FormatType(CurrentClass);
			Formatter.Append("::");
			Formatter.AppendName(name);
			Formatter.AppendLine("_Static()");
			WriteMethodBody(constructorDeclaration.Body, "return (true);");
			Formatter.AppendIndented("Boolean ");
			TypeVisitor.FormatType(CurrentClass);
			Formatter.Append("::");
			Formatter.AppendName(name);
			Formatter.Append("_Initilized = ");
			TypeVisitor.FormatType(CurrentClass);
			Formatter.Append("::");
			Formatter.AppendName(name);
			Formatter.AppendLine("_Static();");
		}
		/// <inheritdoc/>
		public virtual void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			throw new NotImplementedException();
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
			throw new NotImplementedException();
		}
		/// <inheritdoc/>
		public void VisitWhileStatement(WhileStatement whileStatement)
		{
			throw new NotImplementedException();
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
