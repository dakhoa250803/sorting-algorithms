#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "keyboard.h"
#include "utils.h"
#include "Menu.h"

Menu::Menu(string title) {
	this->_title = title;
	this->_subTitle = "";
	this->_init();
}

Menu::Menu(string title, string subTitle) {
	this->_title = title;
	this->_subTitle = subTitle;
	this->_init();
}

Menu::~Menu() {
	delete this->_items;
}

void Menu::_init() {
	this->_items = new vector<string>();
	this->_selectedIdx = -1;
}

void Menu::addItem(string item) {
	this->_items->push_back(item);
}

vector<string>* Menu::getItems() {
	vector<string> *source = this->_items;
	vector<string> *clone = new vector<string>(source->size());
    std::copy(source->begin(), source->end(), clone->begin());
    return clone;
}

string Menu::getItemAt(size_t index) {
	return this->_items->at(index);
}

size_t Menu::size() {
	return this->_items->size();
}

size_t Menu::renderAndWait() {
	clearScreen();
	gotoxy(0, 0);
	this->_renderTitle();
	this->_renderMenuItems();
	return this->_waitForUserSelection();
}

void Menu::_renderMenuItems() {
	vector<string> *items = this->_items;
	for (int i = 0; i < items->size(); i++) {
		cout << "[ ] " << items->at(i) << endl;
	}
}

void Menu::_renderTitle() {
	this->_radioBeginX = 1;
	this->_radioBeginY = 4;
	cout << endl << this->_title << endl;
	if (this->_subTitle.size()) {
		cout << this->_subTitle << endl;
		++this->_radioBeginY;
	}
	cout << endl << "(Use W, S keys to navigate up, down)" << endl;
}

size_t Menu::_waitForUserSelection() {
	KeyCode key = KEY_NONE;
	this->_selectedIdx = 0;
	this->_check();

	do {
		key = getKeyPressed();
		this->_navigate(key);
	}
	while(key != KEY_ENTER && key != KEY_ESC);

	clearScreen();
	return this->_selectedIdx;
}

void Menu::_navigate(KeyCode pressedKey) {
	if (pressedKey == KEY_W) {
		this->_uncheck();
		this->_selectedIdx = std::max(0, (int)this->_selectedIdx-1);
		this->_check();
	}
	else if (pressedKey == KEY_S) {
		size_t maxIndex = this->_items->size() - 1;
		this->_uncheck();
		this->_selectedIdx = std::min((long)maxIndex, (long)this->_selectedIdx+1);
		this->_check();
	}
}

void Menu::_check() {
	printxy(
		this->_radioBeginX,
		this->_radioBeginY + this->_selectedIdx,
		"x"
	);
}

void Menu::_uncheck() {
	printxy(
		this->_radioBeginX,
		this->_radioBeginY + this->_selectedIdx,
		" "
	);
}
