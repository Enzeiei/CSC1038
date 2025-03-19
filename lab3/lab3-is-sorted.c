/*
  is-sorted.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int l)
{
  int i, j, tmp;
  for (i = 0; i < l -1; i++)
  {
    for (j = 0; j < l - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        //swapmoder array j and j + 1
        tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}


int main(int argc, char * argv[])
{
  int apply = argc - 1;
  int razer[apply];

  // input string to int in array

  for (int i = 0; i < apply; i++)
  {
    razer[i] = atoi(argv[i+1]);
  };

  // array sort mode
  bubbleSort(razer, apply);

  //array now sorted. print one line per

  for (int i = 0; i < apply; i++)
  {
    printf("%d\n", razer[i]);
  }

  return 0;
}
