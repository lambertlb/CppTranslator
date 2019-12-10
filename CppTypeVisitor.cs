using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.TypeSystem.Implementation;
using System;

namespace CppTranslator
{
	public class CppTypeVisitor : TypeVisitor
	{
		private Formatter formatter;
		private CppVisitorBase baseVisitor;
		public CppTypeVisitor(CppVisitorBase baseVisitor)
		{
			this.baseVisitor = baseVisitor;
			this.formatter = baseVisitor.Formatter;
		}

		public override IType VisitArrayType(ArrayType type)
		{
			formatter.Append("Array*");
			return (null);
		}
		public override IType VisitTypeDefinition(ITypeDefinition type)
		{
			if (type.Name == "String")
				formatter.Append("");
			formatter.AppendType(type.Name);
			if (type.Kind == TypeKind.Class)
				formatter.Append("*");
			return (null);
		}

		public override IType VisitByReferenceType(ByReferenceType type)
		{
			formatter.Append("*** Unknow type ");
			formatter.Append(type.ToString());
			return base.VisitByReferenceType(type);
		}

		public override IType VisitModOpt(ModifiedType type)
		{
			formatter.Append("*** Unknow type ");
			formatter.Append(type.ToString());
			return base.VisitModOpt(type);
		}

		public override IType VisitModReq(ModifiedType type)
		{
			formatter.Append("*** Unknow type ");
			formatter.Append(type.ToString());
			return base.VisitModReq(type);
		}

		public override IType VisitNullabilityAnnotatedType(NullabilityAnnotatedType type)
		{
			formatter.Append("*** Unknow type ");
			formatter.Append(type.ToString());
			return base.VisitNullabilityAnnotatedType(type);
		}

		public override IType VisitOtherType(IType type)
		{
			formatter.Append("*** Unknow type ");
			formatter.Append(type.ToString());
			return base.VisitOtherType(type);
		}

		public override IType VisitParameterizedType(ParameterizedType type)
		{
			formatter.Append("*** Unknow type ");
			formatter.Append(type.ToString());
			return base.VisitParameterizedType(type);
		}

		public override IType VisitPointerType(PointerType type)
		{
			formatter.Append("*** Unknow type ");
			formatter.Append(type.ToString());
			return base.VisitPointerType(type);
		}

		public override IType VisitTupleType(TupleType type)
		{
			formatter.Append("*** Unknow type ");
			formatter.Append(type.ToString());
			return base.VisitTupleType(type);
		}

		public override IType VisitTypeParameter(ITypeParameter type)
		{
			formatter.Append("*** Unknow type ");
			formatter.Append(type.ToString());
			return base.VisitTypeParameter(type);
		}
	}
}
