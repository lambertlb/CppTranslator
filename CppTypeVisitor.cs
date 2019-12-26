using System;
using System.Collections.Generic;
using ICSharpCode.Decompiler.IL;
using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.TypeSystem.Implementation;

namespace CppTranslator
{
	/// <summary>
	/// Visitor used for type formatting
	/// </summary>
	public class CppTypeVisitor : TypeVisitor
	{
		private Dictionary<String, String> types = new Dictionary<String, String>();
		private CppVisitorBase baseVisitor;
		/// <summary>
		/// Formatter for output
		/// </summary>
		public Formatter Formatter { get; set; }
		/// <summary>
		/// Initializes a new instance of the <see cref="CppTypeVisitor"/> class.
		/// Constructor
		/// </summary>
		/// <param name="baseVisitor">base visitor</param>
		public CppTypeVisitor(CppVisitorBase baseVisitor)
		{
			this.baseVisitor = baseVisitor;
			this.Formatter = baseVisitor.Formatter;
			types.Add("bool", "Boolean");
			types.Add("byte", "Byte");
			types.Add("sbyte", "SByte");
			types.Add("char", "Char");
			types.Add("double", "Double");
			types.Add("float", "Float");
			types.Add("int", "Int32");
			types.Add("uint", "UInt32");
			types.Add("long", "Int64");
			types.Add("ulong", "UInt64");
			types.Add("object", "Object");
			types.Add("short", "Int16");
			types.Add("ushort", "UInt16");
			types.Add("string", "String");
		}
		/// <summary>
		/// Format a type declaration
		/// </summary>
		/// <param name="type">to format</param>
		public void FormatTypeDelaration(IType type)
		{
			FormatType(type);
			if (IsPointerType(type))
			{
				Formatter.Append("*");
			}
		}
		/// <summary>
		/// Format a type
		/// </summary>
		/// <param name="type">to format</param>
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
		/// <summary>
		/// Is this a pointer type
		/// </summary>
		/// <param name="type">type to test</param>
		/// <returns>true if pointer type</returns>
		internal bool IsPointerType(IType type)
		{
			if (type.Kind == TypeKind.ByReference)
			{
				return (true);
			}
			return (type.Kind == TypeKind.Class || type.Kind == TypeKind.Array);
		}
		/// <summary>
		/// Format method access
		/// </summary>
		/// <param name="method">to format</param>
		/// <param name="type">type of method</param>
		/// <param name="methodName">name of method</param>
		public void FormatMethodAccessType(IMethod method, IType type, String methodName)
		{
			if (method.IsStatic)
				Formatter.Append("::");
			else
				FormatTypeAccess(type);
			Formatter.Append(methodName);
		}
		/// <summary>
		/// Format type access for cpp
		/// </summary>
		/// <param name="type">to format</param>
		public void FormatTypeAccess(IType type)
		{
			if (type == null || IsPointerType(type))
				Formatter.Append("->");
			else
				Formatter.Append(".");
		}
		/// <summary>
		/// Get IType for instruction
		/// </summary>
		/// <param name="inst">instruction</param>
		/// <param name="defaultType">default type to use or null</param>
		/// <returns>IType for instructions</returns>
		public IType GetTypeForInstruction(ILInstruction inst, IType defaultType)
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
		/// <summary>
		/// Add type to output
		/// </summary>
		/// <param name="type">to add</param>
		public void AppendType(String type)
		{
			if (types.ContainsKey(type))
			{
				Formatter.Append(types[type]);
				return;
			}
			Formatter.Append(type);
		}
		/// <inheritdoc/>
		public override IType VisitArrayType(ArrayType type)
		{
			Formatter.Append("Array*");
			return (null);
		}
		/// <inheritdoc/>
		public override IType VisitTypeDefinition(ITypeDefinition type)
		{
			AppendType(type.Name);
			if (type.Kind == TypeKind.Class)
				Formatter.Append("*");
			return (null);
		}
		/// <inheritdoc/>
		public override IType VisitByReferenceType(ByReferenceType type)
		{
			Formatter.Append("*** Unknow type ");
			Formatter.Append(type.ToString());
			return base.VisitByReferenceType(type);
		}
		/// <inheritdoc/>
		public override IType VisitModOpt(ModifiedType type)
		{
			Formatter.Append("*** Unknow type ");
			Formatter.Append(type.ToString());
			return base.VisitModOpt(type);
		}
		/// <inheritdoc/>
		public override IType VisitModReq(ModifiedType type)
		{
			Formatter.Append("*** Unknow type ");
			Formatter.Append(type.ToString());
			return base.VisitModReq(type);
		}
		/// <inheritdoc/>
		public override IType VisitNullabilityAnnotatedType(NullabilityAnnotatedType type)
		{
			Formatter.Append("*** Unknow type ");
			Formatter.Append(type.ToString());
			return base.VisitNullabilityAnnotatedType(type);
		}
		/// <inheritdoc/>
		public override IType VisitOtherType(IType type)
		{
			Formatter.Append("*** Unknow type ");
			Formatter.Append(type.ToString());
			return base.VisitOtherType(type);
		}
		/// <inheritdoc/>
		public override IType VisitParameterizedType(ParameterizedType type)
		{
			Formatter.Append("*** Unknow type ");
			Formatter.Append(type.ToString());
			return base.VisitParameterizedType(type);
		}
		/// <inheritdoc/>
		public override IType VisitPointerType(PointerType type)
		{
			Formatter.Append("*** Unknow type ");
			Formatter.Append(type.ToString());
			return base.VisitPointerType(type);
		}
		/// <inheritdoc/>
		public override IType VisitTupleType(TupleType type)
		{
			Formatter.Append("*** Unknow type ");
			Formatter.Append(type.ToString());
			return base.VisitTupleType(type);
		}
		/// <inheritdoc/>
		public override IType VisitTypeParameter(ITypeParameter type)
		{
			Formatter.Append("*** Unknow type ");
			Formatter.Append(type.ToString());
			return base.VisitTypeParameter(type);
		}
	}
}
