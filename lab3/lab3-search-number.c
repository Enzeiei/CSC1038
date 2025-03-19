/*
  search-number.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

int GetSearch(int numb[], int targ, int nums)
{
  // printf("%d\n", maxxed); old verification
  int founder = -1;
  for (int i = 1; i < nums; i++)
  {
    // printf("%d\n", numb[i]); // test numbers
    if (numb[i] == targ)
    {
      // printf("%d yurr ?\n", numb[i]); old tests
      founder = i;
    };
  };
  return founder;
};

int main(int argc, char * argv[])
{
  int app_args = argc - 1; // applicable args
  int target = atoi(argv[1]); // search arg
  int numbys[argc - 1]; // number array

  // iterate through argvs and add to number array
  for (int it = 1; it < argc - 1; it++)
  {
    numbys[it] = atoi(argv[it + 1]);
  };

  int resolute = GetSearch(numbys, target, app_args); // search the array for target number

  if (resolute != -1)
  {
    printf("Found %d at %d\n", target, resolute - 1);
  }
  else {
    printf("%d not found.\n", target);
  }

  return 0;
}
