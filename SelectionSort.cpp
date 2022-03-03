#include "arrayUtils.h"
#include "SelectionSort.h"

template <class T>
T* SelectionSort<T>::sort(T* sourceArr, size_t length, SORT_TYPE sortType) {
//	T* sortedArr = this->_cloneArray(sourceArr, length);
	T* sortedArr = sourceArr;
	for (size_t i = 0; i < length-1; i++) {
		size_t selected_idx = i;
		for (size_t k = i+1; k < length; k++) {
			short cmp = compare(sortedArr[selected_idx], sortedArr[k]);
			if (cmp == sortType) {
				selected_idx = k;
			}
		}
		this->_swap(sortedArr[i], sortedArr[selected_idx]);
		this->_emit("sortItem", i);
	}
	return sortedArr;
}

template <class T>
void SelectionSort<T>::subscribe(string event, HandlerFn handleFn) {
	this->_subscribe(event, handleFn);
}

template class SelectionSort<int>;

