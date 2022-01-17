#ifndef __ARRAY_UTILS__
#define __ARRAY_UTILS__

#include <stdio.h>

/**
 * Generates a random integer whose value is from lowest (inclusive) to highest (exclusive).
 */
int randomIntegerInRange(int lowest, int highest);

int* randomIntArray(size_t length);

void printArray(int *arr, size_t length);

template <typename T>
void destroyArray(T* arr) {
	printf("Destroying array...");
	delete[] arr;
}

template <typename T>
short compare(T a, T b) {
//	if (a > b) return 1;
//	else if (a == b) return 0;
//	else return -1;
	return a > b ? 1 : (a == b ? 0 : -1);
}

#endif
