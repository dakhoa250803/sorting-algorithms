#ifndef __QUICK_SORT__
#define __QUICK_SORT__

#include "ISortingStrategy.h"
#include "SortingBase.h"

template <class T> class QuickSort : public ISortingStrategy<T>, SortingBase<T> {
	public:
		T* sort(T* arr, size_t length, SORT_TYPE sortType = SORT_ASC);
		void subscribe(string event, HandlerFn handleFn);
	private:
		size_t _partition(T* arr, size_t lowIdx, size_t highIdx);
		void _quickSort(T* arr, size_t lowIdx, size_t highIdx);
};

#endif
