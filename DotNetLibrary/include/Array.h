#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  Array : public Object
	{
		DataType	dataType;				// type of data in array
		int32_t		dimension1Size;			// size of dimension 1
		int32_t		dimension2Size;			// size of dimension 2
		int32_t		dimension3Size;			// size of dimension 3
		int32_t		dimensionCount;			// amount of dimensions
		int32_t		totalElementCount;		// total elements in the array
		void*		 data;					// point to data storage for array
	public:
		Array(DataType dataType, Int32 dimension1Size, Int32 dimension2Size = -1, Int32 dimension3Size = -1) {
			this->dataType = dataType;
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
			data = new Byte[totalElementCount * DataTypeSize[dataType]];
		}
		virtual ~Array() {
			if (data != nullptr)
				delete data;
		}
		Object*	GetValue(Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
			return(nullptr);
		}
		void	SetValue(Object* value, Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
		}
		void	SetValue(Object* value, Array* indexes) {
		}
		void* Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
			Int32 idx = index1 * DataTypeSize[dataType];
			return(((char*)data) + idx);
		}
		Array* Initialize(void* initData) {
			return(this);
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
		void	CopyTo(Array* array1, Int32 amount) {
		}
		void	SetValue(Object value, Array* array1) {

		}
		void	SetValue(Object value, Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {

		}
		Object*	GetValue(Array* indexes) {
			return(0);
		}
		virtual void	Copy(Array* array1, Int32 amount)
		{
		};
		virtual void	Clear(Int32 startingIndex, Int32 amount)
		{
		};
		static void  Copy(Array* array1, Array* array2, Int32 amount) {
		}
		static void  Clear(Array* array1, Int32 startingIndex, Int32 amount) {
		}
		static Array*  Empty() {
			return(nullptr);
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
