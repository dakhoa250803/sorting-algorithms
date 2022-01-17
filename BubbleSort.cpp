

#include "arrayUtils.h"
#include "BubbleSort.h"

template <class T>
T* BubbleSort<T>::sort(T* sourceArr, size_t length, SORT_TYPE sortType) {
	T* sortedArr = this->_cloneArray(sourceArr, length);
	for (int i = 0; i < length-1; i++)
		for (int k = 0; k < length-i-1; k++) {
			short cmp = compare(sortedArr[k], sortedArr[k+1]);
			if (cmp == sortType) {
				this->_swap(sortedArr[k], sortedArr[k+1]);
			}
		}

	return sortedArr;
}

// clone  => 2 arrays => clone => 3 arr
// resize => 1 bigger/smaller array

//template <class T>
//T* BubbleSort<T>::_cloneArray(T* sourceArr, size_t length) {
//	size_t blockSize = (length * sizeof(T));
////	T* newArr = (T*)malloc(blockSize);
//	T* newArr = new T[length];
//	memcpy(newArr, sourceArr, blockSize);
//	return newArr;
//}
//
//template <class T>
//void BubbleSort<T>::_swap(T &a, T &b) {
//	T c = a;
//	a = b;
//	b = c;
//}

template class BubbleSort<int>;
