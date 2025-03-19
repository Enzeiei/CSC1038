/*
 circle-area.c
 author: Rafael Lance Catalan
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

int main(int argc, char *argv[])
{
  int radius = 3;
  float area = 0.0;
  /*var initialisation*/
  // radius = atoi(argv[1]); overwritten and assigned to 3 during init.
  if (radius < 0)
    { //happens if radius is negative or zero
    printf("Given input for radius is below zero. It will be corrected to positive.\n");
    radius = radius * (-1);
    };

  radius = radius * radius; //rad ** 2

  area = radius * PI; // circle area
  /*when pi is only 3.14, the answer is less than if it is defined as
  3.1415, as less digits reduces the accuracy.*/

  printf("%.2f\n",area); // two values right of the decimal point
  // printf("%9.2f\n",area); // width of shown number

  return (0);
}
