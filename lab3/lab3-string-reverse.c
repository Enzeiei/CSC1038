/*
  string-reverse.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_len 50

// reversing function
void reversal(char * str) {
  // printf("good shot !!"); // old verification of working
  int worklen = strlen(str);
  for (int go = 0; go < worklen / 2; go++) // will loop through until midpoint, swapping characters along
  {
    char tempy = str[go];
    str[go] = str[worklen - go - 1];
    str[worklen - go - 1] = tempy; // typical end to end swap
  };
  str = '\0'; // null termination
};


int main(int argc, char * argv[])
{
  char rev[max_len + 1]; // max len 50 string to reverse
  strncpy(rev, argv[1], max_len); // grab argv and copy to rev

  // get the string reversed !!
  reversal(rev);

  //print string
  printf("%s\n", rev);

  // printf("%s\n", rev); // old verif working
  return 0;
};
