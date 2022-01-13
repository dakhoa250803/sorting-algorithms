#ifndef __BUBBLE_SORT__
#define __BUBBLE_SORT__

#include "ISortingStrategy.h"

template <class T> class BubbleSort : public ISortingStrategy<T> {
	public:
		T* sort(T* sourceArr, size_t length, SORT_TYPE sortType = SORT_ASC);

	private:
		T* _cloneArray(T* sourceArr, size_t length);
		void _swap(T &a, T &b);
};

#endif
