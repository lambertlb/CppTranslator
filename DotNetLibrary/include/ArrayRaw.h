#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class ArrayBase : public ObjectRaw
	{
	protected:
		virtual void	Copy(ArrayBase* array1, Int32 amount) {};
		virtual void	Clear(Int32 startingIndex, Int32 amount) {};
	public:
		static void  Copy(ArrayBase* array1, ArrayBase* array2, Int32 amount) {
			array2->Copy(array1, amount);
		}
		static void  Clear(ArrayBase* array1, Int32 startingIndex, Int32 amount) {
			array1->Clear(startingIndex, amount);
		}
	};

	template< typename T >
	class  ArrayRaw : public ArrayBase
	{
		int32_t		dimension1Size;			// size of dimension 1
		int32_t		dimension2Size;			// size of dimension 2
		int32_t		dimension3Size;			// size of dimension 3
		int32_t		dimensionCount;			// amount of dimensions
		int32_t		totalElementCount;		// total elements in the array
		T* data;					// point to data storage for array
	public:
		ArrayRaw(Int32 dimension1Size, Int32 dimension2Size = -1, Int32 dimension3Size = -1) {
			this->dimension1Size = dimension1Size;
			this->dimension2Size = dimension2Size;
			this->dimension3Size = dimension2Size;
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
			data = new T[totalElementCount];
		}
		virtual ~ArrayRaw() {
			delete data;
		}
		T	GetValue(Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
			int32_t index = ComputeIndex(index1, index2, index3);
			return(data[index]);
		}
		void	SetValue(T value, Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
			int32_t index = ComputeIndex(index1, index2, index3);
			data[index] = value;
		}
		T* Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
			int32_t index = ComputeIndex(index1, index2, index3);
			return(data + index);
		}
		ArrayRaw<T>& Initialize(T* initData) {
			for (int i = 0; i < totalElementCount; ++i) {
				data[i] = initData[i];
			}
			return(*this);
		}
		Int32	GetLength(Int32 rank) {
			if (rank == 0)
				return(dimension1Size);
			else if (rank == 1)
				return(dimension2Size);
			else if (rank == 2)
				return(dimension3Size);
			return(-1);
		}
		Int32	GetLowerBound(Int32 rank) {
			return(0);
		}
		Int32	GetUpperBound(Int32 rank) {
			return(0);
		}
		Int32	get_Length() {
			return(totalElementCount);
		}
		Int32	get_Rank() {
			if (dimension3Size != -1) {
				return(3);
			}
			if (dimension2Size != -1) {
				return(2);
			}
			return(1);
		}
		void	CopyTo(ArrayBase* array1, Int32 amount) {
			ArrayRaw<T>* source = (ArrayRaw<T>*)array1;
		}
		void	SetValue(Object value, ArrayBase* array1) {

		}
		void	SetValue(Object value, Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {

		}
		T	GetValue(ArrayBase* array1) {
			return(0);
		}
		void	Clear(Int32 startIndex, Int32 amount) {

		}
	protected:
		virtual void	Copy(ArrayBase* array1, Int32 amount)
		{
			ArrayRaw<T>* source = (ArrayRaw<T>*)array1;
		}
	private:
		int32_t	ComputeIndex(Int32 index1, Int32 index2, Int32 index3) {
			int32_t index = index1;
			if (dimensionCount > 1) {
				index = index1 * dimension2Size + index2;
				if (dimensionCount > 2) {
					index = ((index1 * dimension2Size * dimension3Size) + (index2 * dimension3Size)) + index3;
				}
			}
			return(index);
		}
	};
}
