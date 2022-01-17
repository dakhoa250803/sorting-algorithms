#include "arrayUtils.h"
#include "SelectionSort.h"

template <class T>
T* SelectionSort<T>::sort(T* sourceArr, size_t length, SORT_TYPE sortType) {
	T* sortedArr = this->_cloneArray(sourceArr, length);
	for (int i = 0; i < length-1; i++) {
		size_t selected_idx = i;
		for (int k = i+1; k < length; k++) {
			short cmp = compare(sortedArr[selected_idx], sortedArr[k]);
			if (cmp == sortType) {
				selected_idx = k;
			}
		}
		this->_swap(sortedArr[i], sortedArr[selected_idx]);
	}
	return sortedArr;
}

template class SelectionSort<int>;

