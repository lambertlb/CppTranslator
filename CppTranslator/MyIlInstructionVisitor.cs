// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sub-license, and/or sell copies of the Software, and to permit persons
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
using System;
using System.Collections.Generic;
using ICSharpCode.Decompiler.IL;
using ICSharpCode.Decompiler.TypeSystem;

namespace CppTranslator
{
	/// <summary>
	/// IlInstruction visitor for output in IL code as C++
	/// </summary>
	public class MyIlInstructionVisitor : ILVisitor<ILInstruction>
	{
		private Stack<String> leaveBlocks = new Stack<String>();
		private Dictionary<String, String> CurrentVariables { get; set; }
		private Dictionary<String, String> variableTranslation = new Dictionary<String, String>();
		private Dictionary<String, String> specialCallNames = new Dictionary<String, String>();
		private Dictionary<String, String> constantConversions = new Dictionary<String, String>();
		private Dictionary<BinaryNumericOperator, String> operatorSymbols = new Dictionary<BinaryNumericOperator, String>();
		private Dictionary<ComparisonKind, String> comparisonSymbols = new Dictionary<ComparisonKind, String>();
		private BlockContainer currentReturnContainer;
		private BlockContainer mainContainer;
		private int blockIndex;
		/// <summary>
		/// Output formatter
		/// </summary>
		public Formatter Formatter { get; set; }
		/// <summary>
		/// Method return type
		/// </summary>
		public IType MethodReturnType { get; set; }
		/// <summary>
		/// Injection string for static constructor
		/// </summary>
		public String Injection { get; set; }
		/// <summary>
		/// visitor used for type definition
		/// </summary>
		public CppTypeVisitor TypeVisitor { get; set; }
		/// <summary>
		/// Initializes a new instance of the <see cref="MyIlInstructionVisitor"/> class.
		/// Constructor
		/// </summary>
		/// <param name="formatter">for output </param>
		public MyIlInstructionVisitor(Formatter formatter)
		{
			Formatter = formatter;
			CurrentVariables = new Dictionary<string, string>();

			specialCallNames.Add(".ctor", String.Empty);
			specialCallNames.Add("op_Equality", "Equals");

			operatorSymbols.Add(BinaryNumericOperator.Add, "+");
			operatorSymbols.Add(BinaryNumericOperator.Sub, "-");
			operatorSymbols.Add(BinaryNumericOperator.Mul, "*");
			operatorSymbols.Add(BinaryNumericOperator.Div, "/");
			operatorSymbols.Add(BinaryNumericOperator.Rem, "%");
			operatorSymbols.Add(BinaryNumericOperator.BitAnd, "&");
			operatorSymbols.Add(BinaryNumericOperator.BitOr, "|");
			operatorSymbols.Add(BinaryNumericOperator.BitXor, "^");
			operatorSymbols.Add(BinaryNumericOperator.ShiftLeft, "<<");
			operatorSymbols.Add(BinaryNumericOperator.ShiftRight, ">>");

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

			constantConversions.Add(SByte.MinValue.ToString(), "SByteValue::MinValue");
			constantConversions.Add(Int16.MinValue.ToString(), "Int16Value::MinValue");
			constantConversions.Add(Int32.MinValue.ToString(), "Int32Value::MinValue");
			constantConversions.Add(Int64.MinValue.ToString(), "Int64Value::MinValue");
			constantConversions.Add(Single.MinValue.ToString(), "SingleValue::MinValue");
			constantConversions.Add(Double.MinValue.ToString(), "DoubleValue::MinValue");

			constantConversions.Add("NaN", "DoubleValue::NaN");
			constantConversions.Add(Double.PositiveInfinity.ToString(), "DoubleValue::PositiveInfinity");
			constantConversions.Add(Double.NegativeInfinity.ToString(), "DoubleValue::NegativeInfinity");
			constantConversions.Add(Double.Epsilon.ToString(), "DoubleValue::Epsilon");
			constantConversions.Add(float.Epsilon.ToString(), "SingleValue::Epsilon");
		}
		/// <summary>
		/// Is this type a primative
		/// </summary>
		/// <param name="type">to test</param>
		/// <returns>true if primative</returns>
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
		private void HandleFieldAccess(ILInstruction target)
		{
			target.AcceptVisitor(this);
			if (target is LdLoc)
			{
				if (((LdLoc)target).Variable.Name == "this")
				{
					Formatter.Append("->");
					return;
				}
			}
			IType type = TypeVisitor.GetTypeForInstruction(target, null);
			TypeVisitor.FormatTypeAccess(type);
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
			TypeVisitor.FormatType(type);
			if (IsPrimative(type))
				Formatter.Append("Value");
		}
		/// <inheritdoc/>
		protected override ILInstruction Default(ILInstruction inst)
		{
			return (inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitAddressOf(AddressOf inst)
		{
			Formatter.Append("(");
			inst.Value.AcceptVisitor(this);
			Formatter.Append(")");
			return base.VisitAddressOf(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitArglist(Arglist inst)
		{
			return base.VisitArglist(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitAwait(Await inst)
		{
			return base.VisitAwait(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitBinaryNumericInstruction(BinaryNumericInstruction inst)
		{
			if (HandleDivideByZero(inst))
				return base.VisitBinaryNumericInstruction(inst);
			if (HandleSpecialModulusWithFLoatingNumbers(inst))
				return base.VisitBinaryNumericInstruction(inst);
			Formatter.Append("(");
			inst.Left.AcceptVisitor(this);
			Formatter.Append(" ");
			Formatter.Append(operatorSymbols[inst.Operator]);
			Formatter.Append(" ");
			inst.Right.AcceptVisitor(this);
			Formatter.Append(")");
			return base.VisitBinaryNumericInstruction(inst);
		}

		private bool HandleDivideByZero(BinaryNumericInstruction inst)
		{
			if (inst.Operator != BinaryNumericOperator.Div)
				return (false);
			String numberType;
			switch (inst.UnderlyingResultType)
			{
				case StackType.F4:
				case StackType.F8:
					numberType = "(Double)";
					break;
				case StackType.I:
				case StackType.I4:
				case StackType.I8:
					numberType = "(Int64)";
					break;
				default:
					return (false);
			}
			Formatter.Append("Math::Divide(");
			Formatter.Append(numberType);
			inst.Left.AcceptVisitor(this);
			Formatter.Append(",");
			Formatter.Append(numberType);
			inst.Right.AcceptVisitor(this);
			Formatter.Append(")");
			return (true);
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
		/// <inheritdoc/>
		protected override ILInstruction VisitBitNot(BitNot inst)
		{
			Formatter.Append("~");
			inst.Argument.AcceptVisitor(this);
			return base.VisitBitNot(inst);
		}
		/// <inheritdoc/>
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
		/// <summary>
		/// Start a block as the main block for a method
		/// </summary>
		/// <param name="container">container block</param>
		/// <param name="injection">startment to inject or null</param>
		internal void StartMainBlock(BlockContainer container, String injection)
		{
			Injection = injection;
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
		/// <inheritdoc/>
		protected override ILInstruction VisitBlockContainer(BlockContainer container)
		{
			currentReturnContainer = container;
			NewLeaveBlock();
			foreach (Block block in container.Blocks)
			{
				Formatter.AddOpenBrace();
				WriteBlock(block);
				if (Injection != null && currentReturnContainer == mainContainer)
					Formatter.AppendIndentedLine(Injection);
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
			AddLabelIfNeeded(block);
			if (block.Kind == BlockKind.ArrayInitializer)
			{
				HandleInitializedArray(block);
				return;
			}
			DeclareLocalVariables(block);
			foreach (ILInstruction inst in block.Instructions)
			{
				Leave leave = inst as Leave;
				if (String.IsNullOrEmpty(Injection) || leave == null || block.Instructions.Last() != inst || leave.TargetLabel != "IL_0000" || !leave.Value.MatchNop())
				{
					if (Formatter.IsOnNewline)
						Formatter.AppendIndented(String.Empty);
					inst.AcceptVisitor(this);
					if (Formatter.CharactersAddedToLine)
						Formatter.Append(";");
					Formatter.AppendLine(String.Empty);
				}
			}
		}

		private void DeclareLocalVariables(ILInstruction inst)
		{
			if (inst.OpCode == OpCode.Block && ((Block)inst).Kind == BlockKind.ArrayInitializer)
				return;
			if (inst.OpCode == OpCode.LdLoca)
			{
				CheckVariableAddition(((LdLoca)inst).Variable);
			}
			else if (inst.OpCode == OpCode.StLoc)
			{
				CheckVariableAddition(((StLoc)inst).Variable);
			}
			foreach (ILInstruction child in inst.Children)
			{
				DeclareLocalVariables(child);
			}
		}

		private void CheckVariableAddition(ILVariable variable)
		{
			if (!DeclareVariableIfNeeded(variable))
				return;
			Formatter.AppendName(variable.Name);
			Formatter.AppendLine(";");
			Formatter.AppendIndented(String.Empty);
		}

		private void AddLabelIfNeeded(Block block)
		{
			ICSharpCode.Decompiler.IL.Leave leave = block.Instructions.FirstOrDefault() as ICSharpCode.Decompiler.IL.Leave;
			if (block.Instructions.Count == 1 && leave != null)
				return;
			ICSharpCode.Decompiler.IL.BlockContainer container = block.Instructions.FirstOrDefault() as ICSharpCode.Decompiler.IL.BlockContainer;
			if (container != null)
			{
				ICSharpCode.Decompiler.IL.Block block2 = container.Blocks.FirstOrDefault() as ICSharpCode.Decompiler.IL.Block;
				if (block2 != null && block2.Label == block.Label)
					return;
			}
			if (Formatter.IsOnNewline)
			{
				Formatter.Append(block.Label);
				Formatter.AppendLine(":");
			}
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitBox(Box inst)
		{
			Formatter.Append("(new ");
			BoxExpression(inst.Type, inst.Argument);
			Formatter.Append(")");
			return base.VisitBox(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitBranch(Branch inst)
		{
			Formatter.Append("goto ");
			Formatter.Append(inst.TargetLabel);
			return base.VisitBranch(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitCall(Call inst)
		{
			FormatCall(inst);
			return base.VisitCall(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitCallVirt(CallVirt inst)
		{
			FormatCall(inst);
			return base.VisitCallVirt(inst);
		}
		private void FormatCall(CallInstruction inst)
		{
			TypeVisitor.ValidateCall(inst);
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
				TypeVisitor.FormatMethodAccessType(inst.Method, inst.Method.DeclaringType, methodName);
			}
			AddCallParameters(inst.Arguments, inst.Method, skipFirstParameter);
		}
		private bool HandleSpecialCalls(CallInstruction inst)
		{
			if (HandleStringConcat(inst))
				return (true);
			if (HandleStringImplicit(inst))
				return (true);
			return (false);
		}

		private bool HandleStringImplicit(CallInstruction inst)
		{
			if (inst.Method.FullName != "System.String.op_Implicit")
				return (false);
			LdStr ldstr = inst.Arguments.FirstOrDefault() as LdStr;
			if (ldstr == null && inst.Arguments.Count > 1)
				return (false);
			Formatter.AppendStringsWithControl(ldstr.Value);
			return (true);
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
				HandleConcatBlock(block);
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
		private void HandleConcatBlock(Block block)
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
			IType type = TypeVisitor.GetTypeForInstruction(arg, null);
			if (type != null && IsPrimative(type))
			{
				BoxExpression(type, arg);
				return;
			}
			arg.AcceptVisitor(this);
		}
		private bool IsConstant(ILInstruction value)
		{
			return (value is LdcF4 || value is LdcF8 || value is LdcI4 || value is LdcI8 || value is Conv);
		}
		private int GetAsIntConstant(ILInstruction inst)
		{
			if (inst is LdcI4)
				return (((LdcI4)inst).Value);
			if (inst is LdcI8)
				return ((int)((LdcI4)inst).Value);
			if (inst is LdcF8)
				return ((int)((LdcF8)inst).Value);
			if (inst is LdcF4)
				return ((int)((LdcF4)inst).Value);
			if (inst is Conv)
				return (GetAsIntConstant(((Conv)inst).Argument));
			return (-1);
		}
		private void FormatMethodAccessType(IMethod method, ILInstruction inst, String methodName)
		{
			IType type = TypeVisitor.GetTypeForInstruction(inst, null);
			TypeVisitor.FormatMethodAccessType(method, type, methodName);
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
				bool didCast = DoCastOnCallParamterIfNeeded(method.Parameters[paramterIndex]);
				if (didCast)
					Formatter.Append("(");
				inst.AcceptVisitor(this);
				if (didCast)
					Formatter.Append(")");
				first = false;
			}
			Formatter.Append(")");
		}
		private bool DoCastOnCallParamterIfNeeded(IParameter parameter)
		{
			if (!IsPrimative(parameter.Type) && parameter.Type.Kind != TypeKind.Enum)
				return (false);

			Formatter.Append("(");
			TypeVisitor.FormatTypeDelaration(parameter.Type);
			Formatter.Append(")");
			return (true);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitCallIndirect(CallIndirect inst)
		{
			return base.VisitCallIndirect(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitCastClass(CastClass inst)
		{
			Formatter.Append("(");
			TypeVisitor.FormatTypeDelaration(inst.Type);
			Formatter.Append(")");
			inst.Argument.AcceptVisitor(this);
			return base.VisitCastClass(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitCkfinite(Ckfinite inst)
		{
			return base.VisitCkfinite(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitComp(Comp inst)
		{
			Formatter.Append("((");
			inst.Left.AcceptVisitor(this);
			Formatter.Append(")");
			Formatter.Append(comparisonSymbols[inst.Kind]);
			inst.Right.AcceptVisitor(this);
			Formatter.Append(")");
			return base.VisitComp(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitConv(Conv inst)
		{
			CastToPrimativeType(inst.TargetType, inst.Argument);
			return base.VisitConv(inst);
		}

		private void CastToPrimativeType(PrimitiveType targetType, ILInstruction argument)
		{
			Formatter.Append("(");
			switch (targetType)
			{
				case PrimitiveType.I1:
					Formatter.Append("(SByte)");
					break;
				case PrimitiveType.I2:
					Formatter.Append("(Int16)");
					break;
				case PrimitiveType.I4:
					Formatter.Append("(Int32)");
					break;
				case PrimitiveType.I8:
					Formatter.Append("(Int64)");
					break;
				case PrimitiveType.R4:
					Formatter.Append("(Single)");
					break;
				case PrimitiveType.R8:
					Formatter.Append("(Double)");
					break;
				case PrimitiveType.U1:
					Formatter.Append("(Byte)");
					break;
				case PrimitiveType.U2:
					Formatter.Append("(UInt16)");
					break;
				case PrimitiveType.U4:
					Formatter.Append("(UInt32)");
					break;
				case PrimitiveType.U8:
					Formatter.Append("(UInt64)");
					break;
			}
			argument.AcceptVisitor(this);
			Formatter.Append(")");
		}

		/// <inheritdoc/>
		protected override ILInstruction VisitCpblk(Cpblk inst)
		{
			return base.VisitCpblk(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDebugBreak(DebugBreak inst)
		{
			return base.VisitDebugBreak(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDefaultValue(DefaultValue inst)
		{
			if (inst.Type.Kind == TypeKind.Class)
				Formatter.Append("new ");
			TypeVisitor.FormatType(inst.Type);
			Formatter.Append("()");
			return base.VisitDefaultValue(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicBinaryOperatorInstruction(DynamicBinaryOperatorInstruction inst)
		{
			return base.VisitDynamicBinaryOperatorInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicCompoundAssign(DynamicCompoundAssign inst)
		{
			return base.VisitDynamicCompoundAssign(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicConvertInstruction(DynamicConvertInstruction inst)
		{
			return base.VisitDynamicConvertInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicGetIndexInstruction(DynamicGetIndexInstruction inst)
		{
			return base.VisitDynamicGetIndexInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicGetMemberInstruction(DynamicGetMemberInstruction inst)
		{
			return base.VisitDynamicGetMemberInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicInvokeConstructorInstruction(DynamicInvokeConstructorInstruction inst)
		{
			return base.VisitDynamicInvokeConstructorInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicInvokeInstruction(DynamicInvokeInstruction inst)
		{
			return base.VisitDynamicInvokeInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicInvokeMemberInstruction(DynamicInvokeMemberInstruction inst)
		{
			return base.VisitDynamicInvokeMemberInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicIsEventInstruction(DynamicIsEventInstruction inst)
		{
			return base.VisitDynamicIsEventInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicLogicOperatorInstruction(DynamicLogicOperatorInstruction inst)
		{
			return base.VisitDynamicLogicOperatorInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicSetIndexInstruction(DynamicSetIndexInstruction inst)
		{
			return base.VisitDynamicSetIndexInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicSetMemberInstruction(DynamicSetMemberInstruction inst)
		{
			return base.VisitDynamicSetMemberInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitDynamicUnaryOperatorInstruction(DynamicUnaryOperatorInstruction inst)
		{
			return base.VisitDynamicUnaryOperatorInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitExpressionTreeCast(ExpressionTreeCast inst)
		{
			return base.VisitExpressionTreeCast(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitIfInstruction(IfInstruction inst)
		{
			bool justCondition = Formatter.CharactersAddedToLine;
			if (!justCondition)
				Formatter.Append("if ");
			Formatter.Append("(");
			BuildCondition(inst, justCondition);
			Formatter.Append(")");
			if (!justCondition)
			{
				Formatter.AppendLine(String.Empty);
				WriteBlockWithBraces(inst.TrueInst);
				if (!inst.FalseInst.MatchNop())
				{
					Formatter.AppendIndentedLine("else");
					WriteBlockWithBraces(inst.FalseInst);
				}
			}
			return base.VisitIfInstruction(inst);
		}
		private void BuildCondition(IfInstruction inst, bool justCondition)
		{
			bool wasIf = false;
			if (inst.Condition is IfInstruction)
			{
				wasIf = true;
				BuildCondition(inst.Condition as IfInstruction, justCondition);
			}
			if (!wasIf)
			{
				inst.Condition.AcceptVisitor(this);
			}
			if (!justCondition)
				return;
			Formatter.Append(" ? (");
			inst.TrueInst.AcceptVisitor(this);
			Formatter.Append(") : (");
			inst.FalseInst.AcceptVisitor(this);
			Formatter.Append(")");
		}
		private void WriteBlockWithBraces(ILInstruction trueInst)
		{
			Formatter.AddOpenBrace();
			Formatter.AppendIndented(String.Empty);
			trueInst.AcceptVisitor(this);
			ICSharpCode.Decompiler.IL.Block block = trueInst as ICSharpCode.Decompiler.IL.Block;
			if (block == null)
				Formatter.Append(";");
			Formatter.AddCloseBrace();
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitILFunction(ILFunction function)
		{
			return base.VisitILFunction(function);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitInitblk(Initblk inst)
		{
			return base.VisitInitblk(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitInvalidBranch(InvalidBranch inst)
		{
			return base.VisitInvalidBranch(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitInvalidExpression(InvalidExpression inst)
		{
			return base.VisitInvalidExpression(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitIsInst(IsInst inst)
		{
			return base.VisitIsInst(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdcDecimal(LdcDecimal inst)
		{
			return base.VisitLdcDecimal(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdcF4(LdcF4 inst)
		{
			String value;
			if (inst.Value == float.Epsilon || inst.Value == float.MaxValue || inst.Value == float.MinValue)
			{
				value = inst.Value.ToString();
			}
			else
			{
				Double v = inst.Value;
				value = v.ToString();
			}
			if (!ConvertConstants(value))
			{
				if (value.Contains(".", StringComparison.InvariantCulture))
					Formatter.Append("F");
			}
			return base.VisitLdcF4(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdcF8(LdcF8 inst)
		{
			String str = inst.Value.ToString();
			if (Char.IsDigit(str[str.Length - 1]) &&
				!str.Contains('.', StringComparison.InvariantCulture) &&
				!str.Contains('E', StringComparison.InvariantCulture))
				str += ".0";
			ConvertConstants(str);
			return base.VisitLdcF8(inst);
		}
		/// <inheritdoc/>
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
		/// <inheritdoc/>
		protected override ILInstruction VisitLdcI8(LdcI8 inst)
		{
			ConvertConstants(inst.Value.ToString());
			return base.VisitLdcI8(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdElema(LdElema inst)
		{
			Formatter.Append("(*((");
			TypeVisitor.FormatTypeDelaration(inst.Type);
			Formatter.Append("*)");
			inst.Array.AcceptVisitor(this);
			Formatter.Append("->Address(");
			WriteCommaSeparatedList(inst.Indices);
			Formatter.Append(")))");
			return base.VisitLdElema(inst);
		}
		/// <inheritdoc/>
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
			if (name.StartsWith("<", StringComparison.InvariantCulture))
			{
				name = name.Replace("<", String.Empty, StringComparison.InvariantCulture);
				name = name.Replace(">", String.Empty, StringComparison.InvariantCulture);
			}
			return name;
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdFtn(LdFtn inst)
		{
			return base.VisitLdFtn(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdLen(LdLen inst)
		{
			inst.Array.AcceptVisitor(this);
			Formatter.Append("->get_Length()");
			return base.VisitLdLen(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdLoc(LdLoc inst)
		{
			String name = inst.Variable.Name;
			if (variableTranslation.ContainsKey(name))
			{
				name = variableTranslation[name];
			}
			Formatter.AppendName(name);
			return base.VisitLdLoc(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdLoca(LdLoca inst)
		{
			Formatter.AppendName(inst.Variable.Name);
			return base.VisitLdLoca(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdMemberToken(LdMemberToken inst)
		{
			return base.VisitLdMemberToken(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdNull(LdNull inst)
		{
			Formatter.Append("nullptr");
			return base.VisitLdNull(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdObj(LdObj inst)
		{
			inst.Target.AcceptVisitor(this);
			return base.VisitLdObj(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdsFlda(LdsFlda inst)
		{
			WrapTypeIfNeeded(inst.Field.DeclaringType);
			Formatter.Append("::");
			Formatter.AppendName(inst.Field.Name);
			return base.VisitLdsFlda(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdStr(LdStr inst)
		{
			Formatter.Append("(new String(");
			Formatter.AppendStringsWithControl(inst.Value);
			Formatter.Append("))");
			return base.VisitLdStr(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdTypeToken(LdTypeToken inst)
		{
			return base.VisitLdTypeToken(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdVirtDelegate(LdVirtDelegate inst)
		{
			return base.VisitLdVirtDelegate(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLdVirtFtn(LdVirtFtn inst)
		{
			return base.VisitLdVirtFtn(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLeave(Leave inst)
		{
			if (inst.TargetLabel == "IL_0000")
			{
				Formatter.Append("return");
				if (!inst.Value.MatchNop())
				{
					Formatter.Append("(");
					Formatter.Append("(");
					TypeVisitor.FormatTypeDelaration(TypeVisitor.GetTypeForInstruction(inst.Value, MethodReturnType));
					Formatter.Append(")");
					inst.Value.AcceptVisitor(this);
					Formatter.Append(")");
				}
			}
			else
			{
				Formatter.Append("goto ");
				Formatter.Append(CurrentLeaveBlock());
			}
			return base.VisitLeave(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLocAlloc(LocAlloc inst)
		{
			return base.VisitLocAlloc(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLocAllocSpan(LocAllocSpan inst)
		{
			return base.VisitLocAllocSpan(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitLockInstruction(LockInstruction inst)
		{
			return base.VisitLockInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitMakeRefAny(MakeRefAny inst)
		{
			return base.VisitMakeRefAny(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitNewArr(NewArr inst)
		{
			Formatter.Append("new Array(");
			TypeVisitor.FormatType(inst.Type);
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
		/// <inheritdoc/>
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
		/// <inheritdoc/>
		protected override ILInstruction VisitNop(Nop inst)
		{
			return base.VisitNop(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitNullableRewrap(NullableRewrap inst)
		{
			return base.VisitNullableRewrap(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitNullableUnwrap(NullableUnwrap inst)
		{
			return base.VisitNullableUnwrap(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitNullCoalescingInstruction(NullCoalescingInstruction inst)
		{
			return base.VisitNullCoalescingInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitNumericCompoundAssign(NumericCompoundAssign inst)
		{
			inst.Target.AcceptVisitor(this);
			if (inst.Operator == BinaryNumericOperator.Add || inst.Operator == BinaryNumericOperator.Sub)
			{
				if (IsConstant(inst.Value))
				{
					int constant = GetAsIntConstant(inst.Value);
					if (constant == 1)
					{
						if (inst.Operator == BinaryNumericOperator.Add)
							Formatter.Append("++");
						else
							Formatter.Append("--");
						return base.VisitNumericCompoundAssign(inst);
					}
				}
			}
			Formatter.Append(" ");
			Formatter.Append(operatorSymbols[inst.Operator]);
			Formatter.Append("= ");
			inst.Value.AcceptVisitor(this);
			return base.VisitNumericCompoundAssign(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitPinnedRegion(PinnedRegion inst)
		{
			return base.VisitPinnedRegion(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitRefAnyType(RefAnyType inst)
		{
			return base.VisitRefAnyType(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitRefAnyValue(RefAnyValue inst)
		{
			return base.VisitRefAnyValue(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitRethrow(Rethrow inst)
		{
			Formatter.Append("throw");
			return base.VisitRethrow(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitSizeOf(SizeOf inst)
		{
			return base.VisitSizeOf(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitStLoc(StLoc inst)
		{
			if (HandleIncrementAndDecrement(inst))
				return base.VisitStLoc(inst);
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
				TypeVisitor.FormatTypeDelaration(type);
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
			String oper = bin.Operator == BinaryNumericOperator.Add ? "++" : "--";
			Formatter.Append(oper);
			Formatter.AppendName(ldLoc.Variable.Name);
			return (true);
		}
		private bool DeclareVariableIfNeeded(ILVariable variable)
		{
			if (CurrentVariables.ContainsKey(variable.Name))
				return (false);
			CurrentVariables.Add(variable.Name, variable.Name);
			if (Formatter.IsOnNewline)
				Formatter.AppendIndented(String.Empty);
			TypeVisitor.FormatTypeDelaration(variable.Type);
			Formatter.Append(" ");
			return (true);
		}
		/// <inheritdoc/>
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
		private void HandleInitializedArray(Block block)
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
				Formatter.AppendIndented(String.Empty);
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
			}
			newArr.AcceptVisitor(this);
			InitializeElementsOfArray(block);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitStringToInt(StringToInt inst)
		{
			return base.VisitStringToInt(inst);
		}
		/// <inheritdoc/>
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
					{
						Formatter.AppendIndented("default");
					}
					else
					{
						Formatter.AppendIndented("case ");
						Formatter.Append(lbl.ToString());
					}
					break;
				}
				Formatter.AppendLine(":");
				Formatter.AppendIndented(String.Empty);
				section.Body.AcceptVisitor(this);
				Formatter.AppendLine(";");
			}
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitSwitchSection(SwitchSection inst)
		{
			return base.VisitSwitchSection(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitThreeValuedBoolAnd(ThreeValuedBoolAnd inst)
		{
			return base.VisitThreeValuedBoolAnd(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitThreeValuedBoolOr(ThreeValuedBoolOr inst)
		{
			return base.VisitThreeValuedBoolOr(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitThrow(Throw inst)
		{
			Formatter.Append("throw (");
			inst.Argument.AcceptVisitor(this);
			Formatter.Append(")");
			return base.VisitThrow(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitTryCatch(TryCatch inst)
		{
			HandleTryBlock(inst);
			foreach (TryCatchHandler handler in inst.Handlers)
			{
				Formatter.AppendIndented("catch (");
				TypeVisitor.FormatTypeDelaration(handler.Variable.Type);
				Formatter.Append(" ");
				Formatter.AppendName(handler.Variable.Name);
				Formatter.Append(")");
				BlockContainer bc = handler.Body as BlockContainer;
				if (bc == null)
				{
					handler.Body.AcceptVisitor(this);
				}
				else
				{
					Formatter.AddOpenBrace();
					bc.Blocks.FirstOrDefault().AcceptVisitor(this);
					Formatter.AddCloseBrace();
				}
			}
			Formatter.Append(CurrentLeaveBlock());
			Formatter.AppendLine(":;");
			ExitLeaveBLock();
			return base.VisitTryCatch(inst);
		}

		private void HandleTryBlock(TryCatch inst)
		{
			NewLeaveBlock();
			Formatter.Append("try");
			if (inst.TryBlock is BlockContainer)
			{
				Block block = ((BlockContainer)inst.TryBlock).Blocks[0];
				Formatter.AddOpenBrace();
				WriteBlock(block);
				Formatter.AddCloseBrace();
			}
			else
				inst.TryBlock.AcceptVisitor(this);
		}

		/// <inheritdoc/>
		protected override ILInstruction VisitTryCatchHandler(TryCatchHandler inst)
		{
			return base.VisitTryCatchHandler(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitTryFault(TryFault inst)
		{
			return base.VisitTryFault(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitTryFinally(TryFinally inst)
		{
			return base.VisitTryFinally(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitUnbox(Unbox inst)
		{
			return base.VisitUnbox(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitUnboxAny(UnboxAny inst)
		{
			if (inst.Type.Name == "DateTime" || inst.Type.Name == "TimeSpan")
			{
				TypeVisitor.FormatType(inst.Type);
				Formatter.Append("(");
			}
			inst.Argument.AcceptVisitor(this);
			Formatter.Append("->get_As");
			TypeVisitor.FormatType(inst.Type);
			Formatter.Append("()");
			if (inst.Type.Name == "DateTime" || inst.Type.Name == "TimeSpan")
			{
				Formatter.Append(")");
			}
			return base.VisitUnboxAny(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitUserDefinedCompoundAssign(UserDefinedCompoundAssign inst)
		{
			inst.Target.AcceptVisitor(this);
			Formatter.Append(" = ");
			TypeVisitor.FormatType(inst.Method.DeclaringType);
			TypeVisitor.FormatMethodAccessType(inst.Method, inst.Method.DeclaringType, inst.Method.Name);
			Formatter.Append("(");
			inst.Target.AcceptVisitor(this);
			Formatter.Append(",");
			inst.Value.AcceptVisitor(this);
			Formatter.Append(")");
			return base.VisitUserDefinedCompoundAssign(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitUserDefinedLogicOperator(UserDefinedLogicOperator inst)
		{
			return base.VisitUserDefinedLogicOperator(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitUsingInstruction(UsingInstruction inst)
		{
			return base.VisitUsingInstruction(inst);
		}
		/// <inheritdoc/>
		protected override ILInstruction VisitYieldReturn(YieldReturn inst)
		{
			return base.VisitYieldReturn(inst);
		}
		/// <summary>
		/// Get name of property
		/// </summary>
		/// <param name="blockContainer">block for property</param>
		/// <returns>name of property</returns>
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
						if (ldFld.Field.Name.StartsWith("<", StringComparison.InvariantCulture))
							return (ReplaceSpecial(ldFld.Field.Name));
					}
				}
			}
			return (null);
		}
	}
}
