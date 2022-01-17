

#include "arrayUtils.h"
#include "SelectionSort.h"

template <class T>
T* SelectionSort<T>::sort(T* sourceArr, size_t length, SORT_TYPE sortType) {
	T* sortedArr = this->_cloneArray(sourceArr, length);
	size_t selectedIndex;
	for (int i = 0; i < length-1; i++){
		selectedIndex = i;
		for (int k = i+1; k < length; k++) {
			short cmp = compare(sortedArr[selectedIndex], sortedArr[k]);
			if (cmp == sortType) {
				selectedIndex = k;
			}
		}
		this->_swap(sortedArr[i],sortedArr[selectedIndex]);
	}
		
	return sortedArr;
}

template class SelectionSort<int>;
