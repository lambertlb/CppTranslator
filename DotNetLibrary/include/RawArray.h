#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	template< typename T >
	class RawArray : public RawObject
	{
		int32_t		dimension1Size;			// size of dimension 1
		int32_t		dimension2Size;			// size of dimension 2
		int32_t		dimension3Size;			// size of dimension 3
		int32_t		dimensionCount;			// amount of dimensions
		int32_t		totalElementCount;		// total elements in the array
		T*			data;					// point to data storage for array
	public:
		RawArray(Int32 dimension1Size, Int32 dimension2Size = -1, Int32 dimension3Size = -1) {
			this->dimension1Size = dimension1Size;
			this->dimension2Size = dimension2Size;
			this->dimension3Size = dimension2Size;
			dimensionCount = 1;
			totalElementCount = dimension1Size;
			if (dimension2Size != -1)
			{
				++dimensionCount;
				totalElementCount += dimension2Size;
			}
			if (dimension3Size != -1)
			{
				++dimensionCount;
				totalElementCount += dimension3Size;
			}
			data = new T[totalElementCount];
		}
		virtual ~RawArray() {
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
		static	PointerType<RawArray<T>>	CreateArray(Int32 dimension1Size, Int32 dimension2Size = -1, Int32 dimension3Size = -1) {
			return (new RawArray<T>(dimension1Size, dimension2Size = -1, dimension3Size));
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
