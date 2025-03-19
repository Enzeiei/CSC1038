/*
  matrix-diagonal-sum.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
  int arraysize = atoi(argv[1]);
  // printf("%d\n", arraysize);
  int count = 0;
  int numbys[arraysize][arraysize]; // number array

  // iterate through argvs and add to number array
  for (int it = 0; it < arraysize; it++)
  {
    // printf("%d\n", it);
    for (int zz = 0; zz < arraysize; zz++)
      {
        numbys[it][zz] = atoi(argv[(it * arraysize) + zz + 2]);
        // printf("%d %d | %d\n", it, zz, numbys[it][zz]);
        if (it == zz)
        {
          count = count + (atoi(argv[(it * arraysize) + zz + 2]));
        };
      }
  };

  //printf("%d\n", numbys[1][1]); //verification it works at all
  printf("%d\n", count);

  return 0;
}
