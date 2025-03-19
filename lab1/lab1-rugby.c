/*
 rugby.c
 author Rafael Lance Catalan
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
// var init
  int trygle = 5 * atoi(argv[1]);
  int conversion = 2 * atoi(argv[2]);
  int penalty = 3 * atoi(argv[3]);
  int drop = 3 * atoi(argv[4]);

  int output = trygle + conversion + penalty + drop;

  printf("%i\n", output);

  return 0;
}
