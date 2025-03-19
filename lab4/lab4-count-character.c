/*
  count-character.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charCount(char letter, char *pStringer);

int main(int argc, char * argv[])
{
  char attacker = argv[1][0];
  char *pStringer = argv[2];
  int counted = charCount(attacker, pStringer);

  printf("%d\n", counted);

  return 0;
};

int charCount(char letter, char *pStringer)
{
  int len = strlen(pStringer);
  int num = 0;

  for (int i=0; i < len; i++)
  {
    if (pStringer[i] == letter) {
      num++;
    };
  }

  return num;
};
