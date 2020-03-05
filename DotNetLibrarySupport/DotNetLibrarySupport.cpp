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
#include "DotNetLibrarySupport.h"
#include <stdlib.h>

/*!
 * Send a string to platform.
 * For example we just print to console.
 *
 * \param message to print
 */
void DotnetLibrarySupport::TranslatorSupport::Send(String* message)
{
	printf("%ls\n", message->get_Buffer());
}

/*!
 * Run the translated code.
 * Do any setup that needs to happen before hand.
 */
void DotnetLibrarySupport::TranslatorSupport::Run()
{
	try {
        PlatformSetup();
		RunCode();
	}
	catch (Exception * ex) {
		Send(ex->get_Message());
	}
}

/*!
 * Emulate a platform array.
 */
Int32	arrayData[]{ 1,2,3,4 };
/*!
 * Exposing an array to .Net works by wrapping it in a .Net array.
 * \return .Net array
 */
Array* DotnetLibrarySupport::DataAccess::get_ArrayData()
{
	return(new Array(arrayData, Int32Type, 4));
}

/*!
 * Expose a platform double
 */
Double doubleData = 5.5;
/*!
 * Expose double data to .Net.
 * \return double data
 */
Double DotnetLibrarySupport::DataAccess::get_DoubleData()
{
	return doubleData;
}
