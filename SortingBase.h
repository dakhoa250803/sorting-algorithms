#ifndef __SORTING_BASE__
#define __SORTING_BASE__

#include <string>
#include <vector>

#include "event.h"

using namespace std;


template <class T> class SortingBase {
	public:
		SortingBase();
		~SortingBase();
		
	protected:	
		T* _cloneArray(T* sourceArr, size_t length); 
		void _swap(T &a, T &b);
		void _subscribe(string event, HandlerFn handler);
		void _emit(string event, size_t changedIndex);
		
	private:
		vector<EventHandler> *_eventHandlers;
		bool _findEventHandler(string event, EventHandler &handler);
};

#endif
