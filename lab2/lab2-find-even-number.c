/*
  find-even-number.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
int numhold[10]; //number array
int finder = 0; // if even number present
int i; //iterate item
for (i = 1; i < argc; i++) {
  numhold[i] = atoi(argv[i]);
  if (numhold[i] != 0 && numhold[i] % 2 == 0) {
    printf("%d - %d\n", i - 1, numhold[i]);
    finder++;
  };

};

if (finder == 0) {
  printf("Not found!\n");
};

return 0;
}
