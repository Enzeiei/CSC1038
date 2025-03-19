/*
  a program to both process inventory and print the total value.
  author: Rafael Lance Catalan
  date: 31/10/2024
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// to make Product init easier.
typedef struct Product Product;

struct Product
{
  char name[20]; // item named
  unsigned int stock; // stock of item
  float price; // item price
  int discount; //0 if no discount, 1 if discounted
};

//prototyping
void inventory_pop(Product p[], int numtime, char * argv[]); // adding to our inventory.
void print_inventory(Product p[], int numtime); // printing inv value.

//mainer
int main(int argc, char * argv[])
{
  Product inventory[100]; // inventory initialize
  int runtime = (argc - 1) / 4; // 4 aspects per entry of product, hence divide 4 (-1 for arg0).

  inventory_pop(inventory, runtime, argv);
  print_inventory(inventory, runtime);

  return 0;
}

void inventory_pop(Product p[], int numtime, char * argv[])
{
  for (int i = 0; i < numtime; i++)
  {
    Product *Good = &p[i];
    strcpy(Good->name, argv[(i * 4) + 1]);
    Good->stock = atoi(argv[(i * 4) + 2]);
    Good->price = atof(argv[(i * 4) + 3]);
    Good->discount = atoi(argv[(i * 4) + 4]);
  }
  return;
}

void print_inventory(Product p[], int numtime)
{
  float total = 0;
  float *pTot = &total; //total pointer
  float di = 1;
  float nd = 0.9; //defined discount values
  float *disc = 0; //float pointer for discount
  for (int i = 0; i < numtime; i++) // goes through each item.
  {
    Product *Inv = &p[i]; //inventory pointer on given iteration
    if (Inv->discount) //whether discount is applied or not...
    {
      disc = &nd;
    }
    else
    {
      disc = &di;
    }
    // the disc pointer will be assigned the relevant price discount.
    *pTot += Inv->stock * Inv->price * (*disc); // add item values together
  }
  printf("%.2f\n", *pTot);
  return;
}
