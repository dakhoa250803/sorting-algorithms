

#include "arrayUtils.h"
#include "BubbleSort.h"

template <class T>
T* BubbleSort<T>::sort(T* sourceArr, size_t length, SORT_TYPE sortType) {
//	T* sortedArr = this->_cloneArray(sourceArr, length);
	T* sortedArr = sourceArr;
	for (int i = 0; i < length-1; i++)
		for (int k = 0; k < length-i-1; k++) {
			short cmp = compare(sortedArr[k], sortedArr[k+1]);
			if (cmp == sortType) {
				this->_swap(sortedArr[k], sortedArr[k+1]);
				this->_emit("sortItem", k);
			}
		}

	return sortedArr;
}

template <class T>
void BubbleSort<T>::subscribe(string event, HandlerFn handlerFn){
	this->_subscribe(event, handlerFn);
}


template class BubbleSort<int>;
