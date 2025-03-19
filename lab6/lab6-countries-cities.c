/*
  a program to take countries in and get freaky.
  author:Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Country Country; // typedef for ease of use
typedef struct City City;

// City Structure
struct City
{
  char name[100];
  float size;
};

// country structure
struct Country
{
  char name[100];
  struct City cities[3]; // 3 cities per
};

// prototyping
void CountryPop(Country Countrizer, int count2ry, char * argv[]); //country population
void CountryProcess(Country Countrizer, int count2ry);

// mainer
int main(int argc, char * argv[])
{
  // var init
  int country_count;

  country_count = (argc - 1) / 7; // -1 to handle arg[0], 7 for the amount of args per country and cities
  Country Countrize = (Country *)malloc(country_count * sizeof(Country)));

  if (!pCountrize) // in the case that the memory allocation fails.
  {
    printf("The memory failed to allocate.\n");
    return 0;
  };
  // main function running
  CountryPop(Countrize, country_count, argv);

  return 0;
};

void CountryPop(Country Countrizer, int count2ry, char * argv[])
{
  for (int i = 1, i < count2ry, i++)
  {

  };
  return;
}

void CountryProcess(Country Countrizer, int count2ry)
{
  return;
}
