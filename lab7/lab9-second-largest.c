/*
  second largest ; takes a list of floats, finds 2nd largest num and prints as such
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

//prototyping
void floatpop(float *pnums, int size, char * argv[]);
float find2nd(float *pnums, int size);

// mainer

int main(int argc, char * argv[])
{
  int size = argc - 1; // using argc to find how many nums there are

  float *pNums = (float*)malloc(size * sizeof(float));

  // allocation failsafe
  if (pNums == NULL)
  {
    printf("Failed to allocate memory.\n");
    return 0;
  }

  // function callup
  floatpop(pNums, size, argv);
  float resolution = find2nd(pNums, size);

  free(pNums); // release memory held by the pNums

  printf("%.1f\n", resolution);

  return 0;
}

void floatpop(float *pnums, int size, char * argv[])
{
  for (int i = 0; i < size; i++)
  {
    pnums[i] = atof(argv[i + 1]);
  }

  return;
}

float find2nd(float *pnums, int size)
{
  // need to track largest as well as 2nd.
  float larg;
  float larg2;

  for (int i = 0; i < size; i++)
  {
    // if we encounter a number large, trace larg to larg2, replace larg with newest largest.

    if (larg < pnums[i])
    {
      larg2 = larg;
      larg = pnums[i];
    }
    // for the case where num is smaller than largest,but bigger than 2nd largest.
    else if (larg2 < pnums[i] && larg > pnums[i])
    {
      larg2 = pnums[i];
    }
  }

  return larg2;
}
