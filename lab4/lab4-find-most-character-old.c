/*
  find-most-character.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 256

char runner(char *pString);

int main(int argc, char * argv[])
{
  char *pStringer = argv[1];
  char reso;

  reso = runner(pStringer);
  printf("%c\n", reso);

  return 0;
}

char runner(char *pString)
{
  int high = -1;
  int lenner;
  int it = 0;
  char reso;
  int pointers[MAX] = {0};

  lenner = strlen(pString);

  for (int i = 0; i < lenner; i++)
  {
    if (isalpha(pString[i]))
    {
      pointers[i]++;
    };
  }

  while (it < lenner) {
    if (isalpha(pString[it]))
    {
      if (high < pointers[pString[it]]) {
        high = pointers[pString[it]];
      };
    };
  it++;
  };
  return high;
}
