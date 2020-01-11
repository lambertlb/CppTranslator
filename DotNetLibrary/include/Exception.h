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
		virtual DataType GetRawDataType() { return(ObjectType); };
	};
	struct DLL_EXPORT IndexOutOfRangeException : public  Exception
	{
	public:
		IndexOutOfRangeException() : Exception(new String(L"Index out of range")) {}
	};
	struct DLL_EXPORT ArgumentNullException : public  Exception
	{
	public:
		ArgumentNullException() : Exception(new String(L"Arguement is null")) {}
	};
	struct DLL_EXPORT RankException : public  Exception
	{
	public:
		RankException() : Exception(new String(L"Rank exception")) {}
	};
	struct DLL_EXPORT ArgumentOutOfRangeException : public  Exception
	{
	public:
		ArgumentOutOfRangeException() : Exception(new String(L"Arguement out of range")) {}
	};
	struct DLL_EXPORT ArgumentException : public  Exception
	{
	public:
		ArgumentException() : Exception(new String(L"Bad Arguement")) {}
	};
	struct DLL_EXPORT NotImplementedException : public  Exception
	{
	public:
		NotImplementedException() : Exception(new String(L"Functionality not implemented")) {}
	};
	struct DLL_EXPORT InvalidCastException : public  Exception
	{
	public:
		InvalidCastException() : Exception(new String(L"Invalid Cast")) {}
	};
	struct DLL_EXPORT InvalidOperationException : public  Exception
	{
	public:
		InvalidOperationException() : Exception(new String(L"Invalid Operation")) {}
	};
}
