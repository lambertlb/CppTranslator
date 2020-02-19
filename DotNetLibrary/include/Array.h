#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT Array : public Object
	{
	private:
		DataType	dataType;				// type of data in array
		int32_t		dimension1Size;			// size of dimension 1
		int32_t		dimension2Size;			// size of dimension 2
		int32_t		dimension3Size;			// size of dimension 3
		int32_t		dimensionCount;			// amount of dimensions
		int32_t		totalElementCount;		// total elements in the array
		char*		data;					// point to data storage for array
		Int32			ComputeIndex(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		static void		VerifyIndexWithinRangeOfArray(Array* array, Int32 startingIndex, Int32 amountOfElements);
	public:
		Array(void *dataMemory,DataType dataType, Int32 dimension1Size, Int32 dimension2Size = -1, Int32 dimension3Size = -1);
		Array(DataType dataType, Int32 dimension1Size, Int32 dimension2Size = -1, Int32 dimension3Size = -1);
		virtual			~Array();
		Int32			get_Length();
		Int32			get_Rank();
		void*			Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		static void		Clear(Array* array, Int32 startingIndex, Int32 amount);
		static void		ConstrainedCopy(Array* sourceArray, int sourceIndex, Array* destinationArray, int destinationIndex, int length);
		static void		Copy(Array* sourceArray, Array* destinationArray, Int32 length);
		static void		Copy(Array* sourceArray, int sourceIndex, Array* destinationArray, int destinationIndex, int length);
		void			CopyTo(Array* array, Int32 index);
		void			EnsureSingleDimension();
		virtual DataType GetRawDataType() { return(ObjectType); };
		virtual DataType GetElementType() { return(dataType); };
		Int32			GetLength(Int32 rank);
		Int32			GetLowerBound(Int32 rank);
		Int32			GetUpperBound(Int32 rank);
		Object*			GetValue(Array* indexes);
		Object*			GetValue(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		static Int32	IndexOf(Array* array, Object* value, Int32 startIndex = 0, Int32 count = -1);
		Array*			Initialize(void* initData);
		void			SetValue(Object* value, Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		void			SetValue(Object* value, Array* indexes);
	};
}
