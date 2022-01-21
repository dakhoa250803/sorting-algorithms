#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

using namespace std;

class Menu {
	public:
		Menu(string title);
		Menu(string title, string subTitle);
		~Menu();
		void addItem(string item);
		vector<string>* getItems();
		string getItemAt(size_t index);
		void render();
		
	private:
		vector<string> *_items;
		string _title;
		string _subTitle;
		
		void _renderMenuItems();
};

#endif
