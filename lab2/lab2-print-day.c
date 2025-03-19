/*
  print-day.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{

char dayser[7][7] = {"Sun", "Mon", "Tues", "Wednes", "Thurs", "Fri", "Satur"};

printf("%sday\n", dayser[atoi(argv[1]) - 1]);

return 0;
};
