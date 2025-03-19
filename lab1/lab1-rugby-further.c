/*
 rugby.c
 author Rafael Lance Catalan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[])
{
// num archive list init and counter item
int counter = 0;
int numera[] = {-1, -1, -1, -1};
// DATA READ IN ZONE

char nums[10];
printf("Enter trys, conversions, penalty and drops >> ");
char *fgets(nums, int 4, stdin *stream);
printf("Numbers are %s.\n", nums);
char * token;
token = strtok(nums, " ");
// numera[counter] = atoi(token);
//counter++;

while ( token != NULL ) {
      printf("%s\n", token); //printing each token
      numera[counter] = atoi(token);
      token = strtok(NULL, " ");
      counter++;
      };

// printf("passable\n"); //old test
// var init zone
  int trygle = 5 * numera[0];
  int conversion = 2 * numera[1];
  int penalty = 3 * numera[2];
  int drop = 3 * numera[3];

  int output = trygle + conversion + penalty + drop;

  printf("%i\n", output);

  return 0;
}
