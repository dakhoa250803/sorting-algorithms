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
		size_t size();
		size_t renderAndWait();
		
	private:
		vector<string> *_items;
		string _title;
		string _subTitle;
		int _radioBeginX;
		int _radioBeginY;
		size_t _selectedIdx;
		
		void _init();
		void _renderMenuItems();
		void _renderTitle();
		size_t _waitForUserSelection();
		void _navigate(KeyCode pressedKey);
		void _check();
		void _uncheck();
};

#endif
