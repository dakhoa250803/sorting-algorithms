

#include "arrayUtils.h"
#include "QuickSort.h"

template <class T>
T* QuickSort<T>::sort(T* sourceArr, size_t length, SORT_TYPE sortType) {
//	T* sortedArr = this->_cloneArray(sourceArr, length);
	T* sortedArr = sourceArr;
	this->_quickSort(sortedArr,0,length-1);
	return sortedArr;
}

template <class T>
T QuickSort<T>::_partition (T* arr, T low, T high)
{
	size_t midIdx = low + (high - low)/2;
	
    size_t pivot = arr[midIdx];    
    size_t left = low;
    size_t right = high;
    while(true){
        while(arr[left] < pivot) left++; 
        while(arr[right] > pivot) right--; 
        if (left >= right) break; 
        this->_swap(arr[left], arr[right]); 
        left++; 
        right--; 
    }
    return right; 
}

template <class T>
void QuickSort<T>::_quickSort(T* arr, size_t lowIdx, size_t highIdx){
	if(lowIdx >= highIdx) return;
	
	T midIdx = this->_partition(arr,lowIdx,highIdx);
	this->_quickSort(arr,lowIdx,midIdx);
	this->_quickSort(arr,midIdx + 1,highIdx);
	
}

template <class T>
void QuickSort<T>::subscribe(string event, HandlerFn handlerFn){
	this->_subscribe(event, handlerFn);
}

template class QuickSort<int>;
