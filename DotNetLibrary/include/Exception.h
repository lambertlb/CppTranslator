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
		Exception(String* msg) { message = msg; innerException = nullptr; }
		Exception(String* msg, Exception* innerException) { message = msg; this->innerException = innerException; }
		String* get_Message() { return(message); }
		Exception* get_InnerException() { return(innerException); }
		Exception* GetBaseException() { return(innerException); }
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
	struct DLL_EXPORT FormatException : public  Exception
	{
	public:
		FormatException() : Exception(new String(L"Bad Format")) {}
	};
	struct DLL_EXPORT OverflowException : public  Exception
	{
	public:
		OverflowException() : Exception(new String(L"Overflow")) {}
	};
	struct DLL_EXPORT ThrowMinMaxException : public  Exception
	{
	public:
		ThrowMinMaxException() : Exception(new String(L"Overflow")) {}
	};
	struct DLL_EXPORT ArithmeticException : public  Exception
	{
	public:
		ArithmeticException() : Exception(new String(L"Overflow")) {}
	};
	struct DLL_EXPORT DivideByZeroException : public  Exception
	{
	public:
		DivideByZeroException() : Exception(new String(L"Divide by Zero")) {}
	};
}
