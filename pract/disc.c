#include <stdio.h>
#include <stdlib.h> // Required for atoi(), atof()

// Structure Definition
typedef struct {
	char* name;
	int amount;
	float price;
	int promotion;
} item;

// Function Prototypes
int determinePromotion(item* pItem);
void populateArray(item* array, int length, char** argv);
float findTotal(item* array, int length);

int main(int argc, char** argv) {
	// Initialize Variables
	int len;
	float total;

	// Get length and initialize array
	len = (argc - 1) / 4; // -1 to avoid program invocation and /4 as there are 4 parameters per item
	item cart[len];

	// Populate our cart with the details provided using populateArray()
	populateArray(cart, len, argv);

	// Output the total price of the entire cart using findTotal()
	total = findTotal(cart, len);
	printf("%.2f\n", total);

	return 0; // End program
}

// If there is a promotion we return the number of items to discount by, else return 0
int determinePromotion(item* pItem) {
	if (pItem->promotion) {
		return ((pItem->amount) / 3);
	}
	
	return 0;
}

// Store command lines args from argv into a each array index, where each index is it's own item struct
void populateArray(item* array, int length, char** argv) {
	// We are using (4 * i) as each parameter contains 4 items, so this keeps the indexs correct for each iteration
	for (int i = 0; i < length; i++) {
		item tmp;
		item* pTmp = &tmp;
		
		pTmp->name = *(argv + 1 + (4 * i));
		pTmp->amount = atoi(*(argv + 2 + (4 * i)));
		pTmp->price = atof(*(argv + 3 + (4 * i)));
		pTmp->promotion = atoi(*(argv + 4 + (4 * i)));

		*(array + i) = tmp;
	}

}

// A total variable is added to by going through the struct array and adding amount * price - discount, Once total is found, output
float findTotal(item* array, int length) {
	int itemCount;
	float total = 0; // Value we want to output at the end

	for (int i = 0; i < length; i++) {
		itemCount = ((array + i)->amount) - determinePromotion(array + i);
		total += itemCount * ((array + i)->price);
	}

	return total;
}1~#include <stdio.h>
#include <stdlib.h> // Required for atoi(), atof()

// Structure Definition
typedef struct {
	char* name;
	int amount;
	float price;
	int promotion;
} item;

// Function Prototypes
int determinePromotion(item* pItem);
void populateArray(item* array, int length, char** argv);
float findTotal(item* array, int length);

int main(int argc, char** argv) {
	// Initialize Variables
	int len;
	float total;

	// Get length and initialize array
	len = (argc - 1) / 4; // -1 to avoid program invocation and /4 as there are 4 parameters per item
	item cart[len];

	// Populate our cart with the details provided using populateArray()
	populateArray(cart, len, argv);

	// Output the total price of the entire cart using findTotal()
	total = findTotal(cart, len);
	printf("%.2f\n", total);

	return 0; // End program
}

// If there is a promotion we return the number of items to discount by, else return 0
int determinePromotion(item* pItem) {
	if (pItem->promotion) {
		return ((pItem->amount) / 3);
	}
	
	return 0;
}

// Store command lines args from argv into a each array index, where each index is it's own item struct
void populateArray(item* array, int length, char** argv) {
	// We are using (4 * i) as each parameter contains 4 items, so this keeps the indexs correct for each iteration
	for (int i = 0; i < length; i++) {
		item tmp;
		item* pTmp = &tmp;
		
		pTmp->name = *(argv + 1 + (4 * i));
		pTmp->amount = atoi(*(argv + 2 + (4 * i)));
		pTmp->price = atof(*(argv + 3 + (4 * i)));
		pTmp->promotion = atoi(*(argv + 4 + (4 * i)));

		*(array + i) = tmp;
	}

}

// A total variable is added to by going through the struct array and adding amount * price - discount, Once total is found, output
float findTotal(item* array, int length) {
	int itemCount;
	float total = 0; // Value we want to output at the end

	for (int i = 0; i < length; i++) {
		itemCount = ((array + i)->amount) - determinePromotion(array + i);
		total += itemCount * ((array + i)->price);
	}

	return total;
}1~#include <stdio.h>
#include <stdlib.h> // Required for atoi(), atof()

// Structure Definition
typedef struct {
	char* name;
	int amount;
	float price;
	int promotion;
} item;

// Function Prototypes
int determinePromotion(item* pItem);
void populateArray(item* array, int length, char** argv);
float findTotal(item* array, int length);

int main(int argc, char** argv) {
	// Initialize Variables
	int len;
	float total;

	// Get length and initialize array
	len = (argc - 1) / 4; // -1 to avoid program invocation and /4 as there are 4 parameters per item
	item cart[len];

	// Populate our cart with the details provided using populateArray()
	populateArray(cart, len, argv);

	// Output the total price of the entire cart using findTotal()
	total = findTotal(cart, len);
	printf("%.2f\n", total);

	return 0; // End program
}

// If there is a promotion we return the number of items to discount by, else return 0
int determinePromotion(item* pItem) {
	if (pItem->promotion) {
		return ((pItem->amount) / 3);
	}
	
	return 0;
}

// Store command lines args from argv into a each array index, where each index is it's own item struct
void populateArray(item* array, int length, char** argv) {
	// We are using (4 * i) as each parameter contains 4 items, so this keeps the indexs correct for each iteration
	for (int i = 0; i < length; i++) {
		item tmp;
		item* pTmp = &tmp;
		
		pTmp->name = *(argv + 1 + (4 * i));
		pTmp->amount = atoi(*(argv + 2 + (4 * i)));
		pTmp->price = atof(*(argv + 3 + (4 * i)));
		pTmp->promotion = atoi(*(argv + 4 + (4 * i)));

		*(array + i) = tmp;
	}

}

// A total variable is added to by going through the struct array and adding amount * price - discount, Once total is found, output
float findTotal(item* array, int length) {
	int itemCount;
	float total = 0; // Value we want to output at the end

	for (int i = 0; i < length; i++) {
		itemCount = ((array + i)->amount) - determinePromotion(array + i);
		total += itemCount * ((array + i)->price);
	}

	return total;
}
