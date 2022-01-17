#include <stdexcept>
#include <iostream>

#include "arrayUtils.h"
#include "ISortingStrategy.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"


using namespace std;

typedef int data_t;
const size_t ARR_LEN = 30;

data_t* generateArray();

void BubbleSortEx();
void SelectionSortEx();
void InsertionSortEx();

int main(int argc, char** argv) {
	//BubbleSortEx();
	//SelectionSortEx();
	InsertionSortEx();
}


void InsertionSortEx(){
	ISortingStrategy<data_t>* sorter = new InsertionSort<data_t>();
	cout << "Generating array..." << endl;
	data_t* arr = generateArray();
	printArray(arr, ARR_LEN);
	
	cout << endl << "After sort:" << endl;
	data_t* sortedArr = sorter->sort(arr, ARR_LEN, SORT_DESC);
	printArray(sortedArr, ARR_LEN);

	destroyArray(arr);
}

void SelectionSortEx(){
	ISortingStrategy<data_t>* sorter = new SelectionSort<data_t>();
	cout << "Generating array..." << endl;
	data_t* arr = generateArray();
	printArray(arr, ARR_LEN);
	
	cout << endl << "After sort:" << endl;
	data_t* sortedArr = sorter->sort(arr, ARR_LEN, SORT_DESC);
	printArray(sortedArr, ARR_LEN);

	destroyArray(arr);
}

void BubbleSortEx(){
	ISortingStrategy<data_t>* sorter = new BubbleSort<data_t>();
	cout << "Generating array..." << endl;
	data_t* arr = generateArray();
	printArray(arr, ARR_LEN);
	
	cout << endl << "After sort:" << endl;
	data_t* sortedArr = sorter->sort(arr, ARR_LEN, SORT_DESC);
	printArray(sortedArr, ARR_LEN);

	destroyArray(arr);
}

data_t* generateArray() {
	data_t* arr = randomIntArray(ARR_LEN);
	return arr;
}
