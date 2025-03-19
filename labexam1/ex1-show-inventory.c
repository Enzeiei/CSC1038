/*
  a program to both process inventory and print it into an organised manner.
  author: Rafael Lance Catalan
  date: 31/10/2024
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// to make Product init easier.
typedef struct Product Product;

// Product structure
struct Product
{
  char name[20]; // item named
  unsigned int stock; // stock of item
  float price; // item price
  int discount; //0 if no discount, 1 if discounted
};

//prototyping
void inventory_pop(Product p[], int numtime, char * argv[]); // adding to our inventory.
void print_inventory(Product p[], int numtime); // printing our inventory.
void dnd(int n); //discounted or not

//mainer
int main(int argc, char * argv[])
{
  Product inventory[100]; //initialise Product array, "inventory" max 100
  int runtime = (argc - 1) / 4; // 4 aspects per entry of product, hence divide 4 (-1 for arg0).

  inventory_pop(inventory, runtime, argv); //populate inventory
  print_inventory(inventory, runtime);

  return 0; //exit
}

// actual function definition
void inventory_pop(Product p[], int numtime, char * argv[])
{
  for (int i = 0; i < numtime; i++) //processes all items from argv
  {
    Product *pGo = &p[i]; //startup pointer for the index
    strcpy(pGo->name, argv[(i * 4) + 1]);
    pGo->stock = atoi(argv[(i * 4) + 2]);
    pGo->price = atof(argv[(i * 4) + 3]);
    pGo->discount = atoi(argv[(i * 4) + 4]);
  }
  return;
}

void print_inventory(Product p[], int numtime)
{
  for (int i = 0; i < numtime; i++)
  {
    Product *pInv = &p[i]; //making pointer for inventory item
    printf("%s,%d,%.2f,", pInv->name, pInv->stock, pInv->price);
    dnd(pInv->discount); //function for getting discount information
  }
  return;
}

void dnd(int n)
{
  if (n) // where the discount element of the Product struct is 1 = disc!!
  {
    printf("Discounted\n");
  }
  else
  {
    printf("No Discount\n");
  }
  return;
}
