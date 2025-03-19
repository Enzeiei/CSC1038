/*
  sort-numbers.c | sort the numbers.
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// prototyping
void ascBubb(int nums[], int proc);
void dscBubb(int nums[], int proc); // bubble sorts everywhere
void numprint(int nums[], int proc);
int main(int argc, char * argv[])
{
  int proc = atoi(argv[1]); //
  int numbers[proc]; // denotes the amount of nums to process

  for (int i = 2; i < proc + 2; i++)
    {
    numbers[i - 2] = atoi(argv[i]); // Convert argument to int and store it in the array
    }
  void (*pFunc)(int nums[], int proc); //declaring the function pointer.

  if (strcmp("asc", argv[argc - 1])) // grabs the last argument string and compares it against asc(ending).
  {
    pFunc = ascBubb;
  }
  else
  {
    pFunc = dscBubb;
  }

  // apply the pointer func.
  pFunc(numbers, proc);
  pFunc = numprint;
  pFunc(numbers, proc);

  return 0;
}

void ascBubb(int nums[], int proc)
{
  for (int i = 0; i < proc; i++)
  {
    for (int j = 0; j < (proc - 1); j++)
    {
      if (nums[j] < nums [j + 1])
      {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }

  return;
}


void dscBubb(int nums[], int proc)
{
  for (int i = 0; i < proc; i++)
  {
    for (int j = 0; j < (proc - 1); j++)
    {
      if (nums[j] > nums [j + 1])
      {
        int tmp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = tmp;
      }
    }
  }

  return;
}

void numprint(int nums[], int proc)
{
  printf("Sorted Numbers: ");
  for (int i = 0; i < proc; i++)
  {
    printf("%d", nums[i]);

    if (i < (proc - 1))
    {
      printf(" ");
    }
    else
    {
      printf("\n");
    }
  }

  return;
}
