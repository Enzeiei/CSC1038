/*
  find the most frequent occurence of a given letter.
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countOccurence(char* str, char target); //str being our argv
int in_already(char str[], char targ);

int main(int argc, char * argv[])
{
  char * str = argv[1]; // rather than cloning, we make a direct reference to argv[1], our string.
  char * pMax = str; //doubleup ??
  char uni[strlen(str)];
  int maxxer = 0;
  int freaker = 0;
  for (char *p = str; *p != '\0'; p++)
  {
    if (('a'< *p) && (*p < 'z') && (in_already(uni, *p))) // the way this works means that no matter if we've read for the letter already, it'll still run anyway.
    {
      // printf("yurr %c\n", *p);
      int count = countOccurence(argv[1], *p);
      if (count > maxxer)
      {
        pMax = p;
        maxxer = count;
      }
      uni[freaker] = *p;
      freaker++;
    }
  }
  printf("%c\n", *pMax);
  return 0;
}

int countOccurence(char* str, char target)
{
  char *pstr;
  int count = 0;
  int *pCount = &count;

  pstr = strchr(str, target);
  while (pstr)
  {
    ++*pCount;
    pstr = strchr(pstr + 1, target);
  }
  return *pCount;
}

int in_already(char str[], char targ)
{
  int it_girl = strlen(str);
  for(int i = 0; i < it_girl; i++)
  {
    if (str[i] == targ)
    {
      return 0;
    }
  }

  return 1;
}
