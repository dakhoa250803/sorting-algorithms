#include <cstring>
#include <stdlib.h>

#include "BubbleSort.h"

template <class T>
T* BubbleSort<T>::sort(T* sourceArr) {
	return NULL;
}

// clone  => 2 arrays => clone => 3 arr
// resize => 1 bigger/smaller array

template <class T>
T* BubbleSort<T>::_cloneArray(T* sourceArr, size_t length) {
	size_t blockSize = (length * sizeof(T));
	T* newArr = (T*)malloc(blockSize) ;
	memcpy(newArr, sourceArr, blockSize);
	return newArr;
}

template class BubbleSort<int>;

