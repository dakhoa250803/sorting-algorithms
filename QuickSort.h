#ifndef __QUICK_SORT__
#define __QUICK_SORT__

#include "ISortingStrategy.h"
#include "SortingBase.h"

template <class T> class QuickSort : public ISortingStrategy<T>,SortingBase<T> {
	public:
		T* sort(T* sourceArr, size_t length, SORT_TYPE sortType = SORT_ASC);
		void subscribe(string event, HandlerFn handlerFn);
	
	private:
		T _partition(T* arr, T low, T high);
		void _quickSort(T* arr, size_t lowIdx, size_t highIdx);
};



#endif
