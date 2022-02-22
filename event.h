#ifndef EVENTS_H
#define EVENTS_H

#include <string>

using namespace std;

 typedef void (*HandlerFn)(size_t changedIndex);
 
 struct EventHandler{
 	EventHandler(){
	}
	
	EventHandler(string event, HandlerFn handlerFn){
		this->event = event;
		this->handle = handlerFn;
	}
	
	string event;
	HandlerFn handle;
 };
 
 #endif
