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

namespace CppTranslatorSupport
{
	/// <summary>
	/// This parent class provides data access from the target platform to the translated code.
	/// It is not actually translated. It's purpose is to stub out and emulate
	/// all needed data on the target platform to allow running and debugging in .net.
	/// A hand crafted version of this will be used in the target platform to
	/// give the specific support needed. An example is in the DotNetLibrarySupport projects.
	/// 
	/// For example this class defines an array property and a scalar double property.
	/// This can be used to debug the module in .Net.
	/// Once the code is debugged you hand craft a data access class to allow the property to
	/// access the real data within the platform. How this would be done is platform specific
	/// and beyond this comment.
	/// </summary>
	public class DataAccess : TranslatorSupport
	{
		private Int32[] arrayData = new Int32[] { 1, 2, 3, 4 };
		/// <summary>
		/// Emulate a access to array property
		/// </summary>
		public int[] ArrayData { get => arrayData; set => arrayData = value; }
		private Double doubleData = 5.5;
		/// <summary>
		/// Emulate access to scalar double
		/// </summary>
		public double DoubleData { get => doubleData; set => doubleData = value; }
	}
}
