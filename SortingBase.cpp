#include <cstring>

#include "SortingBase.h"

template <class T>
SortingBase<T>::SortingBase() {
	this->_eventHandlers = new vector<EventHandler>();
}

template <class T>
SortingBase<T>::~SortingBase() {
	delete this->_eventHandlers;
}

template <class T>
T* SortingBase<T>::_cloneArray(T* sourceArr, size_t length) {
	size_t blockSize = (length * sizeof(T));
	T* newArr = new T[length];
	memcpy(newArr, sourceArr, blockSize);
	return newArr;
}


template <class T>
void SortingBase<T>::_swap(T &a, T &b) {
	T c = a;
	a = b;
	b = c;
}

template <class T>
void SortingBase<T>::_subscribe(string event,HandlerFn handlerFn ){
	EventHandler handler(event, handlerFn);
	this->_eventHandlers->push_back(handler);
}

template <class T>
void SortingBase<T>::_emit(string event,size_t changedIndex){
	EventHandler foundHandler;
	
	if(this->_findEventHandler(event , foundHandler)){
		foundHandler.handle(changedIndex);
	}
}

template <class T>
bool SortingBase<T>::_findEventHandler(string event, EventHandler &handler){
	vector<EventHandler> *handlers = this->_eventHandlers;
	for(int i = 0; i < handlers->size(); ++i){
		EventHandler h = handlers->at(i);
		if(h.event == event){
			handler = h;
			return true;
		}
	}
	return false;
}

template class SortingBase<int>;
