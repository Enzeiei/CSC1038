/*
 convert-units.c
 author Rafael Lance Catalan
 */


#include <stdio.h>
#include <stdlib.h>
#define CONV 2.54
// CONV representing conversion
int main(int argc, char * argv[])
{
  //var init
  // float centi = 0.0;
  float inches = 0.0;
  int lowbound = 30;
  int highbound = 50;
  int fivelooper = 0; // loop to ensure columns
  /* if i only declare the length variables as int here, it breaks further along with the written code, especially relating to the final printf.
  the variables will be changed back to float.*/
  /*char st[5]; // st user input variable
  printf("Enter centimeters: ");
  scanf("%s", st);*/

  while (lowbound < highbound) {
    fivelooper = 0;
    while (fivelooper < 5) {
      inches = lowbound / CONV;

      printf("%.2f ", inches);
      fivelooper++;
      lowbound++;
    };
  printf("\n");
  };

  /*centi = atoi(argv[1]); // if using user input atoi would be applied to st
  inches = centi / CONV;

  printf("%.2f\n", inches);*/

  return (0);
}
