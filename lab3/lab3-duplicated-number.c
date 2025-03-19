/*
  duplicated-number.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

int GetSearch(int numb[], int targ, int nums)
{
  // printf("%d\n", maxxed); old verification
  int founder = -1;
  for (int i = 0; i < nums; i++)
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

int GetDupe(int numli[], int runnum)
{
  int getted = -1;
  int list2_len = 0; //length of dupe list
  //printf("%d\n", runnum);
  int riser[runnum]; // new list
  for (int i = 0; i < runnum; i++)

  {

    int zaurus = GetSearch(riser, numli[i], list2_len); // get value from getsearch
    // int zaurus = 2;
    if (zaurus != -1 && list2_len != 0)
    {
      //printf("%d real %d\n", numli[i], zaurus);
      getted = numli[i];
      return getted;
    }
    else
    {
      riser[list2_len] = numli[i];
      list2_len++;
    };
    //printf("%d %d %d %d\n", getted, numli[i], runnum, i);
  };

  return getted;
}



int main(int argc, char * argv[])
{
  int app_args = argc - 1; // applicable args
  int numbys[argc - 1]; // number array
  // iterate through argvs and add to number array
  for (int it = 1; it < argc - 1; it++)
  {
    numbys[it - 1] = atoi(argv[it]);
  };

  // printf("passable\n");

  int resolute = GetDupe(numbys, app_args);
  //int resolute = 1;
  // printf("%d\n", resolute);
  if (resolute != -1)
  {
    printf("%d\n", resolute);
  }
  else {
    printf("no duplicated number\n");
  }

  return 0;
}

