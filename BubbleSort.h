#ifndef __BUBBLE_SORT__
#define __BUBBLE_SORT__

#include "ISortingStrategy.h"
#include "SortingBase.h"

template <class T> class BubbleSort : public ISortingStrategy<T>,SortingBase<T> {
	public:
		T* sort(T* sourceArr, size_t length, SORT_TYPE sortType = SORT_ASC);
		void subscribe(string event, HandlerFn handlerFn);

};



#endif
