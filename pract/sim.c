#include <stdio.h>
#include <string.h> // Needed for strcmp(), and strlen()

// Function prototypes
void reverseString(char* str, char* destStr, int length);
int symmetric(char* str, char* reversedStr);

int main(int argc, char*argv[]) {
	// Initialize Variables
	int len;
	int output;

	// Get length and initialize reversed string array
	len = strlen(argv[1]);
	char reversed[len + 1]; // +1 to account for null terminator

	// Call reverseString() to get reversed version of argv[1]
	reverseString(argv[1], reversed, len);

	// Check if string is symmetric then print yes or no
	output = symmetric(argv[1], reversed);
	if (output) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}

	return 0; // End program
}

// Reverse string by starting from the end of the input then add characters to our destination array 1 by 1
void reverseString(char* str, char* destStr, int length) {
	for (int i = 0; i < length; i++) {
		destStr[i] = str[length - i - 1]; // -1 to make sure index is not out of bounds
	}

	destStr[length] = '\0'; // add null terminator to new string
}

// Use strcmp() to check if the original and reversed are the same, if they are then string is symmetric
int symmetric(char* str, char* reversedStr) {
	if (! (strcmp(str, reversedStr))) {
		return 1;
	}
	else {
		return 0;
	}
}
