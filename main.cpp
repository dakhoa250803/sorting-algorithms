#include <stdexcept>
#include <iostream>
#include <windows.h>

#include "arrayUtils.h"
#include "keyboard.h"
#include "ISortingStrategy.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "Menu.h"
#include "ArrayRenderer.h"

using namespace std;

typedef int data_t;
const size_t ARR_LEN = 30;
const size_t SORTER_NUM = 3;

struct Sorter {
	Sorter(string name, ISortingStrategy<data_t> *strategy) {
		this->name = name;
		this->strategy = strategy;
	}

	string name;
	ISortingStrategy<data_t> *strategy;
};



Sorter* selectSorter();
SORT_TYPE selectSortType();
data_t* generateArray();
void sortArray(data_t* arr, Sorter *sorter, SORT_TYPE sortType);
void updateArrayRenderer(size_t changedIndex);

Sorter *supportedSorters[] = {
	new Sorter("Bubble Sort", new BubbleSort<data_t>()),
	new Sorter("Insertion Sort", new InsertionSort<data_t>()),
	new Sorter("Selection Sort", new SelectionSort<data_t>()),
};

ArrayRenderer<data_t>* arrRenderer;

int main(int argc, char** argv) {
	
	do {
		Sorter *sorter = selectSorter();
		if (!sorter) break;
		
		SORT_TYPE sortType = selectSortType();
		if (sortType == SORT_INVALID) break;

		data_t* arr = generateArray();
		arrRenderer = new ArrayRenderer<data_t>(arr, ARR_LEN);
		
		COORD fromCoord;
		fromCoord.X = 1;
		fromCoord.Y = 1;
		size_t changedIndex;
		arrRenderer->render(fromCoord, changedIndex);

		sortArray(arr, sorter, sortType);
		cout << endl << endl;
		destroyArray(arr);

		cout << endl << "Press any key to continue" << endl;
		getKeyPressed();
	}
	while(true);

	cout << "Good bye! We will miss you!";
	return 0;
}

Sorter* selectSorter() {
	Menu *menu = new Menu("SORTING ALGORITHMS", "What is your favorite?");
	for (int i = 0; i < SORTER_NUM; ++i) {
		menu->addItem(supportedSorters[i]->name);
	}
	menu->addItem("Exit");
	size_t selectedIdx = menu->renderAndWait();
	
	if (selectedIdx >= SORTER_NUM) return NULL;
	Sorter *sorter = supportedSorters[selectedIdx];
	return sorter;
}

SORT_TYPE selectSortType() {
	Menu *menu = new Menu("Sort direction?");
	menu->addItem("Ascending");
	menu->addItem("Descending");
	menu->addItem("Exit");
	size_t selectedIdx = menu->renderAndWait();
	
	switch(selectedIdx) {
		case 0: return SORT_ASC;
		case 1: return SORT_DESC;
		default: return SORT_INVALID;
	}
}

data_t* generateArray() {
	cout << "Generating array..." << endl;
	data_t* arr = randomIntArray(ARR_LEN);
	return arr;
}

void sortArray(data_t* arr, Sorter *sorter, SORT_TYPE sortType) {
	ISortingStrategy<data_t>* strategy = sorter->strategy;
	cout << endl << "After sort with: " << sorter->name << endl;
	
	strategy->subscribe("sortItem", updateArrayRenderer);
	data_t* sortedArr = strategy->sort(arr, ARR_LEN, sortType);
}

void updateArrayRenderer(size_t changedIndex){
	COORD fromCoord;
	fromCoord.X = 1;
	fromCoord.Y = 1;
	arrRenderer->render(fromCoord, changedIndex);
	Sleep(100);
}	
