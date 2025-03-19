/*
  calculator.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function base up
float multi(float n1, float n2);
float divi(float n1, float n2);


int main(int argc, char * argv[])
{
char* enter = argv[1];
float v1 = atof(argv[2]);
float v2 = atof(argv[3]);
// printf("%s %f %f\n", enter, v1, v2);

if (!strcmp("multiply", enter))
{
  printf("%.6f\n", multi(v1, v2));
  // printf("in multiply\n");
}
else if (!(strcmp("divide", enter)))
{
  if (v2 == 0)
  {
    printf("invalid\n");
  }
  else
  {
    printf("%.6f\n", divi(v1, v2));
  };
 // printf("in divide\n");
}

return 0;
};


float multi(float n1, float n2)
{
	return ("%f\n", n1 * n2);
};

float divi(float n1, float n2)
{
  return ("%f\n", n1 / n2);
};
