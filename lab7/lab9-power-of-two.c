/*
  verifies number in argv is a power of 2.
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

// prototyping
void powercheck(int num);

// mainer

int main(int argc, char * argv[])
{
  int num = atoi(argv[1]);
  powercheck(num);
  return 0;
}

void powercheck(int num)
{
  int ah = num & (num - 1);
  if (ah == 0)
  {
    printf("Yes\n");
  }
  else
  {
    printf("No\n");
  }
  return;
}
