// Includes
#include <stdio.h>
#include <stdlib.h> // Required for atoi()

// Function prototypes
void populateArray(int* array, int length, char **argv);
void selectionSort(int* array, int length);
void returnMedians(int* array, int length, int* dest);

int main(int argc, char**argv) {
	// Initialize variables
	int len;

	// Get length and initialize arrays;
	len = (argc - 1); // -1 to not include program invocation
	int numArray[len];
	int medians[2]; // To store 2 numbers;

	// Populate the array with input numbers using populateArray
	populateArray(numArray, len, argv);

	// Sort the array from smallest to largest using selectionSort()
	selectionSort(numArray, len);

	// Get the 2 medians of a sorted array using returnMedians()
	returnMedians(numArray, len, medians);

	// Print mediands to stdout
	printf("%d\n%d\n", *(medians), *(medians + 1));

	return 0; // End Program
}

// Takes the command line args from argv, uses atoi() to convert into integers, then stores into the array provided
void populateArray(int* array, int length, char **argv) {
	for (int i = 0; i < length; i++) {
		array[i] = atoi(*(argv + i + 1)); // +1 to avoid program invocation
	}

}

// Sort each number in the array based on size using selection sort algorithm
void selectionSort(int* array, int length) {
    for (int i = 0; i < length; i++) { // Lower bound is increased each iteration
        int p = i;
        int q = i + 1;

        for (;q < length; q++) {
            if(*(array + q) < *(array + p)) {
                p = q;
            }
        }

        int tmp = *(array + i);
        *(array + i) = *(array + p);
        *(array + p) = tmp;
    }
}

// Divide the length by 2 to get the location of the second median, then store medians into given array
void returnMedians(int* array, int length, int* dest) {
	int median = length / 2;
	*(dest) = *(array + median - 1); // -1 as indexes start from 0 and to get the first median
	*(dest + 1) = *(array + median);
}
