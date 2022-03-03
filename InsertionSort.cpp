#include "arrayUtils.h"
#include "InsertionSort.h"

template <class T>
T* InsertionSort<T>::sort(T* sourceArr, size_t length, SORT_TYPE sortType) {
//	T* sortedArr = this->_cloneArray(sourceArr, length);
	T* sortedArr = sourceArr;
	for (size_t i = 1; i < length; i++) {
		T pivot = sortedArr[i];
		long k = i - 1;
//		while (k >= 0 && sortedArr[k] > pivot) {
		while (k >= 0) {
			int cmp = compare(sortedArr[k], pivot);
			if (cmp != sortType) break;
			sortedArr[k+1] = sortedArr[k];
			k--;
		}
		sortedArr[k+1] = pivot;
		this->_emit("sortItem", k+1);
	}
	return sortedArr;
}

template <class T>
void InsertionSort<T>::subscribe(string event, HandlerFn handleFn) {
	this->_subscribe(event, handleFn);
}

template class InsertionSort<int>;

