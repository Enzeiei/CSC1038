/*
  keep it freaky !!
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  int* pnumber = NULL; //type int*, can store the address of a given int

  int number = 15;

  int *pointer = &number; //check the invocation below!

  printf("%d, %d, address of number is %d through pointer, through number itself is %d\n", number, *pointer, pointer, &number);
  printf("adding 35 through *pointer\n");
  *pointer = 50;

  printf("%d on number, %d on pointer, shit is %d!!\n", number, *pointer, (number == *pointer));
}
