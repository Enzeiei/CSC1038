/*

what the fuck
*/
#include <stdio.h>
#include <stdlib.h>

void cac(int * uhhh);

int main(int argc, char * argv[])
{
  int ree = atoi(argv[1]);
  int *pree = &ree;
  printf("%d\n", ree);
  cac(pree);
  printf("%d\n", ree);
  return 0;
}

void cac(int * uhh)
{
  //uhh--;
  printf("%d, %d, %d\n", uhh, &uhh, *uhh);
  *uhh = *uhh - 1;
  return;
}
