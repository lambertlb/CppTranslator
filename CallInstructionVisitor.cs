using System;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.IL;
using ICSharpCode.Decompiler.TypeSystem;

namespace CppTranslator
{
	public class CallInstructionVisitor : ILVisitor<ILInstruction>
	{
		private CppVisitorBase CppVisitorBase { get; set; }
		public Formatter Formatter { get; set; }
		public bool HadCall { get; set; }
		public bool IsStatic { get; set; }
		public bool IsProperty { get; set; }
		public bool IsArray { get; set; }
		public String MethodName { get; set; }

		public CallInstructionVisitor(CppVisitorBase cppVisitorBase)
		{
			CppVisitorBase = cppVisitorBase;
			Formatter = cppVisitorBase.Formatter;
		}
		protected override ILInstruction Default(ILInstruction inst)
		{
			HadCall = false;
			return null;
		}

		protected override ILInstruction VisitCall(Call inst)
		{
			HadCall = true;
			IsStatic = inst.Method.IsStatic;
			MethodName = inst.Method.Name;
			IsProperty = MethodName.StartsWith("get_") || MethodName.StartsWith("set_");
			IsArray = inst.Method.DeclaringType.Name == "Array";
			InvocationExpression invocationExpression = CppVisitorBase.CurrentExpression as InvocationExpression;
			MemberReferenceExpression memberReferenceExpression = invocationExpression.Target as MemberReferenceExpression;
			IType targetType = null;
			if (memberReferenceExpression != null)
			{
				targetType = memberReferenceExpression.Target.GetResolveResult().Type;
				if (targetType.Kind == TypeKind.Unknown)
					targetType = inst.Method.DeclaringType;
			}
			if (IsStatic)
			{
				if (IsArray)
				{
					Formatter.Append("Array::");
				}
				else
				{
					if (CppVisitorBase.IsPrimative(targetType))
					{
						CppVisitorBase.ToValueType(targetType);
					}
					else
					{
						Formatter.Append(inst.Method.DeclaringType.Name);
					}
					Formatter.Append("::");
				}
			}
			else
			{
				if (memberReferenceExpression != null)
				{
					if (CppVisitorBase.IsPrimative(targetType))
					{
						Formatter.Append("(");
						CppVisitorBase.CastToValueType(targetType, memberReferenceExpression.Target);
						Formatter.Append(")");
					}
					else
						CppVisitorBase.CastToType(targetType, memberReferenceExpression.Target);
					if (inst.Method.DeclaringType.Kind == TypeKind.Struct)
					{
						Formatter.Append(".");
					}
					else
					{
						Formatter.Append("->");
					}
				}
			}
			Formatter.Append(MethodName);
			return null;
		}

		//protected override ILInstruction VisitCallIndirect(CallIndirect inst)
		//{
		//	HadCall = true;
		//	IsStatic = inst.Method.IsStatic;
		//	MethodName = inst.Method.Name;
		//	IsProperty = MethodName.StartsWith("get_") || MethodName.StartsWith("set_");
		//	return null;
		//}

		protected override ILInstruction VisitCallVirt(CallVirt inst)
		{
			HadCall = true;
			IsStatic = inst.Method.IsStatic;
			MethodName = inst.Method.Name;
			IsProperty = MethodName.StartsWith("get_") || MethodName.StartsWith("set_");
			IsArray = inst.Method.DeclaringType.Name == "Array";
			InvocationExpression invocationExpression = CppVisitorBase.CurrentExpression as InvocationExpression;
			MemberReferenceExpression memberReferenceExpression = invocationExpression.Target as MemberReferenceExpression;
			if (IsStatic)
			{
				if (IsArray)
				{
					Formatter.Append("Array");
				}
				else
				{
					Formatter.Append(inst.Method.DeclaringType.Name);
				}
				Formatter.Append("::");
			}
			else
			{
				if (memberReferenceExpression != null)
				{
					memberReferenceExpression.Target.AcceptVisitor(CppVisitorBase);
					IType targetType = memberReferenceExpression.Target.GetResolveResult().Type;
					if (targetType.Kind == TypeKind.Struct)
					{
						Formatter.Append(".");
					}
					else
					{
						Formatter.Append("->");
					}
				}
			}
			Formatter.Append(MethodName);
			return null;
		}
	}
}
