using ICSharpCode.Decompiler.IL;
using ICSharpCode.Decompiler.IL.Patterns;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace CppTranslator
{
	class MyIlInstructionVisitor : ILVisitor<ILInstruction>
	{

		private Stack<Dictionary<String, String>> localVariable = new Stack<Dictionary<String, String>>();
		public Stack<String> leaveBlocks = new Stack<String>();
		public Dictionary<String, String> CurrentVariables { get; set; }
		public Formatter Formatter { get; set; }
		public IType MethodReturnType { get; set; }
		public Dictionary<String, String> variableTranslation = new Dictionary<String, String>();
		public Dictionary<String, String> specialCallNames = new Dictionary<String, String>();
		public Dictionary<String, String> constantConversions = new Dictionary<String, String>();
		public Dictionary<BinaryNumericOperator, String> operatorSymbols = new Dictionary<BinaryNumericOperator, String>();
		public Dictionary<ComparisonKind, String> comparisonSymbols = new Dictionary<ComparisonKind, String>();
		internal BlockContainer currentReturnContainer;
		internal BlockContainer mainContainer;
		internal int blockIndex;

		public MyIlInstructionVisitor(Formatter formatter)
		{
			Formatter = formatter;
			CurrentVariables = new Dictionary<string, string>();

			specialCallNames.Add(".ctor", "");
			specialCallNames.Add("op_Equality", "Equals");

			operatorSymbols.Add(BinaryNumericOperator.Add, " + ");
			operatorSymbols.Add(BinaryNumericOperator.Sub, " - ");
			operatorSymbols.Add(BinaryNumericOperator.Mul, " * ");
			operatorSymbols.Add(BinaryNumericOperator.Div, " / ");
			operatorSymbols.Add(BinaryNumericOperator.Rem, " % ");
			operatorSymbols.Add(BinaryNumericOperator.BitAnd, " & ");
			operatorSymbols.Add(BinaryNumericOperator.BitOr, " | ");
			operatorSymbols.Add(BinaryNumericOperator.BitXor, " ^ ");
			operatorSymbols.Add(BinaryNumericOperator.ShiftLeft, " << ");
			operatorSymbols.Add(BinaryNumericOperator.ShiftRight, " >> ");

			comparisonSymbols.Add(ComparisonKind.Equality, " == ");
			comparisonSymbols.Add(ComparisonKind.Inequality, " != ");
			comparisonSymbols.Add(ComparisonKind.LessThan, " < ");
			comparisonSymbols.Add(ComparisonKind.LessThanOrEqual, " <= ");
			comparisonSymbols.Add(ComparisonKind.GreaterThan, " > ");
			comparisonSymbols.Add(ComparisonKind.GreaterThanOrEqual, " >= ");

			constantConversions.Add(Byte.MaxValue.ToString(), "ByteValue::MaxValue");
			constantConversions.Add(SByte.MaxValue.ToString(), "SByteValue::MaxValue");
			constantConversions.Add(Int16.MaxValue.ToString(), "Int16Value::MaxValue");
			constantConversions.Add(Int32.MaxValue.ToString(), "Int32Value::MaxValue");
			constantConversions.Add(Int64.MaxValue.ToString(), "Int64Value::MaxValue");
			constantConversions.Add(UInt16.MaxValue.ToString(), "UInt16Value::MaxValue");
			constantConversions.Add(UInt32.MaxValue.ToString(), "UInt32Value::MaxValue");
			constantConversions.Add(UInt64.MaxValue.ToString(), "UInt64Value::MaxValue");
			constantConversions.Add(Single.MaxValue.ToString(), "SingleValue::MaxValue");
			constantConversions.Add(Double.MaxValue.ToString(), "DoubleValue::MaxValue");

			//            constantConversions.Add("0", "Int32Value::MinValue");
			constantConversions.Add(SByte.MinValue.ToString(), "SByteValue::MinValue");
			constantConversions.Add(Int16.MinValue.ToString(), "Int16Value::MinValue");
			constantConversions.Add(Int32.MinValue.ToString(), "Int32Value::MinValue");
			constantConversions.Add(Int64.MinValue.ToString(), "Int64Value::MinValue");
			constantConversions.Add(Single.MinValue.ToString(), "SingleValue::MinValue");
			constantConversions.Add(Double.MinValue.ToString(), "DoubleValue::MinValue");

			constantConversions.Add("NaN", "DoubleValue::NaN");
			constantConversions.Add(Double.PositiveInfinity.ToString(), "DoubleValue::PositiveInfinity");
			constantConversions.Add(Double.NegativeInfinity.ToString(), "DoubleValue::NegativeInfinity");

		}
		internal bool IsPrimative(IType type)
		{
			if (type.Name == "Boolean" || type.Name == "DateTime" || type.Name == "TimeSpan")
				return (true);
			PrimitiveType pt = type.ToPrimitiveType();
			switch (pt)
			{
				case PrimitiveType.I1:
				case PrimitiveType.I2:
				case PrimitiveType.I4:
				case PrimitiveType.I8:
				case PrimitiveType.R4:
				case PrimitiveType.R8:
				case PrimitiveType.U1:
				case PrimitiveType.U2:
				case PrimitiveType.U4:
				case PrimitiveType.U8:
					return (true);
				default:
					return (false);
			}
		}
		internal bool IsPointerType(IType type)
		{
			if (type.Kind == TypeKind.ByReference)
			{
				return (true);
			}
			return (type.Kind == TypeKind.Class || type.Kind == TypeKind.Array);
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
				name = "Array";
			}
			Formatter.AppendName(name);
		}
		private void FormatMethodAccessType(IMethod method, IType type, String methodName)
		{
			if (method.IsStatic)
				Formatter.Append("::");
			else
				FormatTypeAccess(type);
			Formatter.Append(methodName);
		}
		public void FormatTypeAccess(IType type)
		{
			if (type == null || IsPointerType(type))
				Formatter.Append("->");
			else
				Formatter.Append(".");
		}
		IType GetTypeForInstruction(ILInstruction inst, IType defaultType)
		{
			if (inst is LdLoc)
				return (((LdLoc)inst).Variable.Type);
			else if (inst is LdLoca)
				return (((LdLoca)inst).Variable.Type);
			else if (inst is LdObj)
				return (((LdObj)inst).Type);
			else if (inst is LdFlda)
				return (((LdFlda)inst).Field.Type);
			else if (inst is LdElema)
				return (((LdElema)inst).Type);
			else if (inst is AddressOf)
				return (((AddressOf)inst).Type);
			return (defaultType);
		}
		private void HandleFieldAccess(ILInstruction target)
		{
			target.AcceptVisitor(this);
			IType type = GetTypeForInstruction(target, null);
			FormatTypeAccess(type);
		}
		private void BoxExpression(IType type, ILInstruction inst)
		{
			WrapTypeIfNeeded(type);
			Formatter.Append("(");
			inst.AcceptVisitor(this);
			Formatter.Append(")");
		}

		private void WrapTypeIfNeeded(IType type)
		{
			FormatType(type);
			if (IsPrimative(type))
				Formatter.Append("Value");
		}

		protected override ILInstruction Default(ILInstruction inst)
		{
			return (inst);
		}

		protected override ILInstruction VisitAddressOf(AddressOf inst)
		{
			Formatter.Append("(");
			inst.Value.AcceptVisitor(this);
			Formatter.Append(")");
			return base.VisitAddressOf(inst);
		}

		protected override ILInstruction VisitArglist(Arglist inst)
		{
			return base.VisitArglist(inst);
		}

		protected override ILInstruction VisitAwait(Await inst)
		{
			return base.VisitAwait(inst);
		}

		protected override ILInstruction VisitBinaryNumericInstruction(BinaryNumericInstruction inst)
		{
			if (HandleSpecialModulusWithFLoatingNumbers(inst))
				return base.VisitBinaryNumericInstruction(inst);
			Formatter.Append("(");
			inst.Left.AcceptVisitor(this);
			Formatter.Append(operatorSymbols[inst.Operator]);
			inst.Right.AcceptVisitor(this);
			Formatter.Append(")");
			return base.VisitBinaryNumericInstruction(inst);
		}

		private bool HandleSpecialModulusWithFLoatingNumbers(BinaryNumericInstruction inst)
		{
			if (inst.Operator != BinaryNumericOperator.Rem)
				return (false);
			if (inst.UnderlyingResultType != StackType.F4 && inst.UnderlyingResultType != StackType.F8)
				return (false);
			Formatter.Append("DoubleValue::Modulus(");
			inst.Left.AcceptVisitor(this);
			Formatter.Append(",");
			inst.Right.AcceptVisitor(this);
			Formatter.Append(")");
			return (true);
		}

		protected override ILInstruction VisitBitNot(BitNot inst)
		{
			Formatter.Append("~");
			inst.Argument.AcceptVisitor(this);
			return base.VisitBitNot(inst);
		}

		protected override ILInstruction VisitBlock(Block block)
		{
			WriteBlock(block);
			return base.VisitBlock(block);
		}

		private void NewLeaveBlock()
		{
			++blockIndex;
			leaveBlocks.Push("leaveBlock" + blockIndex);
		}
		private String CurrentLeaveBlock()
		{
			return (leaveBlocks.Peek());
		}
		private void ExitLeaveBLock()
		{
			leaveBlocks.Pop();
		}
		internal void StartMainBlock(BlockContainer container)
		{
			mainContainer = container;
			InitilizeLocalVariableNames(container.Parent as ILFunction);
			variableTranslation.Clear();
			blockIndex = 0;
			container.AcceptVisitor(this);
		}

		private void InitilizeLocalVariableNames(ILFunction ilFunction)
		{
			IMethod method = ilFunction.Method;
			CurrentVariables.Clear();
			foreach (IParameter parameter in method.Parameters)
			{
				CurrentVariables.Add(parameter.Name, parameter.Name);
			}
		}

		protected override ILInstruction VisitBlockContainer(BlockContainer container)
		{
			currentReturnContainer = container;
			NewLeaveBlock();
			foreach (Block block in container.Blocks)
			{
				Formatter.AddOpenBrace();
				WriteBlock(block);
				Formatter.AddCloseBrace();
			}
			if (container != mainContainer && container.LeaveCount > 0)
			{
				Formatter.Append(CurrentLeaveBlock());
				Formatter.AppendLine(":");
			}
			ExitLeaveBLock();
			return (null);
		}

		private void WriteBlock(Block block)
		{
			AddLableIfNeeded(block);
			if (block.Kind == BlockKind.ArrayInitializer)
			{
				HandleInitilzedArray(block);
				return;
			}
			foreach (ILInstruction inst in block.Instructions)
			{
				if (Formatter.IsOnNewline)
					Formatter.AppendIndented("");
				String st = inst.ToString();
				inst.AcceptVisitor(this);
				if (Formatter.CharactersAddedToLine)
					Formatter.Append(";");
				Formatter.AppendLine("");
			}
		}

		private void AddLableIfNeeded(Block block)
		{
			ICSharpCode.Decompiler.IL.Leave leave = block.Instructions.FirstOrDefault() as ICSharpCode.Decompiler.IL.Leave;
			if (block.Instructions.Count == 1 && leave != null)
				return;
			if (Formatter.IsOnNewline)
			{
				Formatter.Append(block.Label);
				Formatter.AppendLine(":");
			}
		}

		protected override ILInstruction VisitBox(Box inst)
		{
			Formatter.Append("(new ");
			BoxExpression(inst.Type, inst.Argument);
			Formatter.Append(")");
			return base.VisitBox(inst);
		}

		protected override ILInstruction VisitBranch(Branch inst)
		{
			Formatter.Append("goto ");
			Formatter.Append(inst.TargetLabel);
			return base.VisitBranch(inst);
		}

		protected override ILInstruction VisitCall(Call inst)
		{
			FormatCall(inst);
			return base.VisitCall(inst);
		}

		protected override ILInstruction VisitCallVirt(CallVirt inst)
		{
			FormatCall(inst);
			return base.VisitCallVirt(inst);
		}

		private void FormatCall(CallInstruction inst)
		{
			if (HandleSpecialCalls(inst))
				return;
			String methodName = GetMethodName(inst.Method.Name);
			if (String.IsNullOrEmpty(methodName))
				return;
			var arg = inst.Arguments.FirstOrDefault();
			bool skipFirstParameter = false;
			if (inst.IsInstanceCall)
			{
				FormatCallInstance(arg);
				skipFirstParameter = true;
				FormatMethodAccessType(inst.Method, arg, methodName);
			}
			else
			{
				if (inst.Method.IsStatic)
					WrapTypeIfNeeded(inst.Method.DeclaringType);
				FormatMethodAccessType(inst.Method, inst.Method.DeclaringType, methodName);
			}
			AddCallParameters(inst.Arguments, inst.Method, skipFirstParameter);
		}

		private bool HandleSpecialCalls(CallInstruction inst)
		{
			if (HandleStringConcat(inst))
				return (true);
			return (false);
		}

		private bool HandleStringConcat(CallInstruction inst)
		{
			if (inst.Method.FullName != "System.String.Concat")
				return (false);
			Block block = inst.Arguments.FirstOrDefault() as Block;
			if (block == null && inst.Arguments.Count < 2)
				return (false);
			Formatter.Append("String::Concat(");
			if (block != null)
			{
				HandleConcatBlock(inst, block);
			}
			else
			{
				bool first = true;
				foreach (ILInstruction parameter in inst.Arguments)
				{
					if (!first)
						Formatter.Append(", ");
					first = false;
					parameter.AcceptVisitor(this);
				}
			}
			Formatter.Append(")");
			return (true);
		}

		private void HandleConcatBlock(CallInstruction inst, Block block)
		{
			bool first = true;
			foreach (ILInstruction element in block.Instructions)
			{
				if (element is StLoc)
					continue;
				ILInstruction todo = ((StObj)element).Value;
				if (!first)
					Formatter.Append(", ");
				first = false;
				todo.AcceptVisitor(this);
			}
		}

		private void FormatCallInstance(ILInstruction arg)
		{
			IType type = GetTypeForInstruction(arg, null);
			if (type != null && IsPrimative(type))
			{
				BoxExpression(type, arg);
				return;
			}
			arg.AcceptVisitor(this);
		}

		private bool IsConstant(ILInstruction value)
		{
			return (value is LdcF4 || value is LdcF8 || value is LdcI4 || value is LdcI8);
		}

		private void FormatMethodAccessType(IMethod method, ILInstruction inst, String methodName)
		{
			IType type = GetTypeForInstruction(inst, null);
			FormatMethodAccessType(method, type, methodName);
		}
		private string GetMethodName(String methodName)
		{
			if (specialCallNames.ContainsKey(methodName))
			{
				return (specialCallNames[methodName]);
			}
			return (methodName);
		}

		private void AddCallParameters(InstructionCollection<ILInstruction> arguments, IMethod method, bool hasThis)
		{
			InstructionCollection<ILInstruction>.Enumerator walker = arguments.GetEnumerator();
			if (hasThis)
				walker.MoveNext();
			bool first = true;
			Formatter.Append("(");
			int paramterIndex = -1;
			while (walker.MoveNext())
			{
				++paramterIndex;
				if (!first)
					Formatter.Append(", ");
				ILInstruction inst = walker.Current;
				DoCastOnCallParamterIfNeeded(method.Parameters[paramterIndex]);
				inst.AcceptVisitor(this);
				first = false;
			}
			Formatter.Append(")");
		}

		private void DoCastOnCallParamterIfNeeded(IParameter parameter)
		{
			if (parameter.Type.Kind != TypeKind.Enum)
				return;
			Formatter.Append("(");
			FormatTypeDelaration(parameter.Type);
			Formatter.Append(")");
		}

		protected override ILInstruction VisitCallIndirect(CallIndirect inst)
		{
			return base.VisitCallIndirect(inst);
		}

		protected override ILInstruction VisitCastClass(CastClass inst)
		{
			return base.VisitCastClass(inst);
		}

		protected override ILInstruction VisitCkfinite(Ckfinite inst)
		{
			return base.VisitCkfinite(inst);
		}

		protected override ILInstruction VisitComp(Comp inst)
		{
			Formatter.Append("(");
			inst.Left.AcceptVisitor(this);
			Formatter.Append(comparisonSymbols[inst.Kind]);
			inst.Right.AcceptVisitor(this);
			Formatter.Append(")");
			return base.VisitComp(inst);
		}

		protected override ILInstruction VisitConv(Conv inst)
		{
			inst.Argument.AcceptVisitor(this);
			return base.VisitConv(inst);
		}

		protected override ILInstruction VisitCpblk(Cpblk inst)
		{
			return base.VisitCpblk(inst);
		}

		protected override ILInstruction VisitDebugBreak(DebugBreak inst)
		{
			return base.VisitDebugBreak(inst);
		}

		protected override ILInstruction VisitDefaultValue(DefaultValue inst)
		{
			if (inst.Type.Kind == TypeKind.Class)
				Formatter.Append("new ");
			FormatType(inst.Type);
			Formatter.Append("()");
			return base.VisitDefaultValue(inst);
		}

		protected override ILInstruction VisitDynamicBinaryOperatorInstruction(DynamicBinaryOperatorInstruction inst)
		{
			return base.VisitDynamicBinaryOperatorInstruction(inst);
		}

		protected override ILInstruction VisitDynamicCompoundAssign(DynamicCompoundAssign inst)
		{
			return base.VisitDynamicCompoundAssign(inst);
		}

		protected override ILInstruction VisitDynamicConvertInstruction(DynamicConvertInstruction inst)
		{
			return base.VisitDynamicConvertInstruction(inst);
		}

		protected override ILInstruction VisitDynamicGetIndexInstruction(DynamicGetIndexInstruction inst)
		{
			return base.VisitDynamicGetIndexInstruction(inst);
		}

		protected override ILInstruction VisitDynamicGetMemberInstruction(DynamicGetMemberInstruction inst)
		{
			return base.VisitDynamicGetMemberInstruction(inst);
		}

		protected override ILInstruction VisitDynamicInvokeConstructorInstruction(DynamicInvokeConstructorInstruction inst)
		{
			return base.VisitDynamicInvokeConstructorInstruction(inst);
		}

		protected override ILInstruction VisitDynamicInvokeInstruction(DynamicInvokeInstruction inst)
		{
			return base.VisitDynamicInvokeInstruction(inst);
		}

		protected override ILInstruction VisitDynamicInvokeMemberInstruction(DynamicInvokeMemberInstruction inst)
		{
			return base.VisitDynamicInvokeMemberInstruction(inst);
		}

		protected override ILInstruction VisitDynamicIsEventInstruction(DynamicIsEventInstruction inst)
		{
			return base.VisitDynamicIsEventInstruction(inst);
		}

		protected override ILInstruction VisitDynamicLogicOperatorInstruction(DynamicLogicOperatorInstruction inst)
		{
			return base.VisitDynamicLogicOperatorInstruction(inst);
		}

		protected override ILInstruction VisitDynamicSetIndexInstruction(DynamicSetIndexInstruction inst)
		{
			return base.VisitDynamicSetIndexInstruction(inst);
		}

		protected override ILInstruction VisitDynamicSetMemberInstruction(DynamicSetMemberInstruction inst)
		{
			return base.VisitDynamicSetMemberInstruction(inst);
		}

		protected override ILInstruction VisitDynamicUnaryOperatorInstruction(DynamicUnaryOperatorInstruction inst)
		{
			return base.VisitDynamicUnaryOperatorInstruction(inst);
		}

		protected override ILInstruction VisitExpressionTreeCast(ExpressionTreeCast inst)
		{
			return base.VisitExpressionTreeCast(inst);
		}

		protected override ILInstruction VisitGetPinnableReference(GetPinnableReference inst)
		{
			return base.VisitGetPinnableReference(inst);
		}

		protected override ILInstruction VisitIfInstruction(IfInstruction inst)
		{
			bool justCondition = Formatter.CharactersAddedToLine;
			if (!justCondition)
				Formatter.Append("if ");
			Formatter.Append("(");
			BuildCondition(inst);
			Formatter.Append(")");
			if (!justCondition)
			{
				Formatter.AppendLine("");
				WriteBlockWithBraces(inst.TrueInst);
				if (!inst.FalseInst.MatchNop())
				{
					Formatter.AppendIndentedLine("else");
					WriteBlockWithBraces(inst.FalseInst);
				}
			}
			return base.VisitIfInstruction(inst);
		}

		private void BuildCondition(IfInstruction inst)
		{
			bool wasIf = false;
			if (inst.Condition is IfInstruction)
			{
				wasIf = true;
				BuildCondition(inst.Condition as IfInstruction);
			}
			if (!wasIf)
			{
				inst.Condition.AcceptVisitor(this);
			}
			bool leftIsConstant = IsConstant(inst.TrueInst);
			int leftConstant = GetAsIntConstant(inst.TrueInst);
			bool rightIsConstant = IsConstant(inst.FalseInst);
			int rightConstant = GetAsIntConstant(inst.FalseInst);
			String logicalOpertor = null;
			if (rightIsConstant)
			{
				if (rightConstant == 1)
					logicalOpertor = " || ";
				else
					logicalOpertor = " && ";
				Formatter.Append(logicalOpertor);
				inst.TrueInst.AcceptVisitor(this);

			}
			else if (leftIsConstant)
			{
				if (leftConstant == 1)
					logicalOpertor = " || ";
				else
					logicalOpertor = " && ";
				Formatter.Append(logicalOpertor);
				inst.FalseInst.AcceptVisitor(this);
			}
		}

		private int GetAsIntConstant(ILInstruction inst)
		{
			if (inst is LdcI4)
				return (((LdcI4)inst).Value);
			return (-1);
		}

		private void WriteBlockWithBraces(ILInstruction trueInst)
		{
			Formatter.AddOpenBrace();
			Formatter.AppendIndented("");
			trueInst.AcceptVisitor(this);
			ICSharpCode.Decompiler.IL.Block block = trueInst as ICSharpCode.Decompiler.IL.Block;
			if (block == null)
				Formatter.Append(";");
			Formatter.AddCloseBrace();
		}

		protected override ILInstruction VisitILFunction(ILFunction function)
		{
			return base.VisitILFunction(function);
		}

		protected override ILInstruction VisitInitblk(Initblk inst)
		{
			return base.VisitInitblk(inst);
		}

		protected override ILInstruction VisitInvalidBranch(InvalidBranch inst)
		{
			return base.VisitInvalidBranch(inst);
		}

		protected override ILInstruction VisitInvalidExpression(InvalidExpression inst)
		{
			return base.VisitInvalidExpression(inst);
		}

		protected override ILInstruction VisitIsInst(IsInst inst)
		{
			return base.VisitIsInst(inst);
		}

		protected override ILInstruction VisitLdcDecimal(LdcDecimal inst)
		{
			return base.VisitLdcDecimal(inst);
		}

		protected override ILInstruction VisitLdcF4(LdcF4 inst)
		{
			String value = inst.Value.ToString();
			if (!ConvertConstants(value))
			{
				if (value.Contains("."))
					Formatter.Append("F");
			}
			return base.VisitLdcF4(inst);
		}

		protected override ILInstruction VisitLdcF8(LdcF8 inst)
		{
			ConvertConstants(inst.Value.ToString());
			return base.VisitLdcF8(inst);
		}

		protected override ILInstruction VisitLdcI4(LdcI4 inst)
		{
			ConvertConstants(inst.Value.ToString());
			return base.VisitLdcI4(inst);
		}

		private bool ConvertConstants(String v)
		{
			if (constantConversions.ContainsKey(v))
			{
				Formatter.Append(constantConversions[v]);
				return (true);
			}
			Formatter.Append(v);
			return (false);
		}

		protected override ILInstruction VisitLdcI8(LdcI8 inst)
		{
			ConvertConstants(inst.Value.ToString());
			return base.VisitLdcI8(inst);
		}

		protected override ILInstruction VisitLdElema(LdElema inst)
		{
			Formatter.Append("(*((");
			FormatTypeDelaration(inst.Type);
			Formatter.Append("*)");
			inst.Array.AcceptVisitor(this);
			Formatter.Append("->Address(");
			WriteCommaSeparatedList(inst.Indices);
			Formatter.Append(")))");
			return base.VisitLdElema(inst);
		}

		protected override ILInstruction VisitLdFlda(LdFlda inst)
		{
			HandleFieldAccess(inst.Target);
			String name = inst.Field.Name;
			name = ReplaceSpecial(name);
			Formatter.AppendName(name);
			return base.VisitLdFlda(inst);
		}

		private static String ReplaceSpecial(String name)
		{
			if (name.StartsWith("<"))
			{
				name = name.Replace("<", "");
				name = name.Replace(">", "");
			}
			return name;
		}

		protected override ILInstruction VisitLdFtn(LdFtn inst)
		{
			return base.VisitLdFtn(inst);
		}

		protected override ILInstruction VisitLdLen(LdLen inst)
		{
			inst.Array.AcceptVisitor(this);
			Formatter.Append("->get_Length()");
			return base.VisitLdLen(inst);
		}

		protected override ILInstruction VisitLdLoc(LdLoc inst)
		{
			String name = inst.Variable.Name;
			if (variableTranslation.ContainsKey(name))
			{
				//ILInstruction ins = variableTranslation[name];
				//ins.AcceptVisitor(this);
				name = variableTranslation[name];
			}
			//			else
			Formatter.AppendName(name);
			return base.VisitLdLoc(inst);
		}

		protected override ILInstruction VisitLdLoca(LdLoca inst)
		{
			if (DeclareVariableIfNeeded(inst.Variable))
			{
				Formatter.AppendName(inst.Variable.Name);
				Formatter.AppendLine(";");
				Formatter.AppendIndented("");
			}
			Formatter.AppendName(inst.Variable.Name);
			return base.VisitLdLoca(inst);
		}

		protected override ILInstruction VisitLdMemberToken(LdMemberToken inst)
		{
			return base.VisitLdMemberToken(inst);
		}

		protected override ILInstruction VisitLdNull(LdNull inst)
		{
			Formatter.Append("nullptr");
			return base.VisitLdNull(inst);
		}

		protected override ILInstruction VisitLdObj(LdObj inst)
		{
			inst.Target.AcceptVisitor(this);
			return base.VisitLdObj(inst);
		}

		protected override ILInstruction VisitLdsFlda(LdsFlda inst)
		{
			WrapTypeIfNeeded(inst.Field.DeclaringType);
			Formatter.Append("::");
			Formatter.Append(inst.Field.Name);
			return base.VisitLdsFlda(inst);
		}

		protected override ILInstruction VisitLdStr(LdStr inst)
		{
			Formatter.Append("(new String(");
			Formatter.AppendStringsWithControl(inst.Value);
			Formatter.Append("))");
			return base.VisitLdStr(inst);
		}

		protected override ILInstruction VisitLdTypeToken(LdTypeToken inst)
		{
			return base.VisitLdTypeToken(inst);
		}

		protected override ILInstruction VisitLdVirtDelegate(LdVirtDelegate inst)
		{
			return base.VisitLdVirtDelegate(inst);
		}

		protected override ILInstruction VisitLdVirtFtn(LdVirtFtn inst)
		{
			return base.VisitLdVirtFtn(inst);
		}

		protected override ILInstruction VisitLeave(Leave inst)
		{
			if (inst.TargetLabel == "IL_0000")
			{
				Formatter.Append("return");
				if (!inst.Value.MatchNop())
				{
					Formatter.Append("(");
					Formatter.Append("(");
					FormatTypeDelaration(GetTypeForInstruction(inst.Value, MethodReturnType));
					Formatter.Append(")");
					inst.Value.AcceptVisitor(this);
					Formatter.Append(")");
				}
			}
			else
			{
				Formatter.Append("goto ");
				//				if (currentReturnContainer == inst.TargetContainer)
				Formatter.Append(CurrentLeaveBlock());
				//				else
				//					Formatter.Append(inst.TargetLabel);
			}
			return base.VisitLeave(inst);
		}

		protected override ILInstruction VisitLocAlloc(LocAlloc inst)
		{
			return base.VisitLocAlloc(inst);
		}

		protected override ILInstruction VisitLocAllocSpan(LocAllocSpan inst)
		{
			return base.VisitLocAllocSpan(inst);
		}

		protected override ILInstruction VisitLockInstruction(LockInstruction inst)
		{
			return base.VisitLockInstruction(inst);
		}

		protected override ILInstruction VisitMakeRefAny(MakeRefAny inst)
		{
			return base.VisitMakeRefAny(inst);
		}

		protected override ILInstruction VisitNewArr(NewArr inst)
		{
			Formatter.Append("new Array(");
			FormatType(inst.Type);
			Formatter.Append("Type,");
			WriteCommaSeparatedList(inst.Indices);
			Formatter.Append(")");
			return base.VisitNewArr(inst);
		}

		private void WriteCommaSeparatedList(InstructionCollection<ILInstruction> indices)
		{
			bool isFirst = true;
			foreach (ILInstruction node in indices)
			{
				if (!isFirst)
				{
					Formatter.Append(",");
				}
				node.AcceptVisitor(this);
				isFirst = false;
			}
		}

		protected override ILInstruction VisitNewObj(NewObj inst)
		{
			if (inst.Method.DeclaringType.Kind == TypeKind.Class)
				Formatter.Append("(new ");
			Formatter.Append(inst.Method.DeclaringType.Name);
			AddCallParameters(inst.Arguments, inst.Method, false);
			if (inst.Method.DeclaringType.Kind == TypeKind.Class)
				Formatter.Append(")");
			return base.VisitNewObj(inst);
		}

		protected override ILInstruction VisitNop(Nop inst)
		{
			return base.VisitNop(inst);
		}

		protected override ILInstruction VisitNullableRewrap(NullableRewrap inst)
		{
			return base.VisitNullableRewrap(inst);
		}

		protected override ILInstruction VisitNullableUnwrap(NullableUnwrap inst)
		{
			return base.VisitNullableUnwrap(inst);
		}

		protected override ILInstruction VisitNullCoalescingInstruction(NullCoalescingInstruction inst)
		{
			return base.VisitNullCoalescingInstruction(inst);
		}

		protected override ILInstruction VisitNumericCompoundAssign(NumericCompoundAssign inst)
		{
			inst.Target.AcceptVisitor(this);
			if (inst.Operator == BinaryNumericOperator.Add)
				Formatter.Append("++");
			else
				Formatter.Append("--");
			return base.VisitNumericCompoundAssign(inst);
		}

		protected override ILInstruction VisitPinnedRegion(PinnedRegion inst)
		{
			return base.VisitPinnedRegion(inst);
		}

		protected override ILInstruction VisitRefAnyType(RefAnyType inst)
		{
			return base.VisitRefAnyType(inst);
		}

		protected override ILInstruction VisitRefAnyValue(RefAnyValue inst)
		{
			return base.VisitRefAnyValue(inst);
		}

		protected override ILInstruction VisitRethrow(Rethrow inst)
		{
			return base.VisitRethrow(inst);
		}

		protected override ILInstruction VisitSizeOf(SizeOf inst)
		{
			return base.VisitSizeOf(inst);
		}

		protected override ILInstruction VisitStLoc(StLoc inst)
		{
			if (HandleIncrementAndDecrement(inst))
				return base.VisitStLoc(inst);

			DeclareVariableIfNeeded(inst.Variable);
			Formatter.AppendName(inst.Variable.Name);
			Formatter.Append(" = ");
			HandleStoreVariable(inst.Variable.Type, inst.Value);

			return base.VisitStLoc(inst);
		}

		private void HandleStoreVariable(IType type, ILInstruction inst)
		{
			if (type.Kind == TypeKind.Enum)
			{
				Formatter.Append("(");
				FormatTypeDelaration(type);
				Formatter.Append(")");
			}
			inst.AcceptVisitor(this);
		}

		private bool HandleIncrementAndDecrement(StLoc inst)
		{
			BinaryNumericInstruction bin = inst.Value as BinaryNumericInstruction;
			if (bin == null)
				return (false);
			ICSharpCode.Decompiler.IL.LdLoc ldLoc = bin.Left as ICSharpCode.Decompiler.IL.LdLoc;
			ICSharpCode.Decompiler.IL.LdcI4 ldci4 = bin.Right as ICSharpCode.Decompiler.IL.LdcI4;
			if (ldLoc == null || ldci4 == null || (bin.Operator != BinaryNumericOperator.Add && bin.Operator != BinaryNumericOperator.Sub))
				return (false);
			if (inst.Variable.Name != ldLoc.Variable.Name)
				return (false);
			if (ldci4.Value != 1)
				return (false);
			ICSharpCode.Decompiler.IL.StLoc parent = inst.Parent as ICSharpCode.Decompiler.IL.StLoc;
			String oper = bin.Operator == BinaryNumericOperator.Add ? "++" : "--";
			//			if (parent != null)
			Formatter.Append(oper);
			Formatter.AppendName(ldLoc.Variable.Name);
			//if (parent == null)
			//	Formatter.Append(oper);
			return (true);
		}

		private bool DeclareVariableIfNeeded(ILVariable variable)
		{
			if (CurrentVariables.ContainsKey(variable.Name))
				return (false);
			CurrentVariables.Add(variable.Name, variable.Name);
			FormatTypeDelaration(variable.Type);
			Formatter.Append(" ");
			return (true);
		}

		protected override ILInstruction VisitStObj(StObj inst)
		{
			inst.Target.AcceptVisitor(this);
			Formatter.Append(" = ");
			if (IsNewInitilizedArray(inst.Value))
				HandleInitializedArray(inst);
			else
				HandleStoreVariable(inst.Type, inst.Value);
			return base.VisitStObj(inst);
		}

		private bool IsNewInitilizedArray(ILInstruction inst)
		{
			if (!(inst is ICSharpCode.Decompiler.IL.Block))
				return (false);
			ILInstruction first = ((ICSharpCode.Decompiler.IL.Block)inst).Instructions.FirstOrDefault();
			if (first != null)
			{
				ICSharpCode.Decompiler.IL.StLoc stLoc = first as ICSharpCode.Decompiler.IL.StLoc;
				if (stLoc == null)
					return (false);
				ICSharpCode.Decompiler.IL.NewArr newArr = stLoc.Value as ICSharpCode.Decompiler.IL.NewArr;
				if (newArr == null)
					return (false);
				return (((ICSharpCode.Decompiler.IL.Block)inst).Instructions.Count > 1);
			}
			return (false);
		}

		private void HandleInitilzedArray(Block block)
		{
			var parent = block.Parent as StLoc;
			var stloc = block.Instructions.FirstOrDefault() as StLoc;
			IType type;
			stloc.Value.MatchNewArr(out type);
			var newArr = (NewArr)stloc.Value;
			if (parent == null)
				stloc.AcceptVisitor(this);
			else
				newArr.AcceptVisitor(this);
			if (parent != null && parent.Variable.Name != stloc.Variable.Name)
				AddTranslatedName(stloc.Variable.Name, parent.Variable.Name);
			InitializeElementsOfArray(block);
		}

		private void InitializeElementsOfArray(Block block)
		{
			Formatter.AppendLine(";");
			block.Instructions.GetEnumerator();
			InstructionCollection<ILInstruction>.Enumerator walker = block.Instructions.GetEnumerator();
			walker.MoveNext();
			Boolean first = true;
			while (walker.MoveNext())
			{
				if (!first)
					Formatter.AppendLine(";");
				ICSharpCode.Decompiler.IL.StObj store = walker.Current as ICSharpCode.Decompiler.IL.StObj;
				Formatter.AppendIndented("");
				store.AcceptVisitor(this);
				first = false;
			}
		}

		private void AddTranslatedName(String name1, String name2)
		{
			if (!variableTranslation.ContainsKey(name1))
			{
				variableTranslation.Add(name1, name2);
			}
		}

		private void HandleInitializedArray(StObj inst)
		{
			ICSharpCode.Decompiler.IL.Block block = (ICSharpCode.Decompiler.IL.Block)inst.Value;
			ICSharpCode.Decompiler.IL.StLoc stLoc = block.Instructions.FirstOrDefault() as ICSharpCode.Decompiler.IL.StLoc;
			ICSharpCode.Decompiler.IL.NewArr newArr = stLoc.Value as ICSharpCode.Decompiler.IL.NewArr;
			ICSharpCode.Decompiler.IL.LdFlda field = inst.Target as ICSharpCode.Decompiler.IL.LdFlda;
			if (field != null && !variableTranslation.ContainsKey(stLoc.Variable.Name))
			{
				AddTranslatedName(stLoc.Variable.Name, field.Field.Name);
				//				variableTranslation.Add(stLoc.Variable.Name, field.Field.Name);
			}
			newArr.AcceptVisitor(this);
			InitializeElementsOfArray(block);
		}

		protected override ILInstruction VisitStringToInt(StringToInt inst)
		{
			return base.VisitStringToInt(inst);
		}

		protected override ILInstruction VisitSwitchInstruction(SwitchInstruction inst)
		{
			Formatter.Append("switch(");
			inst.Value.AcceptVisitor(this);
			Formatter.Append(")");
			Formatter.AddOpenBrace();
			FormatSwitchCases(inst.Sections);
			Formatter.AddCloseBrace();
			return base.VisitSwitchInstruction(inst);
		}

		private void FormatSwitchCases(InstructionCollection<SwitchSection> sections)
		{
			foreach (SwitchSection section in sections)
			{
				foreach (long lbl in section.Labels.Values)
				{
					if (lbl == long.MinValue)
						Formatter.AppendIndented("default");
					else
					{
						Formatter.AppendIndented("case ");
						Formatter.Append(lbl.ToString());
					}
					break;
				}
				Formatter.AppendLine(":");
				Formatter.AppendIndented("");
				section.Body.AcceptVisitor(this);
				Formatter.AppendLine(";");
			}
		}

		protected override ILInstruction VisitSwitchSection(SwitchSection inst)
		{
			return base.VisitSwitchSection(inst);
		}

		protected override ILInstruction VisitThreeValuedBoolAnd(ThreeValuedBoolAnd inst)
		{
			return base.VisitThreeValuedBoolAnd(inst);
		}

		protected override ILInstruction VisitThreeValuedBoolOr(ThreeValuedBoolOr inst)
		{
			return base.VisitThreeValuedBoolOr(inst);
		}

		protected override ILInstruction VisitThrow(Throw inst)
		{
			return base.VisitThrow(inst);
		}

		protected override ILInstruction VisitTryCatch(TryCatch inst)
		{
			return base.VisitTryCatch(inst);
		}

		protected override ILInstruction VisitTryCatchHandler(TryCatchHandler inst)
		{
			return base.VisitTryCatchHandler(inst);
		}

		protected override ILInstruction VisitTryFault(TryFault inst)
		{
			return base.VisitTryFault(inst);
		}

		protected override ILInstruction VisitTryFinally(TryFinally inst)
		{
			return base.VisitTryFinally(inst);
		}

		protected override ILInstruction VisitUnbox(Unbox inst)
		{
			return base.VisitUnbox(inst);
		}

		protected override ILInstruction VisitUnboxAny(UnboxAny inst)
		{
			if (inst.Type.Name == "DateTime" || inst.Type.Name == "TimeSpan")
			{
				FormatType(inst.Type);
				Formatter.Append("(");
			}
			inst.Argument.AcceptVisitor(this);
			Formatter.Append("->get_As");
			FormatType(inst.Type);
			Formatter.Append("()");
			if (inst.Type.Name == "DateTime" || inst.Type.Name == "TimeSpan")
			{
				Formatter.Append(")");
			}
			return base.VisitUnboxAny(inst);
		}

		protected override ILInstruction VisitUserDefinedCompoundAssign(UserDefinedCompoundAssign inst)
		{
			inst.Target.AcceptVisitor(this);
			Formatter.Append(" = ");
			FormatType(inst.Method.DeclaringType);
			FormatMethodAccessType(inst.Method, inst.Method.DeclaringType, inst.Method.Name);
			Formatter.Append("(");
			inst.Target.AcceptVisitor(this);
			Formatter.Append(",");
			inst.Value.AcceptVisitor(this);
			Formatter.Append(")");
			return base.VisitUserDefinedCompoundAssign(inst);
		}

		protected override ILInstruction VisitUserDefinedLogicOperator(UserDefinedLogicOperator inst)
		{
			return base.VisitUserDefinedLogicOperator(inst);
		}

		protected override ILInstruction VisitUsingInstruction(UsingInstruction inst)
		{
			return base.VisitUsingInstruction(inst);
		}

		protected override ILInstruction VisitYieldReturn(YieldReturn inst)
		{
			return base.VisitYieldReturn(inst);
		}
		public String GetHiddenPropertyName(ICSharpCode.Decompiler.IL.BlockContainer blockContainer)
		{
			ICSharpCode.Decompiler.IL.Block block = blockContainer.Blocks.FirstOrDefault();
			foreach (ILInstruction inst in block.Instructions)
			{
				if (inst is ICSharpCode.Decompiler.IL.Leave)
				{
					ICSharpCode.Decompiler.IL.Leave leave = inst as ICSharpCode.Decompiler.IL.Leave;
					ICSharpCode.Decompiler.IL.LdObj ldobj = leave.Value as ICSharpCode.Decompiler.IL.LdObj;
					if (ldobj == null)
						return (null);
					ICSharpCode.Decompiler.IL.LdFlda ldFld = ldobj.Target as ICSharpCode.Decompiler.IL.LdFlda;
					if (ldFld != null)
					{
						if (ldFld.Field.Name.StartsWith("<"))
							return (ReplaceSpecial(ldFld.Field.Name));
					}
				}
			}
			return (null);
		}
	}
}
