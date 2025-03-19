/*
  draw-empty-square.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

//top line function thing declare
void linerman(int x, int st, char c[2]);


int main(int argc, char * argv[])
{
  int stars = atoi(argv[1]);
  int o;
  linerman(o, stars, "*");

  int i; //downwards int
  int j; //sidewards int
  for (i = 0; i < (stars - 2); i++) {
    printf("*");
    for (j = 0; j < (stars - 2); j++) {
      printf(" ");
    }
    printf("*\n");
  };
  o = 0;
  linerman(o, stars, "*");

  return (0);
};

//top/bottom line function thing definition
void linerman(int x, int st, char c[2]) {
  for (x = 0; x < st; x++) {
  printf("%s", c);
  };
  printf("\n");
};
