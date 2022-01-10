#ifndef __BUBBLE_SORT__
#define __BUBBLE_SORT__

#include "ISortingStrategy.h"

template <class T> class BubbleSort : public ISortingStrategy<T> {
	public:
		T* sort(T* sourceArr);

	private:
		T* _cloneArray(T* sourceArr, size_t length);
};

#endif
