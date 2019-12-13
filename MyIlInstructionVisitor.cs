using ICSharpCode.Decompiler.IL;
using ICSharpCode.Decompiler.TypeSystem;
using System;
using System.Collections.Generic;

namespace CppTranslator
{
	class MyIlInstructionVisitor : ILVisitor<ILInstruction>
	{

		private Stack<Dictionary<String, String>> localVariable = new Stack<Dictionary<String, String>>();
		public Dictionary<String, String> CurrentVariables { get; set; }
		public Formatter Formatter { get; set; }
		public IType MethodReturnType { get; set; }

		private void NewLocalVariables()
		{
			if (CurrentVariables != null)
				localVariable.Push(CurrentVariables);
			CurrentVariables = null;
			CurrentVariables = new Dictionary<string, string>();
		}
		private void PopVariables()
		{
			CurrentVariables = null;
			if (localVariable.Count > 0)
			{
				CurrentVariables = localVariable.Pop();
			}
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
		public MyIlInstructionVisitor(Formatter formatter)
		{
			Formatter = formatter;
		}
		protected override ILInstruction Default(ILInstruction inst)
		{
			return (inst);
		}

		protected override ILInstruction VisitAddressOf(AddressOf inst)
		{
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
			return base.VisitBinaryNumericInstruction(inst);
		}

		protected override ILInstruction VisitBitNot(BitNot inst)
		{
			return base.VisitBitNot(inst);
		}

		protected override ILInstruction VisitBlock(Block block)
		{
			return base.VisitBlock(block);
		}

		protected override ILInstruction VisitBlockContainer(BlockContainer container)
		{
			foreach (Block block in container.Blocks)
			{
				NewLocalVariables();
				Formatter.AddOpenBrace();
				WriteBlock(block);
				Formatter.AddCloseBrace();
				PopVariables();
			}
			return (null);
		}

		private void WriteBlock(Block block)
		{
			foreach (ILInstruction inst in block.Instructions)
			{
				Formatter.AppendIndented("");
				inst.AcceptVisitor(this);
				if (Formatter.CharactersAddedToLine)
					Formatter.Append(";");
				Formatter.AppendLine("");
			}
		}

		protected override ILInstruction VisitBox(Box inst)
		{
			return base.VisitBox(inst);
		}

		protected override ILInstruction VisitBranch(Branch inst)
		{
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
			var arg = inst.Arguments.FirstOrDefault();
			bool skipFirstParameter = false;
			bool isThis = false;
			if (inst.IsInstanceCall)
			{
				LdLoc ldLoc = arg.AcceptVisitor(this) as LdLoc;
				if (ldLoc != null && ldLoc.Variable.Name == "this")
					isThis = true;
				skipFirstParameter = true;
			}
			else
			{
				if (inst.Method.IsStatic)
				{
					Formatter.Append(inst.Method.DeclaringType.Name);
				}
			}
			if (FormatMethodAccessType(inst.Method, isThis))
			{
				AddCallParameters(inst.Arguments, skipFirstParameter);
			}
		}

		private bool FormatMethodAccessType(IMethod method, bool isThis)
		{
			if (!isThis)
			{
				if (method.IsStatic)
					Formatter.Append("::");
				else if (IsPointerType(method.DeclaringType))
					Formatter.Append("->");
				else
					Formatter.Append(".");
			}
			if (method.Name != ".ctor")
			{
				Formatter.Append(method.Name);
				return (true);
			}
			return (false);
		}

		private void AddCallParameters(InstructionCollection<ILInstruction> arguments, bool hasThis)
		{
			InstructionCollection<ILInstruction>.Enumerator walker = arguments.GetEnumerator();
			if (hasThis)
				walker.MoveNext();
			bool first = true;
			Formatter.Append("(");
			while (walker.MoveNext())
			{
				if (!first)
					Formatter.Append(", ");
				ILInstruction inst = walker.Current;
				inst.AcceptVisitor(this);
				first = false;
			}
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
			return base.VisitComp(inst);
		}

		protected override ILInstruction VisitConv(Conv inst)
		{
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
			return base.VisitIfInstruction(inst);
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
			Formatter.Append(inst.Value.ToString());
			return base.VisitLdcF4(inst);
		}

		protected override ILInstruction VisitLdcF8(LdcF8 inst)
		{
			Formatter.Append(inst.Value.ToString());
			return base.VisitLdcF8(inst);
		}

		protected override ILInstruction VisitLdcI4(LdcI4 inst)
		{
			Formatter.Append(inst.Value.ToString());
			return base.VisitLdcI4(inst);
		}

		protected override ILInstruction VisitLdcI8(LdcI8 inst)
		{
			Formatter.Append(inst.Value.ToString());
			return base.VisitLdcI8(inst);
		}

		protected override ILInstruction VisitLdElema(LdElema inst)
		{
			return base.VisitLdElema(inst);
		}

		protected override ILInstruction VisitLdFlda(LdFlda inst)
		{
			Formatter.AppendName(inst.Field.Name);
			return base.VisitLdFlda(inst);
		}

		protected override ILInstruction VisitLdFtn(LdFtn inst)
		{
			return base.VisitLdFtn(inst);
		}

		protected override ILInstruction VisitLdLen(LdLen inst)
		{
			return base.VisitLdLen(inst);
		}

		protected override ILInstruction VisitLdLoc(LdLoc inst)
		{
			if (inst.Variable.Name != "this")
				Formatter.AppendName(inst.Variable.Name);
			return base.VisitLdLoc(inst);
		}

		protected override ILInstruction VisitLdLoca(LdLoca inst)
		{
			return base.VisitLdLoca(inst);
		}

		protected override ILInstruction VisitLdMemberToken(LdMemberToken inst)
		{
			return base.VisitLdMemberToken(inst);
		}

		protected override ILInstruction VisitLdNull(LdNull inst)
		{
			return base.VisitLdNull(inst);
		}

		protected override ILInstruction VisitLdObj(LdObj inst)
		{
			inst.Target.AcceptVisitor(this);
			return base.VisitLdObj(inst);
		}

		protected override ILInstruction VisitLdsFlda(LdsFlda inst)
		{
			Formatter.Append(inst.Field.DeclaringType.Name);
			Formatter.Append(".");
			Formatter.Append(inst.Field.Name);
			return base.VisitLdsFlda(inst);
		}

		protected override ILInstruction VisitLdStr(LdStr inst)
		{
			Formatter.Append("new String(L\"");
			Formatter.Append(inst.Value);
			Formatter.Append("\")");
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
			Formatter.Append("return");
			if (!inst.Value.MatchNop())
			{
				Formatter.Append("(");
				if (MethodReturnType != null && MethodReturnType.Kind != TypeKind.Unknown)
				{
					Formatter.Append("(");
					FormatTypeDelaration(MethodReturnType);
					Formatter.Append(")");
				}
				inst.Value.AcceptVisitor(this);
				Formatter.Append(")");
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
			return base.VisitNewArr(inst);
		}

		protected override ILInstruction VisitNewObj(NewObj inst)
		{
			Formatter.Append("new ");
			Formatter.Append(inst.Method.DeclaringType.Name);
			AddCallParameters(inst.Arguments, false);
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
			DeclareVariableIfNeeded(inst.Variable);
			Formatter.AppendName(inst.Variable.Name);
			Formatter.Append(" = ");
			inst.Value.AcceptVisitor(this);

			return base.VisitStLoc(inst);
		}

		private void DeclareVariableIfNeeded(ILVariable variable)
		{
			if (CurrentVariables.ContainsKey(variable.Name))
				return;
			CurrentVariables.Add(variable.Name, variable.Name);
			FormatTypeDelaration(variable.Type);
			Formatter.Append(" ");
		}

		protected override ILInstruction VisitStObj(StObj inst)
		{
			inst.Target.AcceptVisitor(this);
			Formatter.Append(" = ");
			inst.Value.AcceptVisitor(this);
			return base.VisitStObj(inst);
		}

		protected override ILInstruction VisitStringToInt(StringToInt inst)
		{
			return base.VisitStringToInt(inst);
		}

		protected override ILInstruction VisitSwitchInstruction(SwitchInstruction inst)
		{
			return base.VisitSwitchInstruction(inst);
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
			return base.VisitUnboxAny(inst);
		}

		protected override ILInstruction VisitUserDefinedCompoundAssign(UserDefinedCompoundAssign inst)
		{
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
	}
}
