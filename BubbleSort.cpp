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

template class BubbleSort<int>;

