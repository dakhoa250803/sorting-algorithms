#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <windows.h>

#include "arrayUtils.h"

#define MAX_VAL 100
const int MIN_VAL = 10;


int* randomIntArray(size_t length) {
	int* arr = new int[length];
	for (int i = 0; i < length; i++) {
		arr[i] = randomIntegerInRange(MIN_VAL, MAX_VAL);
	}
	return arr;
}

void destroyArray(void* arr) {
	printf("Destroying array...");
	delete[] arr;
}

void printArray(int *arr, size_t length) {
	printf("Array[%d]={\n", length);
	for (int i = 0; i < length; i++) {
		printf("%4d", arr[i]);
		printf(i < length-1 ? "," : "");
	}
	printf("\n}");
}


/**
 * Generates a random integer whose value is from lowest (inclusive) to highest (exclusive).
 */
int randomIntegerInRange(int lowest, int highest) { 
	static bool first = true;
	if (first) 
	{  
	  srand((unsigned)time(0)); //seeding for the first time only!
	  first = false;
	}
    int range=(highest-lowest)+1; 
    int random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0)); 
    return random_integer;
}
