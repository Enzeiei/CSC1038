/*
  findMax.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

int GetMaxxer(int numb[], int nums)
{
  int maxxed = numb[0];
  // printf("%d\n", maxxed); old verification
  for (int i = 1; i < nums; i++)
  {
    if (numb[i] > maxxed)
    {
      // printf("%d yurr ?\n", numb[i]); old tests
      maxxed = numb[i];
    };
  };
  return maxxed;
};

int main(int argc, char * argv[])
{
  int many = argc - 1; // how many args
  int numbys[many]; // number array

  // iterate through argvs and add to number array
  for (int it = 0; it < argc - 1; it++)
  {
    numbys[it] = atoi(argv[it + 1]);
  };

  printf("%d\n", GetMaxxer(numbys, many));

  return 0;
}
