#include <stdexcept>
#include <iostream>

#include "arrayUtils.h"
#include "ISortingStrategy.h"
#include "BubbleSort.h"
using namespace std;

typedef int data_t;
const size_t ARR_LEN = 10;

data_t* generateArray();

int main(int argc, char** argv) {
	ISortingStrategy<data_t>* sorter = new BubbleSort<data_t>();
	cout << "Generating array..." << endl;
	data_t* arr = generateArray();
	printArray(arr, ARR_LEN);

	destroyArray(arr);
	return 0;
}

data_t* generateArray() {
	data_t* arr = randomIntArray(ARR_LEN);
	return arr;
}

