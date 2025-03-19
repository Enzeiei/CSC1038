/*
  find the largest number within an array that is double the size of another within the same array.
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

//prototyping
void floatpop(int *pnums, int size, char * argv[]);
int findlarg(int *pnums, int size);

// mainer

int main(int argc, char * argv[])
{
  int size = argc - 1; // using argc to find how many nums there are

  int *pNums = (int*)malloc(size * sizeof(int));

  // allocation failsafe
  if (pNums == NULL)
  {
    printf("Failed to allocate memory.\n");
    return 0;
  }

  // function callup
  floatpop(pNums, size, argv);
  int resolution = findlarg(pNums, size);

  free(pNums); // release memory held by the pNums

  printf("%d\n", resolution);

  return 0;
}

void floatpop(int *pnums, int size, char * argv[])
{
  for (int i = 0; i < size; i++)
  {
    pnums[i] = atoi(argv[i + 1]);
  }

  return;
}

int findlarg(int *pnums, int size)
{
  // need to track largest; initialize.
  int larg;

  for (int i = 0; i < size; i++)
  {
    // if we encounter a number large, trace larg to larg2, replace larg with newest largest.

    if (larg < pnums[i])
    {
      larg = pnums[i];
    }
  }
  // 2nd loop to verify there is a halfsize num.
  for (int i = 0; i < size; i++)
  {
    if (larg >= (2 * pnums[i]))
    {
      return larg; //largest is returned where a number at half its size is present
    }
  }

  return 0; // if the largest number does not have a number half its size present in the array.
}

