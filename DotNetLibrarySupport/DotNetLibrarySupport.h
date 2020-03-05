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
#pragma once
#ifdef WIN32
#pragma warning( disable : 4244 )
#pragma warning( disable : 4018 )
#pragma warning( disable : 4102 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 26812 )
#pragma warning( disable : 26495 )
#ifdef	DOTNETLIBRARYSUPPORT_EXPORTS
#define	SUPPORTDLL_EXPORT	__declspec( dllexport )
#else
#define	SUPPORTDLL_EXPORT	__declspec( dllimport )
#endif
#else
#define	SUPPORTDLL_EXPORT	
#endif
#include <DotnetTypes.h>
using namespace DotnetLibrary;

namespace DotnetLibrarySupport
{
	/*!
	 * This class exposes target platform functionality to the translated code.
	 * It should mirror the .Net based class in CppTranslatorSupport project.
	 * Every method defined there should be hand crafted here.
	 * For example the "Send" method can be used to send a string to a target platform
	 * alarm method.
	 */
	class SUPPORTDLL_EXPORT TranslatorSupport
	{
	public:
		TranslatorSupport() {};
		/*!
		 * Way to send a string to target platform from .net world.
		 * 
		 * \param message Message to send
		 */
		void	Send(String* message);
		/*!
		 * This needs to be overriden by translated code
		 * 
		 */
		virtual void	RunCode() {}
		/*!
		 * Run the translated code.
		 * This needs to do all environmental setup before calling RunCode
		 * Such as memory allocation setup
		 */
		void	Run();
	private:
	};

	/*!
	 * This class exposes target platform data to the translated code.
	 * This should mirror the DataAccess class in the CppTranslatorSupport project.
	 * 
	 */
	class SUPPORTDLL_EXPORT DataAccess : public TranslatorSupport {
	public:
		DataAccess() {};
		/*!
		 * Example of exposing a platform array into .Net world
		 * 
		 * \return Integer array
		 */
		Array* get_ArrayData();
		/*!
		 * Example of exposing a platform scalar double to .net world.
		 * 
		 * \return platform double data
		 */
		Double get_DoubleData();
	};
}
