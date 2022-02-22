#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__

#include "ISortingStrategy.h"
#include "SortingBase.h"

template <class T> class InsertionSort : public ISortingStrategy<T>,SortingBase<T> {
	public:
		T* sort(T* sourceArr, size_t length, SORT_TYPE sortType = SORT_ASC);
		void subscribe(string event, HandlerFn handlerFn);

};

#endif
