/*
  count-odd-number.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
int numhold[10]; //number array
int oddc = 0; //oddcounter
int i; //iterate item
for (i = 1; i < argc; i++) {
  numhold[i] = atoi(argv[i]);
  if (numhold[i] != 0 && numhold[i] % 2 == 1) {
    oddc++;
  };

};

printf("%d\n", oddc);

return 0;
}
