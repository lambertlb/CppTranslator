using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.CSharp.Syntax.PatternMatching;
using ICSharpCode.Decompiler.Semantics;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;
using System.Linq;

namespace CppTranslator
{
	public class CppVisitorBase : IAstVisitor
	{
		public IType CurrentClass { get; set; }
		public bool HadConstructor { get; set; }
		public bool DoingConstructor { get; set; }
		public AstNodeCollection<EntityDeclaration> Fields { get; set; }
		public CppTypeVisitor TypeVisitor { get; set; }
		MyIlInstructionVisitor myIlVisitor;
		internal MyIlInstructionVisitor MyIlVisitor { get => myIlVisitor;}
		private Formatter formatter;
		public Formatter Formatter { get => formatter; }
		public int StaticArrayCount { get; set; }
		public String CurrentMethod { get; set; }
		public Expression CurrentExpression { get; set; }
		internal Dictionary<OperatorType, String> operators = new Dictionary<OperatorType, string>();

		public CppVisitorBase(Formatter formatter)
		{
			this.formatter = formatter;
			TypeVisitor = new CppTypeVisitor(this);
			myIlVisitor = new MyIlInstructionVisitor(Formatter);
			operators.Add(OperatorType.Addition, "op_Addition");
			operators.Add(OperatorType.Subtraction, "op_Subtraction");
			operators.Add(OperatorType.BitwiseAnd, "op_BitwiseAnd");
		}

		public virtual void CreateHeaders()
		{
		}

		public void VisitAccessor(Accessor accessor)
		{
			ICSharpCode.Decompiler.IL.BlockContainer inst = accessor.Body.Annotation<ICSharpCode.Decompiler.IL.BlockContainer>();
			WriteBlock(inst);
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
		}


		public void VisitArrayInitializerExpression(ArrayInitializerExpression arrayInitializerExpression)
		{
		}

		public void VisitArraySpecifier(ArraySpecifier arraySpecifier)
		{
		}

		public void VisitAsExpression(AsExpression asExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitAssignmentExpression(AssignmentExpression assignmentExpression)
		{
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
			throw new NotImplementedException();
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
		}

		public void VisitConditionalExpression(ConditionalExpression conditionalExpression)
		{
		}

		public void VisitConstraint(Constraint constraint)
		{
			throw new NotImplementedException();
		}

		protected virtual void WriteMethodHeader(String medodName, AstNodeCollection<ParameterDeclaration> parameters)
		{
			FormatType(CurrentClass);
			Formatter.Append("::");
			Formatter.AppendName(medodName);
			WriteCommaSeparatedListInParenthesis(parameters);
		}
		protected virtual void WriteMethod(String methodName, AstNodeCollection<ParameterDeclaration> parameters, BlockStatement body)
		{
			StaticArrayCount = 0;
			CurrentMethod = methodName;
			WriteMethodHeader(methodName, parameters);
			ICSharpCode.Decompiler.IL.BlockContainer inst = body.Annotation<ICSharpCode.Decompiler.IL.BlockContainer>();
			WriteBlock(inst);
		}

		private void WriteBlock(ICSharpCode.Decompiler.IL.BlockContainer inst)
		{
			MyIlVisitor.StartMainBlock(inst);
		}

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
				FormatType(type);
			}
			Formatter.Append(" ");
			WriteCommaSeparatedListInParenthesis(constructorInitializer.Arguments);
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

		public virtual void VisitEnumMemberDeclaration(EnumMemberDeclaration enumMemberDeclaration)
		{
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
		}

		public void VisitExternAliasDeclaration(ExternAliasDeclaration externAliasDeclaration)
		{
			throw new NotImplementedException();
		}

		public virtual void VisitFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
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
		}

		public void VisitForStatement(ForStatement forStatement)
		{
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
			Formatter.AppendName(identifier.Name);
		}

		public void VisitIdentifierExpression(IdentifierExpression identifierExpression)
		{
		}

		public void VisitIfElseStatement(IfElseStatement ifElseStatement)
		{
		}

		public void VisitIndexerDeclaration(IndexerDeclaration indexerDeclaration)
		{
			throw new NotImplementedException();
		}

		public void VisitIndexerExpression(IndexerExpression indexerExpression)
		{
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
		}

		private bool IsProperty(MemberReferenceExpression memberReferenceExpression)
		{
			return (IsGetProperty(memberReferenceExpression) || IsSetProperty(memberReferenceExpression));
		}
		private bool IsSetProperty(MemberReferenceExpression memberReferenceExpression)
		{
			var sym = memberReferenceExpression.GetSymbol();
			return (sym != null && sym.SymbolKind == SymbolKind.Property);
		}
		private bool IsGetProperty(MemberReferenceExpression memberReferenceExpression)
		{
			ICSharpCode.Decompiler.IL.ILInstruction inst = memberReferenceExpression.Annotation<ICSharpCode.Decompiler.IL.ILInstruction>();
			if (inst == null || !(inst is ICSharpCode.Decompiler.IL.CallInstruction))
			{
				return (false);
			}
			ICSharpCode.Decompiler.IL.CallInstruction call = inst as ICSharpCode.Decompiler.IL.CallInstruction;
			return (call.Method.Name.StartsWith("get_"));
		}

		public void VisitMemberType(MemberType memberType)
		{
			memberType.Target.AcceptVisitor(this);
		}

		public virtual void VisitMethodDeclaration(MethodDeclaration methodDeclaration)
		{
			if (methodDeclaration.Body.IsNull)
			{
				return;
			}
			Formatter.AppendIndented("");
			IType type = methodDeclaration.ReturnType.GetResolveResult().Type;
			MyIlVisitor.MethodReturnType = type;
			FormatTypeDelaration(type);
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

		public void VisitNamedArgumentExpression(NamedArgumentExpression namedArgumentExpression)
		{
			namedArgumentExpression.Expression.AcceptVisitor(this);
		}

		public void VisitNamedExpression(NamedExpression namedExpression)
		{
			Formatter.AppendName(namedExpression.NameToken.Name);
			Formatter.Append(" = ");
			namedExpression.Expression.AcceptVisitor(this);
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
			Formatter.Append("nullptr");
		}

		public void VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression)
		{
			IType type = objectCreateExpression.GetResolveResult().Type;
			Formatter.Append("(");
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
			Formatter.Append(")");
		}

		public virtual void VisitOperatorDeclaration(OperatorDeclaration operatorDeclaration)
		{
			Formatter.AppendIndented("");
			operatorDeclaration.ReturnType.AcceptVisitor(this);
			Formatter.Append(" ");
			operatorDeclaration.ReturnType.AcceptVisitor(this);
			Formatter.Append("::");
			Formatter.Append(operators[operatorDeclaration.OperatorType]);
			WriteCommaSeparatedListInParenthesis(operatorDeclaration.Parameters);
			ICSharpCode.Decompiler.IL.BlockContainer inst = operatorDeclaration.Body.Annotation<ICSharpCode.Decompiler.IL.BlockContainer>();
			WriteBlock(inst);
		}

		public void VisitOutVarDeclarationExpression(OutVarDeclarationExpression outVarDeclarationExpression)
		{
			throw new NotImplementedException();
		}

		public void VisitParameterDeclaration(ParameterDeclaration parameterDeclaration)
		{
			IType type = parameterDeclaration.Type.GetResolveResult().Type;
			FormatTypeDelaration(type);
			//			parameterDeclaration.Type.AcceptVisitor(this);
			AddParameterModifiers(parameterDeclaration);

			Formatter.Append(" ");
			Formatter.AppendName(parameterDeclaration.NameToken.Name);
		}

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
		public virtual void VisitPropertyDeclaration(PropertyDeclaration propertyDeclaration)
		{
			IType type = propertyDeclaration.ReturnType.GetResolveResult().Type;
			if (propertyDeclaration.Getter != null)
			{
				Formatter.AppendIndented("");
				FormatTypeDelaration(type);
				Formatter.Append(" ");
				FormatType(CurrentClass);
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
				FormatType(CurrentClass);
				Formatter.Append("::");
				Formatter.Append("set_");
				Formatter.Append(propertyDeclaration.NameToken.Name);
				Formatter.Append("(");
				FormatTypeDelaration(type);
				Formatter.AppendLine(" x_value )");
				ICSharpCode.Decompiler.IL.ILFunction inst = propertyDeclaration.Setter.Annotation<ICSharpCode.Decompiler.IL.ILFunction>();
				WriteBlock(inst.Body as ICSharpCode.Decompiler.IL.BlockContainer);
			}
			return;
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
				Formatter.AppendIndented("");
				statement.AcceptVisitor(this);
				Formatter.AppendLine("");
			}
		}

		public void VisitSwitchStatement(SwitchStatement switchStatement)
		{
			Formatter.Append("switch ( ");
			switchStatement.Expression.AcceptVisitor(this);
			Formatter.AppendLine(" )");
			Formatter.AddOpenBrace();
			foreach (var section in switchStatement.SwitchSections)
			{
				section.AcceptVisitor(this);
			}
			Formatter.AddCloseBrace();
		}

		public virtual void VisitSyntaxTree(SyntaxTree syntaxTree)
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
			HadConstructor = false;
			CurrentClass = typeDeclaration.GetResolveResult().Type;
			Formatter.Name_space = CurrentClass.Namespace;
			Fields = typeDeclaration.Members;
			CreateStaticVariables();
			foreach (var member in typeDeclaration.Members)
			{
				member.AcceptVisitor(this);
			}
			if (!HadConstructor)
			{
				CreateDefaultConstructor(typeDeclaration);
			}
			Fields = null;
		}

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

		public virtual void VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration)
		{
			DoingConstructor = true;
			TypeDeclaration type = constructorDeclaration.Parent as TypeDeclaration;
			String name = null;
			if (type != null && type.Name != constructorDeclaration.Name)
				name = type.NameToken.Name;
			else
				name = constructorDeclaration.NameToken.Name;
			Formatter.AppendIndented("");
			StaticArrayCount = 0;
			CurrentMethod = name;
			if (constructorDeclaration.Parameters.Count == 0)
				HadConstructor = true;
			WriteMethodHeader(name, constructorDeclaration.Parameters);
			if (!constructorDeclaration.Initializer.IsNull)
			{
				Formatter.Append(" ");
				constructorDeclaration.Initializer.AcceptVisitor(this);
			}
			WriteMethodBody(constructorDeclaration.Body);
			DoingConstructor = false;
		}
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
		public virtual void CreateDefaultConstructor(TypeDeclaration typeDeclaration)
		{
			IType type = typeDeclaration.Annotation<TypeResolveResult>().Type;
			Formatter.AppendIndented("");
			FormatType(type);
			Formatter.Append("::");
			FormatType(type);
			Formatter.Append("()");
			Formatter.AddOpenBrace();
			InitializeFields();
			Formatter.AddCloseBrace();
		}

		private void InitializeFields()
		{
			if (!DoingConstructor || Fields == null)
			{
				return;
			}
			foreach (var member in Fields)
			{
				if (member is FieldDeclaration)
				{
					FormatFieldDeclaration((FieldDeclaration)member);
				}
			}
		}
		private void FormatFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
			VariableInitializer variable = fieldDeclaration.Variables.First<VariableInitializer>();
			if (variable.Initializer.IsNull)
			{
				return;
			}
			var sym = fieldDeclaration.GetSymbol() as IEntity;
			if (!sym.IsStatic)
			{
				Formatter.AppendIndented("");
				WriteCommaSeparatedList(fieldDeclaration.Variables);
				Formatter.AppendLine(";");
			}
		}

		private void FormatStaticFieldDeclaration(FieldDeclaration fieldDeclaration)
		{
			VariableInitializer variable = fieldDeclaration.Variables.First<VariableInitializer>();
			var sym = fieldDeclaration.GetSymbol() as IEntity;
			if (sym.IsStatic)
			{
				Formatter.AppendIndented("");
				fieldDeclaration.ReturnType.GetResolveResult().Type.AcceptVisitor(TypeVisitor);
				Formatter.Append(" ");
				FormatType(CurrentClass);
				Formatter.Append("::");
				WriteCommaSeparatedList(fieldDeclaration.Variables);
				Formatter.AppendLine(";");
			}
		}
		public virtual void VisitVariableInitializer(VariableInitializer variableInitializer)
		{
			Formatter.AppendName(variableInitializer.Name);
			Formatter.Append(" = ");
			variableInitializer.Initializer.AcceptVisitor(this);
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
			IType variableType = variableDeclarationStatement.Type.GetResolveResult().Type;
			FormatTypeDelaration(variableType);
			//SimpleType simpleType = variableDeclarationStatement.Type as SimpleType;
			//if (simpleType != null)
			//{
			//	IType type = simpleType.GetResolveResult().Type;
			//	//				FormatTypeDelaration(type, simpleType.IdentifierToken.Name);
			//	FormatTypeDelaration(type);
			//}
			//else
			//{
			//	variableDeclarationStatement.Type.AcceptVisitor(this);
			//}
			Formatter.Append(" ");
			WriteCommaSeparatedList(variableDeclarationStatement.Variables);
			if (!(variableDeclarationStatement.Parent is ForStatement))
				Formatter.Append(";");
		}
		public void FormatTypeDelaration(IType type)
		{
			FormatType(type);
			if (IsPointerType(type))
			{
				Formatter.Append("*");
			}
		}
		public void FormatType(IType type)
		{
			String name = type.Name;
			if (type.Kind == TypeKind.ByReference)
			{
				name = name.Substring(0, name.Length - 1);
			}
			if (type.Kind == TypeKind.Array)
			{
				name = "Array*";
			}
			Formatter.AppendName(name);
		}

		internal bool IsPointerType(IType type)
		{
			if (type.Kind == TypeKind.ByReference)
			{
				ByReferenceType by = (ByReferenceType)type;
				return (by.ElementType.Kind == TypeKind.Class);
			}
			return (type.Kind == TypeKind.Class);
		}

		public void VisitWhileStatement(WhileStatement whileStatement)
		{
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
