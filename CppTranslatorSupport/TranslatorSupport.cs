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

namespace CppTranslatorSupport
{
	/// <summary>
	/// This is the base class that all translated modules should inherit from.
	/// It is not actually translated. It's purpose is to stub out and emulate
	/// all funtionality needed on the target platform to allow running and debugging in .net.
	/// A hand crafted version of this will be used in the target platform to
	/// give the specific support needed. An example is in the DotNetLibrarySupport projects.
	/// For example if you want to have the translated code "Send" strings to a central logger
	/// You can have a send methods as defined below. In .Net it will just send to console but
	/// in the target platform you can do what you wish with the string.
	/// 
	/// Handling things this way you can do most of you debugging in .net and have less pain
	/// debugging in C++ on target platform.
	/// </summary>
	public class TranslatorSupport
	{
		/// <summary>
		/// Example of a supported platform function that can be called by translated code.
		/// </summary>
		/// <param name="message"></param>
		public void Send(String message)
		{
			Console.WriteLine(message);
		}
		/// <summary>
		/// Main run methods for a module. In the target platform
		/// This would do all the setup for the environment before running the code. 
		/// </summary>
		public void Run()
		{
			try
			{
				RunCode();
			}
			catch (Exception ex)
			{
				Console.WriteLine("Exception {0}", ex.Message);
				Console.WriteLine(ex.StackTrace);
			}
		}
		/// <summary>
		/// Virtual method the the translated should override
		/// </summary>
		public virtual void RunCode()
		{
		}
	}
}
