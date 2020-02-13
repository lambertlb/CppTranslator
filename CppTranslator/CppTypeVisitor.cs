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
using System;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Text;
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
		/// <summary>
		/// Collection of legal types and method signatures
		/// </summary>
		private Dictionary<String, String> legalTypes = new Dictionary<String, String>();
		/// <summary>
		/// Map C# types to C++ types
		/// </summary>
		private Dictionary<String, String> typeTranslation = new Dictionary<String, String>();
		/// <summary>
		/// Formatter for output
		/// </summary>
		public Formatter Formatter { get; set; }
		/// <summary>
		/// Initializes a new instance of the <see cref="CppTypeVisitor"/> class.
		/// Constructor
		/// </summary>
		/// <param name="formatter">formatter</param>
		public CppTypeVisitor(Formatter formatter)
		{
			this.Formatter = formatter;
			typeTranslation.Add("bool", "Boolean");
			typeTranslation.Add("byte", "Byte");
			typeTranslation.Add("sbyte", "SByte");
			typeTranslation.Add("char", "Char");
			typeTranslation.Add("double", "Double");
			typeTranslation.Add("float", "Float");
			typeTranslation.Add("int", "Int32");
			typeTranslation.Add("uint", "UInt32");
			typeTranslation.Add("long", "Int64");
			typeTranslation.Add("ulong", "UInt64");
			typeTranslation.Add("object", "Object");
			typeTranslation.Add("short", "Int16");
			typeTranslation.Add("ushort", "UInt16");
			typeTranslation.Add("string", "String");
		}

		public void LoadValidTypes()
		{
#if DEBUG
			String typeFilePath = AppDomain.CurrentDomain.BaseDirectory + @"..\..\ValidTypes.xml";
#else
			String typeFilePath = AppDomain.CurrentDomain.BaseDirectory + @"ValidTypes.xml";
#endif
			try
			{
				using (ValidItems validItems = new ValidItems())
				{
					validItems.ReadXml(typeFilePath, XmlReadMode.ReadSchema);
					LoadValidationData(validItems);
				}
			}
			catch (Exception)
			{
				Trace.TraceError("Missing file " + typeFilePath);
			}
		}

		private void LoadValidationData(ValidItems validItems)
		{
			ValidItems.ValidDataTable table = validItems.Valid;
			foreach (ValidItems.ValidRow validRow in table)
			{
				legalTypes.Add(validRow.Valid_Column, String.Empty);
			}
		}

		/// <summary>
		/// Make sure this is supported type
		/// </summary>
		/// <param name="type">to check</param>
		private void ValidateType(IType type)
		{
			ValidateType(type.FullName);
		}
		private void ValidateType(String typeToValidate)
		{
			typeToValidate = typeToValidate.Replace("&", String.Empty, StringComparison.InvariantCulture);
			if (!typeToValidate.StartsWith("System.", StringComparison.InvariantCulture))
				return;
			if (!legalTypes.ContainsKey(typeToValidate))
			{
				IllegalType(typeToValidate);
			}
		}
		/// <summary>
		/// Make sure this call uses valid types
		/// </summary>
		/// <param name="inst">Call Instruction</param>
		public void ValidateCall(CallInstruction inst)
		{
			String signature = BuildCallSignature(inst);
			ValidateType(signature);
		}

		private string BuildCallSignature(CallInstruction inst)
		{
			StringBuilder sb = new StringBuilder();
			sb.Append(inst.Method.FullName);
			sb.Append('(');
			bool needComma = false;
			foreach (IParameter parameter in inst.Method.Parameters)
			{
				ValidateType(parameter.Type);
				if (needComma)
					sb.Append(',');
				sb.Append(parameter.Type.FullName);
				needComma = true;
			}
			sb.Append(')');
			return (sb.ToString());
		}

		private void IllegalType(String typeToValidate)
		{
			Trace.TraceError("Illegal Use of \"" + typeToValidate + "\"");
			// Just log it once
			legalTypes.Add(typeToValidate, String.Empty);
			//using (StreamWriter file = new StreamWriter("IllegalTypes.txt", true))
			//{
			//	file.WriteLine(typeToValidate);
			//}
		}

		/// <summary>
		/// Format a type declaration
		/// </summary>
		/// <param name="type">to format</param>
		public void FormatTypeDelaration(IType type)
		{
			ValidateType(type);
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
			else if (inst is StLoc)
				return (((StLoc)inst).Variable.Type);
			return (defaultType);
		}
		/// <summary>
		/// Add type to output
		/// </summary>
		/// <param name="type">to add</param>
		public void AppendType(String type)
		{
			if (typeTranslation.ContainsKey(type))
			{
				Formatter.Append(typeTranslation[type]);
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
