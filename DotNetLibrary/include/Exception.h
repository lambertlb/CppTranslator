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
#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	/**
	 * Base Exception class
	 */
	struct DLL_EXPORT Exception: public Object
	{
	private:
		String* message;
		Exception* innerException;

	public:
		/**
		 * Null Constructor
		 */
		Exception() {
			message = nullptr;
			innerException = nullptr;
		}
		/**
		 * Exception with this message
		 * @param msg message
		 */
		Exception(String* msg) {
			message = msg;
			innerException = nullptr;
		}
		/**
		 * Exception with message and inner exception
		 * @param msg message
		 * @param innerException inner exception
		 */
		Exception(String* msg, Exception* innerException) {
			message = msg;
			this->innerException = innerException;
		}
		/**
		 * Get message
		 * @return message
		 */
		String* get_Message() {
			return (message);
		}
		/**
		 * get inner exception
		 * @return inner exception
		 */
		Exception* get_InnerException() {
			return (innerException);
		}
		/**
		 * get base exception
		 * @return base exception
		 */
		Exception* GetBaseException() {
			return (innerException);
		}
		/**
		 * Get raw type of this boxed object
		 * @return raw type
		 */
		virtual DataType GetRawDataType() {
			return (ObjectType);
		}
	};
	/**
	 * Index out of range exception
	 */
	struct DLL_EXPORT IndexOutOfRangeException: public Exception
	{
	public:
		IndexOutOfRangeException() : Exception(new String(L"Index out of range")) {
		}
	};
	/**
	 * Null argument exception
	 */
	struct DLL_EXPORT ArgumentNullException: public Exception
	{
	public:
		ArgumentNullException() : Exception(new String(L"Arguement is null")) {
		}
	};
	/**
	 * rank exception
	 */
	struct DLL_EXPORT RankException: public Exception
	{
	public:
		RankException() : Exception(new String(L"Rank exception")) {
		}
	};
	/**
	 * Argument out of range
	 */
	struct DLL_EXPORT ArgumentOutOfRangeException: public Exception
	{
	public:
		ArgumentOutOfRangeException() : Exception(new String(L"Arguement out of range")) {
		}
	};
	/**
	 * Bad Argument
	 */
	struct DLL_EXPORT ArgumentException: public Exception
	{
	public:
		ArgumentException() : Exception(new String(L"Bad Arguement")) {
		}
	};
	/**
	 * Not implemented
	 */
	struct DLL_EXPORT NotImplementedException: public Exception
	{
	public:
		NotImplementedException() : Exception(new String(L"Functionality not implemented")) {
		}
	};
	/**
	 * Invalid cast
	 */
	struct DLL_EXPORT InvalidCastException: public Exception
	{
	public:
		InvalidCastException() : Exception(new String(L"Invalid Cast")) {
		}
	};
	/**
	 * Invalid operation
	 */
	struct DLL_EXPORT InvalidOperationException: public Exception
	{
	public:
		InvalidOperationException() : Exception(new String(L"Invalid Operation")) {
		}
	};
	/**
	 * Bad format
	 */
	struct DLL_EXPORT FormatException: public Exception
	{
	public:
		FormatException() : Exception(new String(L"Bad Format")) {
		}
	};
	/**
	 * Overflow
	 */
	struct DLL_EXPORT OverflowException: public Exception
	{
	public:
		OverflowException() : Exception(new String(L"Overflow")) {
		}
	};
	/**
	 * Max min exception
	 */
	struct DLL_EXPORT ThrowMinMaxException: public Exception
	{
	public:
		ThrowMinMaxException() : Exception(new String(L"Overflow")) {
		}
	};
	/**
	 * Arithmetic exception
	 */
	struct DLL_EXPORT ArithmeticException: public Exception
	{
	public:
		ArithmeticException() : Exception(new String(L"Overflow")) {
		}
	};
	/**
	 * Divide by Zero
	 */
	struct DLL_EXPORT DivideByZeroException: public Exception
	{
	public:
		DivideByZeroException() : Exception(new String(L"Divide by Zero")) {
		}
	};
}
