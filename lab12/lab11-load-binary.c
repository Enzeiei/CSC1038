/*
  a program which reads in data from a binary file for a student's data.
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef
typedef struct Student Student;

struct Student
{
  char Name[50];
  char College[40];
  int Age;
  float Grade;
};

// prototyping

//mainer
int main(int argc, char * argv[])
{
  FILE *pFile = NULL;
  char *filename = "studentBinary.bin";
  pFile = fopen(filename, "rb"); // reading mode
  if(!pFile) // if it fails
  {
    printf("Error opening %s for writing. Program terminated.\n", filename);
    exit(1);
  }
  Student s1;
  int faiz; // namelen
  int blade; // collegelen
  int lennae = fread(&faiz, sizeof(int), 1, pFile); // read in data
  int axel = fread(s1.Name, sizeof(char), (faiz), pFile);
  int crasher = fread(&blade, sizeof(int), 1, pFile);
  int cooleg = fread(s1.College, sizeof(char), blade, pFile);
  int ager =  fread(&s1.Age, sizeof(int), 1, pFile);
  int grader = fread(&s1.Grade, sizeof(float), 1, pFile);
  fclose(pFile);
  //printing
  s1.Name[strlen(s1.Name) - 1] = '\0';
  printf("Name: %s\n", s1.Name);
  printf("College: %s\n", s1.College);
  printf("Age: %d\n", s1.Age);
  printf("Grade: %.2f\n", s1.Grade);

  return 0;
}

