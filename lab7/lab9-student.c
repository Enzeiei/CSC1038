/*
  process student data and display such.
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
void display(Students *student, int stu_count);

// main

int main(int argc, char * argv[])
{
  int stu_count = (argc - 1) / 3; // remove program and, due to the three elements per student, divide by three.
  int size = 2; // as per the original question

  Students *student = (Students*)malloc(size * sizeof(Students));

  if (student == NULL) // print if not enough memory
  {
    printf("Could not allocate.\n");
  }

  // there will be more than 2 students that we will need to reallocate for.
  if (stu_count > size)
  {
    // reallocate based on student count.
    Students *tmp = (Students*)realloc(student, stu_count * sizeof(Students)); // tmp array for reallocation
    if (tmp == NULL) // if unable to reallocate
    {
      printf("Could not reallocate.\n");
    }
  }


  // function calling

  populate(student, stu_count, argv);
  display(student, stu_count);

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

void display(Students *student, int stu_count)
{

  for (int i = 0; i < stu_count; i++)
  {
    // printall
    printf("%s, %s, %.2f\n", student[i].name, student[i].programme, student[i].grade);
  }

  return;
}
