#include <iostream>
#include <iomanip>
#include <windows.h>

#include "console.h"
#include "utils.h"
#include "ArrayRenderer.h"

using namespace std;

const char DOT = 254;

template <class T>
ArrayRenderer<T>::ArrayRenderer(T* targetArr, size_t length) {
	this->_arr = targetArr;
	this->_length = length;
}

template <class T>
ArrayRenderer<T>::render(COORD fromTopLeft, size_t highlightIndex) {
	clearScreen();
	gotoxy(fromTopLeft.X, fromTopLeft.Y);

	for (int i = 0; i < this->_length; ++i) {
		setYellowText();
		cout << setw(3) << this->_arr[i];
	}

	short offsetTop = fromTopLeft.Y + 1;

	T maxVal = this->_maxValue();
	setLightGreenText();
	for (int j = 0; j < maxVal; ++j) {
		gotoxy(fromTopLeft.X, offsetTop++);
		for (int i = 0; i < this->_length; ++i) {
			if( i == highlightIndex) setYellowText();
			else setLightGreenText();
			cout << setw(3) << (j < this->_arr[i] ? DOT : ' ');
		}
	}
}

template <class T>
T ArrayRenderer<T>::_maxValue() {
	T max = this->_arr[0];
	for (int i = 1; i < this->_length; ++i) {
		if (max < this->_arr[i]) {
			max = this->_arr[i];
		}
	}
	return max;
}

template class ArrayRenderer<int>;


