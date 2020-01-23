#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
#define DefaultCapacity 128 // default internal buffer size
#define MaximumCapacity Int32Value::MaxValue// Maximum string builder capacity
	class DLL_EXPORT StringBuilder : public Object
	{
	private:
		Char	internalMemory[DefaultCapacity + 1]; // default memory to prevent allocations
		Char*	chunkChars;		// array of characters
		Int32	currentCapacity;	// total size of the array
		Int32	currentLength;	// current offset into array for next insters
		Int32	maxCapacity;	// max capacity for this builder
	public:
		StringBuilder();
		StringBuilder(Int32 capacity);
		StringBuilder(Int32 capacity, Int32 maxCapacity);
		StringBuilder(String* value, Int32 capacity = DefaultCapacity);
		StringBuilder(String* value, Int32 startIndex, Int32 length, Int32 capacity);
		virtual				~StringBuilder();
		Boolean				IsInternal() { return(chunkChars == internalMemory); }
		Char*				get_Buffer() { return(chunkChars); }
		void				Initialize();
		Char*				Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		Int32				CountSubStrings(String* subString, Int32 startIndex, Int32 length);
		virtual DataType	GetRawDataType() { return(ObjectType); };
		Int32				get_Length();
		void				set_Length(Int32 newLength);
		Int32				get_Capacity();
		void				set_Capacity(Int32 capacity);
		Int32				get_MaxCapacity();
		Char				get_Chars(Int32 index);
		void				set_Chars(Int32 index, Char newChar);
		virtual String*		ToString();
		virtual String*		ToString(Int32 startIndex, Int32 length);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		StringBuilder*		Append(const Char* values, Int32 charCount, Int32 where = -1);
		StringBuilder*		Append(Array* values, Int32 startIndex = -1, Int32 charCount = -1);
		StringBuilder*		Append(ValueType& value, Int32 index = -1);
		StringBuilder*		Append(Boolean value);
		StringBuilder*		Append(Byte value);
		StringBuilder*		Append(Double value);
		StringBuilder*		Append(Int16 value);
		StringBuilder*		Append(Int32 value);
		StringBuilder*		Append(Int64 value);
		StringBuilder*		Append(Object* value);
		StringBuilder*		Append(Char value);
		StringBuilder*		Append(Char value, Int32 repeatCount);
		StringBuilder*		Append(String* value, Int32 startIndex = 0, Int32 charCount = -1);
		StringBuilder*		Append(SByte value);
		StringBuilder*		Append(Single value);
		StringBuilder*		Append(UInt16 value);
		StringBuilder*		Append(UInt32 value);
		StringBuilder*		Append(UInt64 value);
		StringBuilder*		AppendFormat(String* format, Object* arg0);
		StringBuilder*		AppendFormat(String* format, Array* args);
		StringBuilder*		AppendFormat(String* format, Object* arg0, Object* arg1);
		StringBuilder*		AppendFormat(String* format, Object* arg0, Object* arg1, Object* arg2);
		void				EnsureRoomFor(Int32 amount);
		Int32				EnsureCapacity(Int32 capacity);
		virtual Boolean		Equals(Object* object);
		virtual Boolean		Equals(StringBuilder* object);
		StringBuilder*		Remove(Int32 startIndex, Int32 length);
		StringBuilder*		Insert(const Int32 index, const Boolean value);
		StringBuilder*		Insert(const Int32 index, const Byte value);
		StringBuilder*		Insert(const Int32 index, const Char value);
		StringBuilder*		Insert(const Int32 index, Array* value, Int32 startIndex = -1, Int32 charCount = -1);
		StringBuilder*		Insert(const Int32 index, Double value);
		StringBuilder*		Insert(const Int32 index, const Int16 value);
		StringBuilder*		Insert(const Int32 index, Int32 value);
		StringBuilder*		Insert(const Int32 index, Int64 value);
		StringBuilder*		Insert(const Int32 index, Object* value);
		StringBuilder*		Insert(const Int32 index, String* value, Int32 count = 1);
		StringBuilder*		Insert(const Int32 index, const SByte value);
		StringBuilder*		Insert(const Int32 index, const Single value);
		StringBuilder*		Insert(const Int32 index, const UInt16 value);
		StringBuilder*		Insert(const Int32 index, UInt32 value);
		StringBuilder*		Insert(const Int32 index, const UInt64 value);
		StringBuilder*		Replace(const Char oldChar, const Char newChar);
		StringBuilder*		Replace(String* search, String* replace);
		StringBuilder*		Replace(const Char oldChar, const Char newChar, const Int32 startIndex, const Int32 count);
		StringBuilder*		Replace(String* search, String* replace, const Int32 startIndex, const Int32 count);
		void				ReplaceSubString(String* search, String* replace, const Int32 startIndex, const Int32 count);
	};
}
