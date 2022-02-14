#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <windows.h>

#include "utils.h"

#define MAX_VAL 30
const int MIN_VAL = 1;


int* randomIntArray(size_t length) {
	int* arr = new int[length];
	for (int i = 0; i < length; i++) {
		arr[i] = randomIntegerInRange(MIN_VAL, MAX_VAL);
	}
	return arr;
}

void printArray(int *arr, size_t length) {
	printf("Array[%d]={\n", length);
	for (int i = 0; i < length; i++) {
		printf("%5d", arr[i]);
		printf(i < length-1 ? "," : "");
	}
	printf("\n}\n");
}

