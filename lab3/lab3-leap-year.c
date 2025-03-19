/*
  leap year getter !
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

//prototyping
void yearthrough(int start, int end);

int main(int argc, char * argv[])
{
  if ((argc - 1) == 2)
  {
    int st = atoi(argv[1]);
    int en = atoi(argv[2]);

    yearthrough(st, en);
  }

  return 0;
}

void yearthrough(int start, int end)
{
  for (int i = start; i <= end; ++i)
  {
    if (i % 400 == 0)
    {
      printf("%d\n", i);
    }
    else if ((i % 100 != 0) && (i % 4 == 0))
    {
      printf("%d\n", i);
    }
  }
}
