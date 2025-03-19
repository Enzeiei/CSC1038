/*
  get one country and print it out | get-a-country.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Country Country;

struct Country
{
  char name[50];
  char capital[50];
  int size;
  float population;
};

// function prototype
void country_pop(Country country[], int num, char * argv[]);
void country_print(Country country[], int num);

//mainer
int main(int argc, char * argv[])
{
  int processor = ((argc - 1) / 4); //future use for when there is more than one country to process

  Country country[5]; //an array that can have 5 countries
  //printf("%s wah\n", argv[4]);

  country_pop(country, processor, argv);
  country_print(country, processor);

  return 0;
}

//real functionism hours
void country_pop(Country country[], int num, char * argv[])
{
  for (int i = 0; i < num; i++)
  {
    strcpy(country[i].name, argv[(i * 4) + 1]);
    strcpy(country[i].capital, argv[(i * 4) + 2]);
    country[i].population = atof(argv[(i * 4) + 3]);
    country[i].size = atoi(argv[(i * 4) + 4]);
  };
}

void country_print(Country country[], int num)
{
  for (int i = 0; i < num; i++)
  {
    printf("%s\n", country[i].name);
    printf("%s\n", country[i].capital);
    printf("%.2f million people\n", country[i].population);
    printf("%d km2\n", country[i].size); // done on indinvidual lines for understanding
  };
}
