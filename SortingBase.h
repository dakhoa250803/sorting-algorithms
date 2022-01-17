#ifndef __SORTING_BASE__
#define __SORTING_BASE__

#include <cstring>
//#include <stdlib.h>

template <class T> class SortingBase {
	protected:		
		T* _cloneArray(T* sourceArr, size_t length) {
			size_t blockSize = (length * sizeof(T));
			// T* newArr = (T*)malloc(blockSize)
			T* newArr = new T[length];
			memcpy(newArr, sourceArr, blockSize);
			return newArr;
		}

		void _swap(T &a, T &b) {
			T c = a;
			a = b;
			b = c;
		}
};

#endif
