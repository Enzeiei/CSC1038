/*
 circle-area.c
 author: Rafael Lance Catalan
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

int main(int argc, char * argv[])
{
  int radius = 0;
  float area = 0.0;
  /*var initialisation*/
  radius = atoi(argv[1]);

  radius = radius * radius; //rad ** 2

  area = radius * PI; // circle area

  printf("%.2f\n",area); // two values right of the decimal point
  // printf("%9.2f\n",area); // width of shown number

  return (0);
}
