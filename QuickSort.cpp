#include "arrayUtils.h"
#include "QuickSort.h"

template <class T>
T* QuickSort<T>::sort(T* arr, size_t length, SORT_TYPE sortType) {
	this->_quickSort(arr, 0, length - 1);
	return arr;
}

template <class T>
size_t QuickSort<T>::_partition(T* arr, size_t lowIdx, size_t highIdx) {
    size_t pivotIdx = lowIdx + (highIdx - lowIdx) / 2;
	T pivotVal = arr[pivotIdx];
    size_t leftIdx = lowIdx;
    size_t rightIdx = highIdx;
    while(true) {
        while(arr[leftIdx] < pivotVal) ++leftIdx;
        while(arr[rightIdx] > pivotVal) --rightIdx;
        if (leftIdx >= rightIdx) break;
        swap(arr[leftIdx], arr[rightIdx]);
        ++leftIdx;
        --rightIdx;
    }
    return rightIdx;
}

template <class T>
void QuickSort<T>::_quickSort(T* arr, size_t lowIdx, size_t highIdx) {
    if (lowIdx >= highIdx) return;

    size_t middleIdx = this->_partition(arr, lowIdx, highIdx);
//    if (middleIdx == 0) return;
    this->_quickSort(arr, lowIdx, middleIdx);
    this->_quickSort(arr, middleIdx + 1, highIdx);
}

template <class T>
void QuickSort<T>::subscribe(string event, HandlerFn handleFn) {
	this->_subscribe(event, handleFn);
}

template class QuickSort<int>;

