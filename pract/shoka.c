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
void printCart(item* array, int length);

int main(int argc, char** argv) {
	// Initialize Variables
	int len;

	// Get length and initialize array
	len = (argc - 1) / 4; // -1 to avoid program invocation and /4 as there are 4 parameters per item
	item cart[len];

	// Populate our cart with the details provided using populateArray()
	populateArray(cart, len, argv);

	// Output each item contained within the array, in a formatted manner using printCart()
	printCart(cart, len);

	return 0; // End program
}

// We print what type of promotion an item has, with 1 being its "On Sale" and 0 being "No SAle"
int determinePromotion(item* pItem) {
	if (pItem->promotion) {
		printf("On Sale\n");
	}
	else {
		printf("No Sale\n");
	}
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

// Print out each item struct in the format name,amount,price,promotion with promotion being either "On Sale" or "No Sale"
void printCart(item* array, int length) {
	for (int i = 0; i < length; i++) {
		printf("%s,%d,%.2f,", (array + i)->name, (array + i)->amount, (array + i)->price);

		// We find out which string we need to print using determinePromotion()
		determinePromotion(array + i);
	}

}
