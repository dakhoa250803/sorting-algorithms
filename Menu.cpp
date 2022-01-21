#include <iostream>

using namespace std;

void showMenu(){
	cout << "Please choose! " << endl;
	cout << "1. Selection Sort"<<endl;
	cout << "2. Bubble Sort"<<endl;
	cout << "3. Insertion Sort"<<endl;
	cout << "0. Exit"<<endl;
}

int chooseMenu(){
	cout << "Choose menu: ";
	int n = 0;
	cin >> n;
	if(n >= 0 || n <= 3)
		return n;
	else return 0;
}


