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
		private Dictionary<String, String> substitutes = new Dictionary<String, String>();
		private Dictionary<String, String> primatives = new Dictionary<String, String>();
		private String enumName;
		public String EnumName { get => enumName; set => enumName = value; }
		public IType CurrentClass { get; set; }
		public bool HadConstructor { get; set; }
		public bool DoingConstructor { get; set; }
		public AstNodeCollection<EntityDeclaration> Fields { get; set; }
		public CppTypeVisitor TypeVisitor { get; set; }
		public CallInstructionVisitor CallVisitor { get; set; }
		private Formatter formatter;
		public Formatter Formatter { get => formatter; }
		public int StaticArrayCount { get; set; }
		public String CurrentMethod { get; set; }
		public Expression CurrentExpression { get; set; }

		public CppVisitorBase(Formatter formatter)
		{
			this.formatter = formatter;
			TypeVisitor = new CppTypeVisitor(this);
			CallVisitor = new CallInstructionVisitor(this);
			substitutes.Add("byteMaxValue", Byte.MaxValue.ToString());
			substitutes.Add("byteMinValue", Byte.MinValue.ToString());
			substitutes.Add("sbyteMaxValue", SByte.MaxValue.ToString());
			substitutes.Add("sbyteMinValue", SByte.MinValue.ToString());
			substitutes.Add("shortMaxValue", Int16.MaxValue.ToString());
			substitutes.Add("shortMinValue", Int16.MinValue.ToString());
			substitutes.Add("ushortMaxValue", UInt16.MaxValue.ToString());
			substitutes.Add("ushortMinValue", UInt16.MinValue.ToString());
			substitutes.Add("intMaxValue", Int32.MaxValue.ToString());
			substitutes.Add("intMinValue", Int32.MinValue.ToString());
			substitutes.Add("uintMaxValue", UInt32.MaxValue.ToString());
			substitutes.Add("uintMinValue", UInt32.MinValue.ToString());
			substitutes.Add("longMaxValue", Int64.MaxValue.ToString());
			substitutes.Add("longMinValue", Int64.MinValue.ToString());
			substitutes.Add("ulongMaxValue", UInt64.MaxValue.ToString());
			substitutes.Add("ulongMinValue", UInt64.MinValue.ToString());
			substitutes.Add("floatMaxValue", Single.MaxValue.ToString());
			substitutes.Add("floatMinValue", Single.MinValue.ToString());
			substitutes.Add("doubleMaxValue", Double.MaxValue.ToString());
			substitutes.Add("doubleMinValue", Double.MinValue.ToString());
			substitutes.Add("DateTimeMaxValue", DateTime.MaxValue.Ticks.ToString());
			substitutes.Add("DateTimeMinValue", DateTime.MinValue.Ticks.ToString());
			substitutes.Add("TimeSpaneMaxValue", TimeSpan.MaxValue.Ticks.ToString());
			substitutes.Add("TimeSpaneMinValue", TimeSpan.MinValue.Ticks.ToString());

			primatives.Add("Boolean", "Boolean");
			primatives.Add("Char", "Char");
			primatives.Add("Byte", "Byte");
			primatives.Add("SByte", "SByte");
			primatives.Add("Int16", "Int16");
			primatives.Add("UInt16", "UInt16");
			primatives.Add("Int32", "Int32");
			primatives.Add("UInt32", "UInt32");
			primatives.Add("Int64", "Int64");
			primatives.Add("UInt64", "UInt64");
			primatives.Add("Single", "Single");
			primatives.Add("Double", "Double");
		}

		public virtual void CreateHeaders()
		{
		}

		public void CastToType(IType toType, IType fromType, AstNode expression, bool needGetAs)
		{
			//if (toType.Name == "Single")
			//{
			//	Formatter.Append("((Single)");
			//	expression.AcceptVisitor(this);
			//	Formatter.Append(")");
			//	return;
			//}
			expression.AcceptVisitor(this);
			return;
			if (toType.Kind == TypeKind.Unknown)
			{
				expression.AcceptVisitor(this);
				return;
			}
			bool castToPrimativeNumber = NeedToCastToNumber(toType, expression);
			//			if (!castToPrimativeNumber && (toType.Kind == TypeKind.Array || toType.Kind == fromType.Kind))
			if (!IsPrimative(toType) && (toType.Kind == TypeKind.Array || toType.Kind == fromType.Kind))
			{
				expression.AcceptVisitor(this);
				return;
			}
			ICSharpCode.Decompiler.IL.Box box = expression.Annotation<ICSharpCode.Decompiler.IL.Box>();
			if (box != null)
			{
				Formatter.Append("(new ");
				Formatter.Append(fromType.Name);
				Formatter.Append("Box(");
				expression.AcceptVisitor(this);
				Formatter.Append(" ))");
				return;
			}
			if (castToPrimativeNumber)
				Formatter.Append("(");
			Formatter.Append("( ");
			Formatter.Append(toType.Name);
			Formatter.Append(" ) ");
			expression.AcceptVisitor(this);
			if (castToPrimativeNumber)
				Formatter.Append(")");
			if (needGetAs)
			{
				Formatter.Append("->get_As");
				Formatter.Append(toType.Name);
				Formatter.Append("()");
			}
		}

		public bool IsPrimative(IType toType)
		{
			if (toType == null)
			{
				return (false);
			}
			return (primatives.ContainsKey(toType.Name));
		}
		private bool NeedToCastToNumber(IType toType, AstNode expression)
		{
			if (!IsPrimative(toType))
				return (false);
			String exp = expression.ToString();
			return (Char.IsDigit(exp[0]));
		}

		internal void CastToValueType(IType toType, AstNode expression)
		{
			Formatter.Append("(");
			ToValueType(toType);
			Formatter.Append(")");
			expression.AcceptVisitor(this);
		}

		internal void ToValueType(IType toType)
		{
			Formatter.Append(toType.Name);
			Formatter.Append("Value");
		}

		internal void CastToType(IType toType, AstNode expression)
		{
			IType fromType = expression.GetResolveResult().Type;
			CastToType(toType, fromType, expression, false);
		}

		private void CastToType(IType targetType)
		{
			Formatter.Append(targetType.Name);
			return;
			if (targetType.Kind != TypeKind.Unknown)
			{
				Formatter.Append("((");
				Formatter.Append(targetType.Name);
				Formatter.Append(")");
			}
		}

		internal void CastToType(IType targetType, String whatToCast)
		{
			CastToType(targetType);
			Formatter.Append(whatToCast);
		}

		public void VisitAccessor(Accessor accessor)
		{
			WriteBlock(accessor.Body);
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
			Formatter.Append("(new Array(");
			arrayCreateExpression.Type.AcceptVisitor(this);
			Formatter.Append("Type,");
			if (arrayCreateExpression.Arguments.Count > 0)
			{
				WriteCommaSeparatedList(arrayCreateExpression.Arguments);
			}
			Formatter.Append(")");
			foreach (var specifier in arrayCreateExpression.AdditionalArraySpecifiers)
			{
				specifier.AcceptVisitor(this);
			}
			if (!arrayCreateExpression.Initializer.IsNull)
			{
				Formatter.Append(")->Initialize((");
				arrayCreateExpression.Type.AcceptVisitor(this);
				Formatter.Append("*) ");
				Formatter.Append(CurrentMethod);
				Formatter.Append("Array");
				Formatter.Append(StaticArrayCount.ToString());
				++StaticArrayCount;
			}
			Formatter.Append(")");
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
			var sym = assignmentExpression.Left.GetSymbol();
			assignmentExpression.Left.AcceptVisitor(this);
			if (sym != null && sym.SymbolKind == SymbolKind.Property)
			{
				Formatter.Append("(");
				assignmentExpression.Right.AcceptVisitor(this);
				Formatter.Append(")");
				return;
			}
			Formatter.Append(" ");
			if (assignmentExpression.Operator == AssignmentOperatorType.Assign)
			{
				Formatter.Append(AssignmentExpression.GetOperatorRole(assignmentExpression.Operator).ToString());
			}
			else
			{
				Formatter.Append("= ");
				if (HandleSpecialOperators(assignmentExpression.Left, assignmentExpression.Right, assignmentExpression.Operator.ToString()))
					return;
				assignmentExpression.Left.AcceptVisitor(this);
				Formatter.Append(" ");
				Formatter.Append(GetOperator(assignmentExpression.Operator));
			}
			Formatter.Append(" ");
			IType type = assignmentExpression.Left.GetResolveResult().Type;
			if (type.Kind == TypeKind.Struct)
			{
				CastToType(type, assignmentExpression.Right);
			}
			else
			{
				assignmentExpression.Right.AcceptVisitor(this);
			}
		}
		public String GetOperator(AssignmentOperatorType op)
		{
			switch (op)
			{
				case AssignmentOperatorType.Add:
					return "+";
				case AssignmentOperatorType.Subtract:
					return "-";
				case AssignmentOperatorType.Multiply:
					return "*";
				case AssignmentOperatorType.Divide:
					return "/";
				case AssignmentOperatorType.Modulus:
					return "%";
				case AssignmentOperatorType.ShiftLeft:
					return "<<";
				case AssignmentOperatorType.ShiftRight:
					return ">>";
				case AssignmentOperatorType.BitwiseAnd:
					return "&";
				case AssignmentOperatorType.BitwiseOr:
					return "|";
				case AssignmentOperatorType.ExclusiveOr:
					return "^";
				default:
					throw new NotSupportedException("Invalid value for AssignmentOperatorType");
			}
		}

		private void AssignProperty(AssignmentExpression assignmentExpression)
		{
			var sym = assignmentExpression.Left.GetSymbol();
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
			if (HandleSpecialOperators(binaryOperatorExpression.Left, binaryOperatorExpression.Right, binaryOperatorExpression.Operator.ToString()))
				return;
			IType left = binaryOperatorExpression.Left.GetResolveResult().Type;
			IType right = binaryOperatorExpression.Right.GetResolveResult().Type;
			binaryOperatorExpression.Left.AcceptVisitor(this);
			Formatter.Append(" ");
			Formatter.Append(BinaryOperatorExpression.GetOperatorRole(binaryOperatorExpression.Operator).ToString());
			Formatter.Append(" ");
			if (right.Kind == TypeKind.Struct)
			{
				CastToType(right, binaryOperatorExpression.Right);
			}
			else
			{
				binaryOperatorExpression.Right.AcceptVisitor(this);
			}
		}

		private bool HandleSpecialOperators(Expression leftExpression, Expression rightExpression, String oper)
		{
			if (oper == "==" || oper == "!=" || oper == "Equality" || oper == "InEquality")
				return (HandleEqualityOperator(leftExpression, rightExpression, oper));
			if (oper == "%" || oper == "Modulus")
				return (HandleModulusOperator(leftExpression, rightExpression, oper));
			if (oper == "+" || oper == "Add")
				return (HandleAddStringsOperator(leftExpression, rightExpression, oper));
			return (false);
		}

		internal bool IsString(IType type)
		{
			return (type.Name == "String");
		}
		private bool HandleAddStringsOperator(Expression leftExpression, Expression rightExpression, string oper)
		{
			IType left = leftExpression.GetResolveResult().Type;
			IType right = rightExpression.GetResolveResult().Type;
			if (IsString(left) && IsString(right))
			{
				leftExpression.AcceptVisitor(this);
				Formatter.Append("->Combine(");
				rightExpression.AcceptVisitor(this);
				Formatter.Append(")");
				return (true);
			}
			return (false);
		}

		internal bool IsDouble(IType type)
		{
			return (type.Name == "Double" || type.Name == "Single");
		}
		private bool HandleModulusOperator(Expression leftExpression, Expression rightExpression, String oper)
		{
			IType left = leftExpression.GetResolveResult().Type;
			IType right = rightExpression.GetResolveResult().Type;
			bool leftIsDouble = IsDouble(left);
			bool rightIsDouble = IsDouble(right);
			if (leftIsDouble || rightIsDouble)
			{
				Formatter.Append("((DoubleValue)");
				leftExpression.AcceptVisitor(this);
				Formatter.Append(") % ");
				rightExpression.AcceptVisitor(this);
				return (true);
			}
			return (false);
		}

		private bool HandleEqualityOperator(Expression leftExpression, Expression rightExpression, String oper)
		{
			IType left = leftExpression.GetResolveResult().Type;
			IType right = rightExpression.GetResolveResult().Type;
			if (left.Kind == TypeKind.Class || left.Kind == TypeKind.Struct)
			{
				if (oper == "!=" || oper == "InEquality")
					Formatter.Append("!");
				Formatter.Append("(");
				if (IsPrimative(left))
					ToValueType(left);
				Formatter.Append("(");
				leftExpression.AcceptVisitor(this);
				Formatter.Append("))");

				if (left.Kind == TypeKind.Class)
				{
					Formatter.Append("->");
				}
				else
				{
					Formatter.Append(".");
				}
				Formatter.Append("Equals(");
				String rt = rightExpression.ToString();
				if (rt == "0")
				{
					Formatter.Append("(");
					Formatter.Append(left.Name);
					Formatter.Append(")");
				}
				rightExpression.AcceptVisitor(this);
				Formatter.Append(")");
				return (true);
			}
			return (false);
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
				Formatter.AppendIndented("default");
			}
			else
			{
				Formatter.AppendIndented("case ");
				caseLabel.Expression.AcceptVisitor(this);
			}
			Formatter.Append(":");
		}

		public void VisitCastExpression(CastExpression castExpression)
		{
			ICSharpCode.Decompiler.IL.UnboxAny unbox = castExpression.Annotation<ICSharpCode.Decompiler.IL.UnboxAny>();
			ICSharpCode.Decompiler.IL.Box box = castExpression.Annotation<ICSharpCode.Decompiler.IL.Box>();
			IType toType = castExpression.Type.GetResolveResult().Type;
			if (toType.Kind == TypeKind.Unknown)
				toType = castExpression.GetResolveResult().Type;
			IType fromType = castExpression.Expression.GetResolveResult().Type;
			if (unbox != null)
			{
				UnBox(toType, castExpression.Expression);
			}
			else if (box != null)
			{
				Box(toType, castExpression.Expression);
			}
			else
				CastToType(toType, fromType, castExpression.Expression, unbox != null);
		}

		private void Box(IType toType, Expression expression)
		{
			if (IsPrimative(toType))
			{
				Formatter.Append("(new ");
				Formatter.Append(toType.Name);
				Formatter.Append("Value(");
				expression.AcceptVisitor(this);
				Formatter.Append("))");
			}
			else
			{
			}
		}

		private void UnBox(IType toType, Expression expression)
		{
			expression.AcceptVisitor(this);
			Formatter.Append("->get_As");
			Formatter.Append(toType.Name);
			Formatter.Append("()");
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
			IType type = composedType.GetResolveResult().Type;
			if (type.Kind == TypeKind.Array)
			{
				Formatter.Append("Array*");
				return;
			}
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
			WriteBlock(body);
		}

		private void WriteBlock(BlockStatement body)
		{
			Formatter.AddOpenBrace();
			InitializeFields();
			ArrayInitializerVisitor arrayVisitor = new ArrayInitializerVisitor(this, CurrentMethod);
			body.AcceptVisitor(arrayVisitor); // create array initializers
			WriteStatements(body);
			Formatter.AddCloseBrace();
		}

		private void WriteStatements(BlockStatement body)
		{
			foreach (var node in body.Statements)
			{
				Formatter.AppendIndented("");
				node.AcceptVisitor(this);
				if (!Formatter.IsOnNewline)
				{
					Formatter.AppendLine("");
				}
			}
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
			IType type = defaultValueExpression.GetResolveResult().Type;
			if (type.Kind == TypeKind.Class)
			{
				Formatter.Append("new ");
			}
			defaultValueExpression.Type.AcceptVisitor(this);
			Formatter.Append("()");
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
			//switch (directionExpression.FieldDirection)
			//{
			//	case FieldDirection.Out:
			//		Formatter.Append("out");
			//		break;
			//	case FieldDirection.Ref:
			//		Formatter.Append("ref");
			//		break;
			//	case FieldDirection.In:
			//		Formatter.Append("in");
			//		break;
			//	default:
			//		throw new NotSupportedException("Invalid value for FieldDirection");
			//}
			//Formatter.Append(" ");
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
			if (!(expressionStatement.Parent is ForStatement))
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
			IType type = foreachStatement.InExpression.GetResolveResult().Type;
			if (type.Kind == TypeKind.Array)
			{
				WriteForeachArray(foreachStatement);
			}
			else
			{
				WriteForeachEnumerable(foreachStatement);
			}
		}

		private void WriteForeachArray(ForeachStatement foreachStatement)
		{
			Formatter.Append("for ( Int32 foreachi = 0; foreachi < ");
			foreachStatement.InExpression.AcceptVisitor(this);
			Formatter.Append("->GetLength(0) ; ++foreachi ) ");
			Formatter.AddOpenBrace();
			Formatter.AppendIndented("");
			foreachStatement.VariableType.AcceptVisitor(this);
			Formatter.Append(" ");
			WriteVariableName(foreachStatement.VariableNameToken);
			Formatter.Append(" = ");
			FormatInExpression(foreachStatement);
			Formatter.Append(";");
			if (foreachStatement.EmbeddedStatement is BlockStatement)
			{
				WriteStatements(foreachStatement.EmbeddedStatement as BlockStatement);
			}
			else
			{
				foreachStatement.EmbeddedStatement.AcceptVisitor(this);
			}
			Formatter.AddCloseBrace();
		}
		public void FormatInExpression(ForeachStatement foreachStatement)
		{
			IType target = foreachStatement.VariableType.GetResolveResult().Type;
			Formatter.Append("(");
			Formatter.Append("(*");
			Formatter.Append("(");
			Formatter.Append("(");
			Formatter.AppendName(target.Name);
			Formatter.Append("*)");
			foreachStatement.InExpression.AcceptVisitor(this);
			Formatter.Append("->Address(foreachi)");
			Formatter.Append(")");
			Formatter.Append(")");
			Formatter.Append(")");
		}
		private void WriteForeachEnumerable(ForeachStatement foreachStatement)
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
			Formatter.AppendName(nameIdentifier.Name);
		}

		protected virtual void WriteEmbeddedStatement(Statement embeddedStatement)
		{
			Formatter.AppendLine("");
			BlockStatement block = embeddedStatement as BlockStatement;
			if (block != null)
			{
				WriteBlock(block);
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
			Formatter.AppendName(identifier.Name);
		}

		public void VisitIdentifierExpression(IdentifierExpression identifierExpression)
		{
			ICSharpCode.Decompiler.IL.Box inst = identifierExpression.Annotation<ICSharpCode.Decompiler.IL.Box>();
			if (inst != null)
			{
				Formatter.Append("new ");
				Formatter.AppendType(inst.Type.Name);
				Formatter.Append("Value(");
			}
			Formatter.AppendName(identifierExpression.IdentifierToken.Name);
			if (inst != null)
			{
				Formatter.Append(")");
			}
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
				Formatter.AppendIndented("else");
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
			ArrayType target = indexerExpression.Target.GetResolveResult().Type as ArrayType;
			String typeName = "Char";
			if (target != null)
				typeName = target.ElementType.Name;
			Formatter.Append("(");
			Formatter.Append("(*");
			Formatter.Append("(");
			Formatter.Append("(");
			Formatter.AppendName(typeName);
			if (typeName == "Object" || typeName == "String")
				Formatter.Append("*");
			Formatter.Append("*)");
			indexerExpression.Target.AcceptVisitor(this);
			Formatter.Append("->Address(");
			WriteCommaSeparatedList(indexerExpression.Arguments);
			Formatter.Append(")");
			Formatter.Append(")");
			Formatter.Append(")");
			Formatter.Append(")");
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
			CurrentExpression = invocationExpression;
			ICSharpCode.Decompiler.IL.ILInstruction inst = invocationExpression.Annotation<ICSharpCode.Decompiler.IL.ILInstruction>();
			inst.AcceptVisitor(CallVisitor);
			//			invocationExpression.Target.AcceptVisitor(this);
			WriteCommaSeparatedListInParenthesis(invocationExpression.Arguments);
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
			if (HandleLengthProperty(memberReferenceExpression))
			{
				return;
			}
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
			var skind = sym == null ? SymbolKind.None : sym.SymbolKind;
			if (skind != SymbolKind.Property && type.Kind == TypeKind.Enum)
			{
				HandleEnumExpression(type, sym);
				return;
			}
			IType targetType = memberReferenceExpression.Target.GetResolveResult().Type;
			if (HandleConstants(memberReferenceExpression.Target.ToString(), memberReferenceExpression.MemberNameToken.Name, targetType))
			{
				if (targetType.Kind != TypeKind.Unknown)
				{
					Formatter.Append(")");
				}
				return;
			}
			memberReferenceExpression.Target.AcceptVisitor(this);
			var sym2 = memberReferenceExpression.Target.GetSymbol() as IEntity;
			if (sym != null && sym.IsStatic)
			{
				if (IsPrimative(targetType))
					Formatter.Append("Value");
				Formatter.Append("::");
			}
			else
			{
				TypeKind kind = targetType.Kind;
				if (kind == TypeKind.Unknown)
				{
					kind = type.Kind;
				}
				if (kind == TypeKind.Struct)
				{
					Formatter.Append(".");
				}
				else
				{
					Formatter.Append("->");
				}
			}
			HandleMemberName(memberReferenceExpression);
		}

		private bool HandleLengthProperty(MemberReferenceExpression memberReferenceExpression)
		{
			ICSharpCode.Decompiler.IL.ILInstruction inst = memberReferenceExpression.Annotation<ICSharpCode.Decompiler.IL.ILInstruction>();
			if (inst != null && (inst is ICSharpCode.Decompiler.IL.LdLen))
			{
				memberReferenceExpression.Target.AcceptVisitor(this);
				Formatter.Append("->get_Length()");
				return (true);
			}
			ICSharpCode.Decompiler.IL.CallVirt call = inst as ICSharpCode.Decompiler.IL.CallVirt;
			return (false);
		}

		private void HandleMemberName(MemberReferenceExpression memberReferenceExpression)
		{
			if (IsArrayLength(memberReferenceExpression))
			{
				Formatter.Append("GetLength(0)");
				return;
			}
			if (IsProperty(memberReferenceExpression))
			{
				FormatProperty(memberReferenceExpression);
				return;
			}
			Formatter.AppendName(memberReferenceExpression.MemberNameToken.Name);
		}

		private void FormatProperty(MemberReferenceExpression memberReferenceExpression)
		{
			if (IsGetProperty(memberReferenceExpression))
			{
				Formatter.Append("get_");
				Formatter.AppendName(memberReferenceExpression.MemberNameToken.Name);
				Formatter.Append("()");
			}
			else
			{
				Formatter.Append("set_");
				Formatter.AppendName(memberReferenceExpression.MemberNameToken.Name);
			}
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

		private bool IsArrayLength(MemberReferenceExpression memberReferenceExpression)
		{
			ICSharpCode.Decompiler.IL.ILInstruction inst = memberReferenceExpression.Annotation<ICSharpCode.Decompiler.IL.ILInstruction>();
			return (inst != null && inst is ICSharpCode.Decompiler.IL.LdLen);
		}

		private bool HandleConstants(String instance, String field, IType targetType)
		{
			//String key = instance + field;
			//if (substitutes.ContainsKey(key))
			//{
			//	CastToType(targetType, substitutes[key]);
			//	return (true);
			//}
			return (false);
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
			if (methodDeclaration.Body.IsNull)
			{
				return;
			}
			Formatter.AppendIndented("");
			if (methodDeclaration.NameToken.Name == "BooleanOperatorTests")
			{
				Formatter.Append("");
			}
			IType type = methodDeclaration.ReturnType.GetResolveResult().Type;
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
			Formatter.Append(" operator ");
			Formatter.Append(OperatorDeclaration.GetToken(operatorDeclaration.OperatorType));
			WriteCommaSeparatedListInParenthesis(operatorDeclaration.Parameters);
			WriteBlock(operatorDeclaration.Body);
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
				propertyDeclaration.Getter.AcceptVisitor(this);
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
				propertyDeclaration.Setter.AcceptVisitor(this);
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
			WriteBlock(constructorDeclaration.Body);
			DoingConstructor = false;
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
			IType type = variableInitializer.GetResolveResult().Type;
			CastToType(type, variableInitializer.Initializer);
			//			variableInitializer.Initializer.AcceptVisitor(this);
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
