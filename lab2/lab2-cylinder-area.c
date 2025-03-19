/*
  cylinder-area.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

int main(int argc, char * argv[])
{
if (argc == 1) {
  printf("No input given!\n");
  exit(0);
}
else if (argc == 2) {
  printf("Two arguments needed!\n");
  exit(0);
}
else if (atoi(argv[1]) <= -1 || atoi(argv[2]) <= -1) {
  printf("The radious or height cannot be negative!\n");
  exit(0);
}
else {
  float radius = atof(argv[1]);
  float height = atof(argv[2]);
  float calcul = ((2 * PI) * radius * height) + ((2 * PI) * radius * radius);
  printf("%.2f\n", calcul);
};

return 0;
};
