#ifndef __SORTING_STRATEGY__
#define __SORTING_STRATEGY__

#include "event.h"

#include <string>

enum SORT_TYPE {
	SORT_INVALID = 0,
	SORT_ASC = 1,   // ascending
	SORT_DESC = -1  // descending
};

template <class T> class ISortingStrategy {
	public:
		virtual T* sort(T* sourceArr, size_t length, SORT_TYPE sortType = SORT_ASC) = 0;
		virtual void subscribe(string event, HandlerFn handlerFn) = 0;
};

#endif
