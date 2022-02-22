

#include "arrayUtils.h"
#include "InsertionSort.h"

template <class T>
T* InsertionSort<T>::sort(T* sourceArr, size_t length, SORT_TYPE sortType) {
//	T* sortedArr = this->_cloneArray(sourceArr, length);
	T* sortedArr = sourceArr;
	for (int i = 1; i < length; i++)
    { 
        T pivot = sortedArr[i]; 
        size_t k = i - 1; 
    	while (k >= 0){
    		short cmp = compare(sortedArr[k], pivot);
    		if(cmp != sortType) break;
    		sortedArr[k + 1] = sortedArr[k]; 
			k--;
    	} 
    	sortedArr[k + 1] = pivot;
    	this->_emit("sortItem", k + 1);
    } 
	return sortedArr;
}

template <class T>
void InsertionSort<T>::subscribe(string event, HandlerFn handlerFn){
	this->_subscribe(event, handlerFn);
}

template class InsertionSort<int>;
