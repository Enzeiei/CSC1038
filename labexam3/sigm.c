#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  for (int i = 2; i < 100; i++)
  {
    float ah = (323 % i);
    if (ah == 0)
    printf("%d the goat\n", i);
    //printf("%d, %.2f\n", i, ah);
  }

  return 0;
}
