#include "DotNetLibrarySupport.h"
#include <stdlib.h>

void DotnetLibrarySupport::TranslatorSupport::Send(String* message)
{
	printf("%ls\n",message->get_Buffer());
}

void DotnetLibrarySupport::TranslatorSupport::Run()
{
	try {
		RunCode();
	}
	catch (Exception * ex) {
		Send(ex->get_Message());
	}
}
