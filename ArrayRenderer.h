#ifndef __ARRAY_RENDERER__
#define __ARRAY_RENDERER__

#include <windows.h>

template <class T> class ArrayRenderer {
	public:
		ArrayRenderer(T* targetArr, size_t length);
		render(COORD fromTopLeft,size_t highlightIndex);

	private:
		T* _arr;
		size_t _length;
		T _maxValue();
		
};

#endif
