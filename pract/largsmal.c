// Includes
#include <stdio.h>
#include <stdlib.h> // Required for atof()
#include <string.h> // Required for strcmp()

// Function Prototypes
int findOperation(char* operation);
float findSmallest(float* array, int length);
float findLargest(float* array, int length);

int main(int argc, char*argv[]) {
	// Initialize Variables
	int len;
	int operationCode;
	float output;

	// Get array length and initialize array
	len = argc - 2; // -2 as we need to ignore program call and argv[1]
	float arr[len];

	// Store numbers from argv into array
	for (int i = 0; i < len; ++i)
	{
		arr[i] = atof(argv[i + 2]);
	}

	// Check what operation is being used then execute function, or print invalid
	operationCode = findOperation(argv[1]);
	if (operationCode == 1) {
		output = findSmallest(arr, len);
	}
	else if (operationCode == 2) {
		output = findLargest(arr, len);
	}
	else {
		printf("Invalid operation given\n");
	}
	
	// Output value to 2 digits
	printf("%.2f\n", output);

	return 0; // End program
}

// Using strcmp() we can find what operation is used, then return a value depending on what operation is found
int findOperation(char* operation) {
	if (! (strcmp(operation, "smallest"))) {
		return 1;
	}
	else if (! (strcmp(operation, "largest"))) {
		return 2;
	}

	return -1; // If -1 return then invalid operation given
}

// Have a variable store the current smallesthen search through array and compare each element to smallest then return after done
float findSmallest(float* array, int length) {
	float smallest = array[0];

	for (int i = 0; i < length; i++) {
		if (array[i] < smallest) {
			smallest = array[i];
		}
	}

	return smallest;
}

// Store current largest as variable, then search through loop and compare each element to largest. Return value after done
float findLargest(float* array, int length) {
	float largest = array[0];

	for (int i = 0; i < length; i++) {
		if (array[i] > largest) {
			largest = array[i];
		}
	}

	return largest;
}
