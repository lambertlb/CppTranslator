using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.TypeSystem.Implementation;
using System;
using System.Collections.Generic;
using System.Text;

namespace CppTranslator
{
	class IlTypeVisitor : TypeVisitor
	{
		private Formatter formatter;

		public IlTypeVisitor(Formatter formatter)
		{
			this.formatter = formatter;
		}

		public override IType VisitArrayType(ArrayType type)
		{
			return base.VisitArrayType(type);
		}

		public override IType VisitByReferenceType(ByReferenceType type)
		{
			return base.VisitByReferenceType(type);
		}

		public override IType VisitModOpt(ModifiedType type)
		{
			return base.VisitModOpt(type);
		}

		public override IType VisitModReq(ModifiedType type)
		{
			return base.VisitModReq(type);
		}

		public override IType VisitNullabilityAnnotatedType(NullabilityAnnotatedType type)
		{
			return base.VisitNullabilityAnnotatedType(type);
		}

		public override IType VisitOtherType(IType type)
		{
			return base.VisitOtherType(type);
		}

		public override IType VisitParameterizedType(ParameterizedType type)
		{
			return base.VisitParameterizedType(type);
		}

		public override IType VisitPointerType(PointerType type)
		{
			return base.VisitPointerType(type);
		}

		public override IType VisitTupleType(TupleType type)
		{
			return base.VisitTupleType(type);
		}

		internal bool IsPointerType(ITypeDefinition type)
		{
			if (type.Kind == TypeKind.ByReference)
			{
				//ByReferenceType by = (ByReferenceType)type;
				//return (by.ElementType.Kind == TypeKind.Class);
			}
			return (type.Kind == TypeKind.Class);
		}
		public override IType VisitTypeDefinition(ITypeDefinition type)
		{
			if (type.IsStatic)
				formatter.Append("::");
			else if (IsPointerType(type))
				formatter.Append("->");
			else
				formatter.Append(".");
			return base.VisitTypeDefinition(type);
		}

		public override IType VisitTypeParameter(ITypeParameter type)
		{
			return base.VisitTypeParameter(type);
		}
	}
}
