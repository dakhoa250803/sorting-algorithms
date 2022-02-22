#ifndef __SELECTION_SORT__
#define __SELECTION_SORT__

#include "ISortingStrategy.h"
#include "SortingBase.h"

template <class T> class SelectionSort : public ISortingStrategy<T>,SortingBase<T> {
	public:
		T* sort(T* sourceArr, size_t length, SORT_TYPE sortType = SORT_ASC);
		void subscribe(string event, HandlerFn handlerFn);

//	private:
//		T* _cloneArray(T* sourceArr, size_t length);
//		void _swap(T &a, T &b);
};

#endif
