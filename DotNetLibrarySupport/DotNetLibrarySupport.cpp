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
 * Do any setup that needs happen before hand.
 */
void DotnetLibrarySupport::TranslatorSupport::Run()
{
	try {
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
 * Expose array to .Net works by wrapping it in a .Net array.
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
