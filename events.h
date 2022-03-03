#ifndef EVENTS_H
#define EVENTS_H

#include <string>
using namespace std;


typedef void (*HandlerFn)(size_t changedIndex);

struct EventHandler {
	EventHandler() {
	}

	EventHandler(string event, HandlerFn handleFn) {
		this->event = event;
		this->handle = handleFn;
	}

	string event;
	HandlerFn handle;
};

#endif

