#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "Menu.h"

Menu::Menu(string title) {
	this->_items = new vector<string>();
	this->_title = title;
	this->_subTitle = "";
}

Menu::Menu(string title, string subTitle) {
	this->_items = new vector<string>();
	this->_title = title;
	this->_subTitle = subTitle;
}

Menu::~Menu() {
	delete this->_items;
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

void Menu::render() {
	this->_renderMenuItems();
}

void Menu::_renderMenuItems() {
	clearScreen();
	cout << endl << this->_title << endl;
	if (this->_subTitle.size()) {
		cout << this->_subTitle << endl;
	}
	
	vector<string> *items = this->_items;
	cout << "[x] " << items->at(0) << endl;
	for (int i = 1; i < items->size(); i++) {
		cout << "[ ] " << items->at(i) << endl;
	}
	cout << endl;
}
