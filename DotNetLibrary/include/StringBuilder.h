#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class StringBuilder : public Object
	{
	public:
		StringBuilder() {
		}
		StringBuilder(Int32 capacity) {
		}
		StringBuilder(String* value, Int32 startIndex = -1, Int32 length = -1, Int32 capacity = -1) {
		}
		StringBuilder(Int32 capacity, Int32 maxCapacity) {
		}
		Char* Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
			return(nullptr);
		}
		Int32 get_Length() { return(0); }
		void set_Length(Int32 newLength) {}
		Int32 get_Capacity() { return(0); }
		void set_Capacity(Int32 capacity) {}
		Int32 get_MaxCapacity() { return(0); }
		Char get_Chars(Int32 index) { return (0); }
		void set_Chars(Int32 index, Char newChar) {}
		String* ToString(Int32 startIndex = -1, Int32 length = -1) {
			return(nullptr);
		}
		StringBuilder* Append(Array* values, Int32 startIndex = -1, Int32 charCount = -1) { return(this); }
		StringBuilder* Append(Boolean value) { return(this); }
		StringBuilder* Append(Byte value) { return(this); }
		StringBuilder* Append(Double value) { return(this); }
		StringBuilder* Append(Int16 value) { return(this); }
		StringBuilder* Append(Int32 value) { return(this); }
		StringBuilder* Append(Int64 value) { return(this); }
		StringBuilder* Append(Object* value) { return(this); }
		StringBuilder* Append(Char value, Int32 repeatCount = -1) { return(this); }
		StringBuilder* Append(String* value, Int32 startIndex = -1, Int32 charCount = -1) { return(this); }
		StringBuilder* Append(SByte value) { return(this); }
		StringBuilder* Append(Single value) { return(this); }
		StringBuilder* Append(UInt16 value) { return(this); }
		StringBuilder* Append(UInt32 value) { return(this); }
		StringBuilder* Append(UInt64 value) { return(this); }
		StringBuilder* AppendFormat(String* format, Object* arg0) { return(this); }
		StringBuilder* AppendFormat(String* format, Array* args) { return(this); }
		StringBuilder* AppendFormat(String* format, Object* arg0, Object* arg1) { return(this); }
		StringBuilder* AppendFormat(String* format, Object* arg0, Object* arg1, Object* arg2) { return(this); }
		Int32			EnsureCapacity(Int32 capacity) {}
		StringBuilder* Remove(Int32 startIndex, Int32 length) { return(this); }
		StringBuilder*	Insert(const Int32 index, const Boolean value) { return(this); }
		StringBuilder*	Insert(const Int32 index, const Byte value) { return(this); }
		StringBuilder*	Insert(const Int32 index, const Char value) { return(this); }
		StringBuilder*	Insert(const Int32 index, Array* value) { return(this); }
		StringBuilder*	Insert(const Int32 index, Double value) { return(this); }
		StringBuilder*	Insert(const Int32 index, const Int16 value) { return(this); }
		StringBuilder*	Insert(const Int32 index, Int32 value) { return(this); }
		StringBuilder*	Insert(const Int32 index, Int64 value) { return(this); }
		StringBuilder*	Insert(const Int32 index, Object* value) { return(this); }
		StringBuilder*	Insert(const Int32 index, String* value) { return(this); }
		StringBuilder*	Insert(const Int32 index, const SByte value) { return(this); }
		StringBuilder*	Insert(const Int32 index, const Single value) { return(this); }
		StringBuilder*	Insert(const Int32 index, const UInt16 value) { return(this); }
		StringBuilder*	Insert(const Int32 index, UInt32 value) { return(this); }
		StringBuilder*	Insert(const Int32 index, const UInt64 value) { return(this); }
		StringBuilder*	Insert(const Int32 index, String* value, const Int32 count) { return(this); }
		StringBuilder*	Insert(const Int32 index, Array* value, const Int32 startIndex, const Int32 charCount) { return(this); }
		StringBuilder*	Replace(const Char oldChar, const Char newChar) { return(this); }
		StringBuilder*	Replace(String* oldValue, String* newValue) { return(this); }
		StringBuilder*	Replace(const Char oldChar, const Char newChar, const Int32 startIndex, const Int32 count) { return(this); }
		StringBuilder*	Replace(String* oldValue, String* newValue, const Int32 startIndex, const Int32 count) { return(this); }
	};
}