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
	/*!
	 * Emulator for .Net array class.
	 * This handles up to three dimensional arrays.
	 */
	class DLL_EXPORT Array: public Object
	{
	private:
		DataType dataType;				// type of data in array
		int32_t dimension1Size;			// size of dimension 1
		int32_t dimension2Size;			// size of dimension 2
		int32_t dimension3Size;			// size of dimension 3
		int32_t dimensionCount;			// amount of dimensions
		int32_t totalElementCount;		// total elements in the array
		char* data;						// point to data storage for array
		/**
		 * Compute index into 1d array from 3d indexes
		 * @param index1 index to 1st dimension
		 * @param index2 index to 2nd dimension or -1 if not used
		 * @param index3 index to 3rd dimension or -1 if not used
		 * @return index into 1d array
		 */
		Int32 ComputeIndex(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		/**
		 * Make sure range of indexes fits in the 1d array.
		 * @param array to check
		 * @param startingIndex starting index
		 * @param amountOfElements amount of elements to cover
		 */
		static void VerifyIndexWithinRangeOfArray(Array* array, Int32 startingIndex, Int32 amountOfElements);
		/**
		 * Initialize internal fields with proper data
		 * @param dataType type of data in memory
		 * @param dimension1Size size of 1st dimension
		 * @param dimension2Size size of 2nd dimension or -1 if not used
		 * @param dimension3Size size of 3rd dimension or -1 if not used
		 */
		void InitializeData(DataType dataType, Int32 dimension1Size, Int32 dimension2Size, Int32 dimension3Size);

	public:
		/**
		 * Construct array with external memory.
		 * Useful for wrapping arrays in platform.
		 * @param dataMemory pointer to platform memory
		 * @param dataType type of data in memory
		 * @param dimension1Size size of 1st dimension
		 * @param dimension2Size size of 2nd dimension or -1 if not used
		 * @param dimension3Size size of 3rd dimension or -1 if not used
		 */
		Array(void* dataMemory, DataType dataType, Int32 dimension1Size, Int32 dimension2Size = -1, Int32 dimension3Size = -1);
		/**
		 * Construct array in .net world memory
		 * @param dataType type of data in memory
		 * @param dimension1Size size of 1st dimension
		 * @param dimension2Size size of 2nd dimension or -1 if not used
		 * @param dimension3Size size of 3rd dimension or -1 if not used
		 */
		Array(DataType dataType, Int32 dimension1Size, Int32 dimension2Size = -1, Int32 dimension3Size = -1);
		/**
		 * Destructor
		 */
		virtual ~Array();
		/**
		 * Get length of 1d Array
		 * @return length of 1d array
		 */
		Int32 get_Length();
		/**
		 * Get how many dimensions this array has.
		 * @return amount of dimensions
		 */
		Int32 get_Rank();
		/**
		 * Compute the address of a data item in the array.
		 * This is used in place of .net indexer
		 * @param index1 into 1st dimension
		 * @param index2 into 2nd dimension or -1
		 * @param index3 into 3rd dimension or -1
		 */
		void* Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		/**
		 * Clear out elements of an array
		 * @param array array to clear
		 * @param startingIndex starting index
		 * @param amount amount of elements to clear
		 */
		static void Clear(Array* array, Int32 startingIndex, Int32 amount);
		/**
		 * Copy items from source array to destination
		 * @param sourceArray source array
		 * @param sourceIndex starting index in source
		 * @param destinationArray destination array
		 * @param destinationIndex starting index in destination
		 * @param length how many elements to copy
		 */
		static void ConstrainedCopy(Array* sourceArray, Int32 sourceIndex, Array* destinationArray, Int32 destinationIndex, Int32 length);
		/**
		 * Copy items from source array to destination
		 * @param sourceArray source array
		 * @param destinationArray destination array
		 * @param length how many elements to copy
		 */
		static void Copy(Array* sourceArray, Array* destinationArray, Int32 length);
		/**
		 * Copy items from source array to destination
		 * @param sourceArray source array
		 * @param sourceIndex starting index in source
		 * @param destinationArray destination array
		 * @param destinationIndex starting index in destination
		 * @param length how many elements to copy
		 */
		static void Copy(Array* sourceArray, Int32 sourceIndex, Array* destinationArray, Int32 destinationIndex, Int32 length);
		/**
		 * Copy items from source array to destination
		 * @param array where to copy
		 * @param index starting index
		 */
		void CopyTo(Array* array, Int32 index);
		/**
		 * Ensure this is a single dimension array
		 */
		void EnsureSingleDimension();
		/**
		 * Array is type of object
		 * @return type of object
		 */
		virtual DataType GetRawDataType() {
			return (ObjectType);
		}
		;
		/**
		 * Type of element in array
		 * @return type of element
		 */
		virtual DataType GetElementType() {
			return (dataType);
		}
		;
		/**
		 * Get length of this dimension
		 * @param rank of dimension
		 * @return size of rank or -1 if unused
		 */
		Int32 GetLength(Int32 rank);
		/**
		 * Get low bounds of this dimension
		 * @param rank of dimension
		 * @return 0
		 */
		Int32 GetLowerBound(Int32 rank);
		/**
		 * Get upper bounds of this dimension
		 * @param rank of dimension
		 * @return 1 - dimension size
		 */
		Int32 GetUpperBound(Int32 rank);
		/**
		 * Get array element as object
		 * @param indexes indexes into array
		 * @return element as Object
		 */
		Object* GetValue(Array* indexes);
		/**
		 * Get array element as object
		 * @param index1 into 1st dimension
		 * @param index2 into 2nd dimension or -1
		 * @param index3 into 3rd dimension or -1
		 * @return element as Object
		 */
		Object* GetValue(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		/**
		 * Compute index of this items
		 * @param array array with items
		 * @param value item to look for
		 * @param startIndex starting index
		 * @param count amount of elements to look at
		 * @return index where found or -1
		 */
		static Int32 IndexOf(Array* array, Object* value, Int32 startIndex = 0, Int32 count = -1);
		/**
		 * Initialize this array with raw data array
		 * @param initData raw data array
		 * @return array pointer
		 */
		Array* Initialize(void* initData);
		/**
		 * Set Object value into array
		 * @param value to set
		 * @param index1 into 1st dimension
		 * @param index2 into 2nd dimension or -1
		 * @param index3 into 3rd dimension or -1
		 */
		void SetValue(Object* value, Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		/**
		 * Set Object value into array
		 * @param value to set
		 * @param indexes indexes into array
		 */
		void SetValue(Object* value, Array* indexes);
	};
}
