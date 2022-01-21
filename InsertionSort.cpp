

#include "arrayUtils.h"
#include "InsertionSort.h"

template <class T>
T* InsertionSort<T>::sort(T* sourceArr, size_t length, SORT_TYPE sortType) {
	T* sortedArr = this->_cloneArray(sourceArr, length);
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
    } 
		
	return sortedArr;
}

template class InsertionSort<int>;
