/*
  she long on my words
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//protoform

void printWordfromString(char str[], int startword);
int findLongestWord(char str[]); //char str[] appears to just be a string bc char array !?
// find longest word just give the index of the start of the word, from which printword hits
// which runsuntil it hits the end of the string or a space, indicating end of word.

int main(int argc, char * argv[])
{
  int startword = findLongestWord(argv[1]);
  printWordfromString(argv[1], startword);

  return 0;
}

void printWordfromString(char str[], int startword)
{
  int i = startword;
  while((str[i] != '\0') && (str[i] != ' '))
  {
    printf("%c", str[i]);
    ++i;
  }
  printf("\n");
}

int findLongestWord(char str[]) //string grabbing !!
{
  int startword = 0;
  int maxWordLength = 0;
  int i = -1;
  int wordLength = 0;

  do {
    ++i;
    if ((str[i] == ' ') || (str[i] == '\0'))
    {
      if (wordLength > maxWordLength)
      {
        maxWordLength = wordLength;
        startword = i - wordLength;
      }
      wordLength = 0;
    }
    else
    {
      wordLength++;
    }
  } while(str[i] != '\0');
  return startword;
}
