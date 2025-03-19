/*
  dot product !
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

// prototyping ?
void popul(int *pv1, int *pv2, int size, char * argv[]); // populating
int dproduct(int *pv1, int *pv2, int size); // dot product !

// mainer
int main(int argc, char * argv[])
{
  int sizer = atoi(argv[1]);

  // memory assignage per our two vectors.
  int *pVector1 = (int*)malloc(sizer * sizeof(int));
  int *pVector2 = (int*)malloc(sizer * sizeof(int));

  // failure check
  if ((pVector1 == NULL) || (pVector2 == NULL))
  {
    printf("Failed to allocate memory.\n");
    return 0;
  }

  // function callup
  popul(pVector1, pVector2, sizer, argv);
  int reso = dproduct(pVector1, pVector2, sizer);

  // free the llocated memory now that the result has been found.
  free(pVector1);
  free(pVector2);

  printf("%d\n", reso);

  return 0;
}

void popul(int *pv1, int *pv2, int size,char * argv[])
{
  for (int i = 0; i < size; i++)
  {
    pv1[i] = atoi(argv[i + 2]); // populates v1

    pv2[i] = atoi(argv[i + 2 + size]); // populates v2
  }

  return;
}

int dproduct(int *pv1, int *pv2, int size)
{
  int total;

  for (int i = 0; i < size; i++)
  {
    total += (pv1[i] * pv2[i]); // each element of each array corrosponds to the other of the same index
  }

  return total;
}
