#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{

	struct DLL_EXPORT Exception : public  Object
	{
	private:
		String* message;
		Exception* innerException;

	public:
		Exception() { message = nullptr;  innerException = nullptr; }
		Exception(String* msg) { message = nullptr; innerException = nullptr; }
		Exception(String* msg, Exception* innerException) { message = msg; this->innerException = innerException; }
		String* get_Message() { return(message); }
		Exception* get_InnerException() { return(innerException); }
		Exception* GetBaseException() { return(nullptr); }
	};
}
