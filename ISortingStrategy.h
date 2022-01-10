#ifndef __SORTING_STRATEGY__
#define __SORTING_STRATEGY__

template <class T> class ISortingStrategy {
	public:
		virtual T* sort(T* sourceArr) = 0;
};

#endif
