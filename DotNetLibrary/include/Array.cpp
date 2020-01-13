#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Array::Array(DataType dataType, Int32 dimension1Size, Int32 dimension2Size, Int32 dimension3Size) {
		this->dataType = dataType;
		this->dimension1Size = dimension1Size;
		this->dimension2Size = dimension2Size;
		this->dimension3Size = dimension3Size;
		dimensionCount = 1;
		totalElementCount = dimension1Size;
		if (dimension2Size != -1)
		{
			++dimensionCount;
			totalElementCount *= dimension2Size;
		}
		if (dimension3Size != -1)
		{
			++dimensionCount;
			totalElementCount *= dimension3Size;
		}
		data = new char[totalElementCount * DataTypeSize[dataType]];
	}
	Array::~Array() {
		if (data != nullptr)
			delete data;
		data = nullptr;
	}
	void* Array::Address(Int32 index1, Int32 index2, Int32 index3)
	{
		return &((char*)data)[ComputeIndex(index1, index2, index3) * DataTypeSize[dataType]];
	}
	void Array::Clear(Array* array, Int32 startingIndex, Int32 amount)
	{
		if (array == nullptr)
			throw new ArgumentNullException;
		array->EnsureSingleDimension();
		Int32	elementSize = DataTypeSize[array->dataType];
		VerifyIndexWithinRangeOfArray(array, startingIndex, amount);
		memset((char*)array->data + (startingIndex * elementSize), 0, (amount * elementSize));
	}
	void Array::ConstrainedCopy(Array* sourceArray, int sourceIndex, Array* destinationArray, int destinationIndex, int length)
	{
		Copy(sourceArray, sourceIndex, destinationArray, destinationIndex,length);
	}
	void Array::Copy(Array* sourceArray, Array* destinationArray, Int32 length)
	{
		Copy(sourceArray, 0, destinationArray, 0, length);
	}
	void Array::Copy(Array* sourceArray, int sourceIndex, Array* destinationArray, int destinationIndex, int length)
	{
		if (sourceArray == nullptr || destinationArray == nullptr)
			throw new ArgumentNullException;
		Int32	elementSize = DataTypeSize[sourceArray->dataType];
		if (length < 0)
			throw new ArgumentOutOfRangeException();
		if (sourceIndex < 0 || destinationIndex < 0)
			throw new ArgumentException();
		if (sourceIndex + length > sourceArray->totalElementCount || destinationIndex + length > destinationArray->totalElementCount)
			throw new ArgumentException();
		if (sourceArray->get_Rank() != destinationArray->get_Rank())
			throw new RankException();
		if (sourceArray->dataType != destinationArray->dataType)
			throw new NotImplementedException();
		void* dstAddr = destinationArray->data + (destinationIndex * elementSize);
		void* srcAddr = sourceArray->data + (sourceIndex * elementSize);
		Int32	tsz = length * elementSize;
		memcpy(dstAddr, srcAddr, tsz);
	}
	void Array::CopyTo(Array* array, Int32 index)
	{
		if (array == nullptr)
			throw new ArgumentNullException;
		array->EnsureSingleDimension();
		VerifyIndexWithinRangeOfArray(array, index, get_Length());
		Copy(this, 0, array, index, dimension1Size);
	}
	Int32 Array::ComputeIndex(Int32 index1, Int32 index2, Int32 index3)
	{
		Int32 index = 0;
		switch (dimensionCount)
		{
		case	1:
			if (index1 < 0 || index2 >= 0 || index3 >= 0)
				throw new IndexOutOfRangeException();
			if (index1 >= dimension1Size)
				throw new IndexOutOfRangeException();
			index = index1;
			break;
		case	2:
			if (index1 < 0 || index2 < 0 || index3 >= 0)
				throw new IndexOutOfRangeException();
			if (index1 >= dimension1Size || index2 >= dimension2Size)
				throw new IndexOutOfRangeException();
			index = index1 * dimension2Size + index2;
			break;
		case	3:
			if (index1 < 0 || index2 < 0 || index3 < 0)
				throw new IndexOutOfRangeException();
			if (index1 >= dimension1Size || index2 >= dimension2Size || index3 >= dimension3Size)
				throw new IndexOutOfRangeException();
			index = ((index1 * dimension2Size * dimension3Size) + (index2 * dimension3Size)) + index3;
			break;
		}
		return index;
	}
	void Array::EnsureSingleDimension()
	{
		if (dimensionCount != 1)
			throw new RankException();
	}
	Int32 Array::GetLength(Int32 rank)
	{
		if (rank > dimensionCount)
			throw new IndexOutOfRangeException();
		if (rank == 0)
			return(dimension1Size);
		else if (rank == 1)
			return(dimension2Size);
		else if (rank == 2)
			return(dimension3Size);
		return(-1);
	}
	Int32 Array::GetLowerBound(Int32 rank)
	{
		if (rank > dimensionCount)
			throw new IndexOutOfRangeException();
		return(0);
	}
	Int32 Array::GetUpperBound(Int32 rank)
	{
		if (rank > dimensionCount)
			throw new IndexOutOfRangeException();
		return(GetLength(rank) - 1);
	}
	Object* Array::GetValue(Array* indexes)
	{
		if (indexes == nullptr)
			throw new ArgumentNullException;
		indexes->EnsureSingleDimension();
		Int32	arraySize = indexes->dimension1Size;
		if (arraySize > 3)
			throw new NotImplementedException();
		if (arraySize == 0)
			return(nullptr);
		Int32	index1 = *(Int32*)indexes->Address(0, -1, -1);
		Int32	index2 = arraySize > 1 ? *(Int32*)indexes->Address(1, -1, -1) : -1;
		Int32	index3 = arraySize > 2 ? *(Int32*)indexes->Address(2, -1, -1) : -1;
		return(GetValue(index1, index2, index3));
	}
	Object* Array::GetValue(Int32 index1, Int32 index2, Int32 index3)
	{
		void* address = Address(index1, index2, index3);
		switch (dataType)
		{
		case NullType:
			break;
		case ObjectType:
			return(*((Object**)address));
		case BooleanType:
			return(new BooleanValue(*((Boolean*)address)));
		case CharType:
			return(new CharValue(*((Char*)address)));
		case SByteType:
			return(new SByteValue(*((SByte*)address)));
		case ByteType:
			return(new ByteValue(*((Byte*)address)));
		case Int16Type:
			return(new Int16Value(*((Int16*)address)));
		case UInt16Type:
			return(new UInt16Value(*((UInt16*)address)));
		case Int32Type:
			return(new Int32Value(*((Int32*)address)));
		case UInt32Type:
			return(new UInt32Value(*((UInt32*)address)));
		case Int64Type:
			return(new Int64Value(*((Int64*)address)));
		case UInt64Type:
			return(new UInt64Value(*((UInt64*)address)));
		case SingleType:
			return(new SingleValue(*((Single*)address)));
		case DoubleType:
			return(new DoubleValue(*((Double*)address)));
		case DecimalType:
			throw new InvalidCastException();
			break;
		case DateTimeType:
			return(new DateTimeValue(*((DateTime*)address)));
		case TimeSpanType:
			return(new TimeSpanValue(*((TimeSpan*)address)));
		case StringType:
			return(*((Object**)address));
		}
		return(nullptr);
	}
	Int32 Array::IndexOf(Array* array, Object* value, Int32 startIndex, Int32 count)
	{
		if (array == nullptr)
			throw new ArgumentNullException();
		if (array->get_Rank() != 1)
			throw new RankException();
		if (count < 0) {
			count = array->get_Length() - startIndex;
		}
		Int32 lb = array->GetLowerBound(0);
		if (startIndex < lb || startIndex > array->get_Length() + lb)
			throw new ArgumentOutOfRangeException();
		if (count < 0 || count > array->get_Length() - startIndex + lb)
			throw new ArgumentOutOfRangeException();
		if (array->GetElementType() != ObjectType && array->GetElementType() != StringType)
			throw new NotImplementedException();
		Int32 endIndex = startIndex + count;
		for (int i = startIndex; i < endIndex; i++) {
			Object* obj = array->GetValue(i);
			if (obj == nullptr) {
				if (value == nullptr)
					return i;
			}
			else {
				if (obj->Equals(value))
					return i;
			}
		}
		return (lb - 1);
	}
	Int32 Array::get_Length()
	{
		return(totalElementCount);
	}
	Int32 Array::get_Rank()
	{
		return(dimensionCount);
	}
	Array* Array::Initialize(void* initialData)
	{
		Int32	amountToCopy = totalElementCount * DataTypeSize[dataType];
		memcpy(data, initialData, amountToCopy);
		return(this);
	}
	void Array::SetValue(Object* value, Int32 index1, Int32 index2, Int32 index3)
	{
		if (value == nullptr)
			throw new ArgumentNullException();
		void* addr = Address(index1, index2, index3);
		switch (dataType)
		{
		case ObjectType:
			*((Object**)addr) = value;
			break;
		case StringType:
			*((Object**)addr) = value;
			break;
		case BooleanType:
			*((Boolean*)addr) = value->get_AsBoolean();
			break;
		case CharType:
			*((Char*)addr) = value->get_AsChar();
			break;
		case ByteType:
			*((Byte*)addr) = value->get_AsInt32();
			break;
		case SByteType:
			*((SByte*)addr) = value->get_AsInt32();
			break;
		case Int16Type:
			*((Int16*)addr) = value->get_AsInt32();
			break;
		case UInt16Type:
			*((UInt16*)addr) = value->get_AsUInt32();
			break;
		case Int32Type:
			*((Int32*)addr) = value->get_AsInt32();
			break;
		case UInt32Type:
			*((UInt32*)addr) = value->get_AsUInt32();
			break;
		case Int64Type:
			*((Int64*)addr) = value->get_AsInt64();
			break;
		case UInt64Type:
			*((UInt64*)addr) = value->get_AsInt64();
			break;
		case SingleType:
			*((Single*)addr) = value->get_AsSingle();
			break;
		case DoubleType:
			*((Double*)addr) = value->get_AsDouble();
			break;
		case DateTimeType:
			*((DateTime*)addr) = value->get_AsDateTime();
			break;
		case TimeSpanType:
			*((TimeSpan*)addr) = value->get_AsTimeSpan();
			break;
		default:
			throw new InvalidCastException();
			break;
		}
	}
	void Array::SetValue(Object* value, Array* indexes)
	{
		if (indexes == nullptr)
			throw new ArgumentNullException;
		indexes->EnsureSingleDimension();
		Int32	arraySize = indexes->dimension1Size;
		if (arraySize > 3)
			throw new NotImplementedException();
		if (arraySize == 0)
			return;
		Int32	index1 = *(Int32*)indexes->Address(0, -1, -1);
		Int32	index2 = arraySize > 1 ? *(Int32*)indexes->Address(1, -1, -1) : -1;
		Int32	index3 = arraySize > 2 ? *(Int32*)indexes->Address(2, -1, -1) : -1;
		SetValue(value, index1, index2, index3);
	}
	void Array::VerifyIndexWithinRangeOfArray(Array* array, Int32 startingIndex, Int32 amountOfElements)
	{
		if (array == nullptr)
			new ArgumentNullException();
		array->EnsureSingleDimension();
		if (amountOfElements < 0)
			new ArgumentNullException();
		if (startingIndex < 0)
			new ArgumentNullException();
		if ((startingIndex + amountOfElements) > array->dimension1Size)
			new ArgumentNullException();
	}
}
