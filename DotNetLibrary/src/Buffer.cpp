#include "DotnetTypes.h"

namespace DotnetLibrary
{
	void Buffer::BlockCopy(Array* src, Int32 srcOffset, Array* dst, Int32 dstOffset, Int32 count)
	{
		if (src == nullptr)
			throw new ArgumentNullException();
		if (dst == nullptr)
			throw new ArgumentNullException();
		src->EnsureSingleDimension();
		dst->EnsureSingleDimension();
		if (!Object::IsPrimativeType(src->GetElementType()))
			throw new ArgumentException();
		if (!Object::IsPrimativeType(dst->GetElementType()))
			throw new ArgumentException();
		if (srcOffset < 0)
			throw new ArgumentOutOfRangeException();
		if (dstOffset < 0)
			throw new ArgumentOutOfRangeException();
		if (count < 0)
			throw new ArgumentOutOfRangeException();
		UInt32	sourceLength = src->get_Length() * DataTypeSize[src->GetElementType()];
		UInt32	destinationLength = dst->get_Length() * DataTypeSize[dst->GetElementType()];
		if ((sourceLength < srcOffset + count) || (destinationLength < dstOffset + count))
			throw new ArgumentException();
		memmove((Byte*)dst->Address(0) + dstOffset, (Byte*)src->Address(0) + srcOffset, count);
	}
	Int32 Buffer::ByteLength(Array* array)
	{
		// Is the array present?
		if (array == nullptr)
			throw new ArgumentNullException();

		// Is it of primitive types?
		if (!Object::IsPrimativeType(array->GetElementType()))
			throw new ArgumentException();
		array->EnsureSingleDimension();

		Int32 byteLength = array->get_Length() * DataTypeSize[array->GetElementType()];
		return byteLength;
	}
	Byte Buffer::GetByte(Array* array, Int32 index)
	{
		// array argument validation done via ByteLength
		if (index >= ByteLength(array))
			throw new ArgumentOutOfRangeException();
		return(*(((Byte*)array->Address(0)) + index));
	}
	void Buffer::SetByte(Array* array, Int32 index, Byte value)
	{
		// array argument validation done via ByteLength
		if (index >= ByteLength(array))
			throw new ArgumentOutOfRangeException();
		*(((Byte*)array->Address(0)) + index) = value;
	}
}

