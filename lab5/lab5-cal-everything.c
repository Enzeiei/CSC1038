/*
  cal-everything.c
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float sum(int, int);
float difference(int, int);
float product(int, int);
float division(int, int);
float power(int, int);
float natlog(int, int);

int main(int argc, char * argv[])
{
  int one = atoi(argv[1]);
  int two = atoi(argv[2]);
  // printf("%d %d wah\n", one, two);
  float reso = 0.0;
  float (*pfunction)(int, int); //declare !

  pfunction = sum;
  reso = pfunction(one, two);
  printf("%.02f\n", reso);

  pfunction = difference;
  reso = pfunction(one, two);
  printf("%.02f\n", reso);

  pfunction = product;
  reso = pfunction(one, two);
  printf("%.02f\n", reso);

  pfunction = division;
  reso = pfunction(one, two);
  printf("%.02f\n", reso);

  pfunction = power;
  reso = pfunction(one, two);
  printf("%.02f\n", reso);

  pfunction = natlog;
  reso = pfunction(one, two);
  printf("%.02f\n", reso);

  return 0;

}

float sum(int x, int y)
{
  // printf("%f %f thang\n", x, y);
  return (float)x + (float)y;
}

float difference(int x, int y)
{
  return (float)x - (float)y;
}

float product(int x, int y)
{
  return (float)x * (float)y;
}

float division(int x, int y)
{
  return (float)x / (float)y;
}

float power(int x, int y)
{
  return pow ((float)x, (float)y);
}

float natlog(int x, int y)
{
  return log ((float)x) + log ((float)y);
}
