/*
 convert-units.c
 author Rafael Lance Catalan
 */


#include <stdio.h>
#include <stdlib.h>
#define CONV 2.54

int main(int argc, char*argv[])
{
  //var init
  float centi = 0.0;
  float inches = 0.0;

  centi = atoi(argv[1]);
  inches = centi / CONV;

  printf("%.2f\n", inches);

  return (0);
}
