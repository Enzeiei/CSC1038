/*
  turn the argv into an array - get largest, then smallest, then operate.
  author: Rafael Lance Catalan
*/

//includes
#include <stdio.h>
#include <stdlib.h>


// prototyping
int MaxMinDiff(int arr[], int runner);
// ^ will use a list of ints and its length to operate; find the max/min diff.

// mainer
int main(int argc, char * argv[])
  {
  int faiz[100]; //our list of integers
  int argon = argc - 1; //how many args for following for loop.

  for(int i = 1; i < argon; i++)
  {
    faiz[i] = atoi(argv[i]);
  } //add up integers from argv to our int list to operate better later.

  printf("%d\n", MaxMinDiff(faiz, argon)); // function call
  // printf(":3\n"); <<- old test code
  return 0;
}

int MaxMinDiff(int arr[], int runner)
{
  int max = 0;
  int min = 0;
  int *pMax = &max;
  int *pMin = &min; //max/min initialize, along with pointers for each.
  int maxxer = 0;
  int minner = 0; //Boolean-type variables to ensure max/min are assigned at least once from the given int list.
  for(int i = 0; i < runner; i++)
  {
    if ((arr[i] > max) || (maxxer == 0))
    {
      *pMax = arr[i];
      maxxer = 1; // max assigned.
    }
    else if ((arr[i] < min) || (minner == 0))
    {
      *pMin = arr[i];
      minner = 1; // min assigned.
    }
  }
  // printf("Final vent %d - %d\n", max, min); <- old test code
  return (*pMax - *pMin);
}
