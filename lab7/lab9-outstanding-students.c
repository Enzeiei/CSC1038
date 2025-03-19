/*
  process student data and get students of the higher than average.
  Author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students Students; //typedefs for ease of use

struct Students
{
  char name[20];
  char programme[20];
  float grade;
};

// function proto
void populate(Students *student, int stu_count, char*argv[]);
float meangrab(Students *student, int stu_count);
void display(Students *student, int stu_count, float mean);

// main

int main(int argc, char * argv[])
{
  int stu_count = (argc - 1) / 3; // remove program and, due to the three elements per student, divide by three.

  Students *student = (Students*)malloc(stu_count * sizeof(Students));

  if (student == NULL) // print if not enough memory
  {
    printf("Not enough memory!\n");
  }

  // function calling

  populate(student, stu_count, argv);
  float meaner = meangrab(student, stu_count);
  display(student, stu_count, meaner);

  free(student); // frees the allocated memory for student

  return 0;
}

void populate(Students * student, int stu_count, char*argv[])
{
  for(int i = 0; i < stu_count; i++)
  {
    strcpy(student[i].name, argv[i * 3 + 1]);//copies the name of each student  which is always first in student
    strcpy(student[i].programme, argv[i * 3 + 2]);//copies the programme of study of each student
    student[i].grade = atof(argv[i * 3 + 3]);//gets the grade for each student
  }
  return;
}

float meangrab(Students *student, int stu_count)
{
  float mean;
  //mean is the grade of eahc student added together and then divide by the amount of students
  for(int i = 0; i < stu_count; i++)
  {
    mean += student[i].grade;
  }
    mean = mean / stu_count;

  return mean;
}


void display(Students *student, int stu_count, float mean)
{

  for (int i = 0; i < stu_count; i++)
  {
    // Find all csce students who are above the overall average, and print
    if (student[i].grade > mean && strcmp(student[i].programme, "CSCE") == 0)
    {
      printf("%s, %.2f\n", student[i].name, student[i].grade);
    }
  }
  printf("Average grade: %.2f\n", mean); // avg
  return;
}
