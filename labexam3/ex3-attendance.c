/*
  A program which accepts  agiven amount of attendance records for n amount of stdents, given the attendance codes P, A and L.
  Using a given algorithm, we can determine if their attendance status is a 1 or a 0
  author: Rafael Lance Catalan
*/

// includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs to hold the data of students.
typedef struct StudAtt StudAtt;// Student attendance Node.

struct StudAtt // a singly linked list for sake of convenience and efficiency.
{
  char record[50]; // char array/string, storing the data
  int lstr; // the length of the above string.
  int attval; //the attendance value. may be changed to 1 to denote good attendance.
  StudAtt * pNext;
};

// prototyping
StudAtt * StuPop(StudAtt * St, int * runtime, char * argv[]); //populate the array of StudentAttendance.
void StuRead(StudAtt * pSt); // uses the pointer of a single StudAtt node as the basis to work from.
// main
int main(int argc, char * argv[])
{
  StudAtt * Studenter; //intialise our struct array pointer... thing.
  int runner = (argc - 1); // remove argv[0], the name of the program frmo argcount.
  Studenter = (StudAtt *)malloc(runner * (sizeof(StudAtt))); // allocating memory for our array of student attendance.

  //function usage
  StudAtt * Start = StuPop(Studenter, &runner, argv); //pointerise/use the memory address for the student array and the runtime int.
  // printf("%d\n", Start->lstr); // old test to ensure that the strlen is indeed working
  StuRead(Start);

  // free the allocated memory before exit
  free(Studenter);
  return 0;
}

StudAtt * StuPop(StudAtt * St, int * runtime, char * argv[])
{
  StudAtt * pEntry; //Pointer based on StudAtt.
  // populate the array.
  for (int i = 0; i < (*runtime); ++i)
  {
    pEntry = &St[i]; // assign entry to the address of that index of our attendance array
    strcpy(pEntry->record, argv[i + 1]); // offset due to argv[0];
    pEntry->lstr = strlen((pEntry->record)); //len of record for later use
    pEntry->attval = 0; //assigning default attendance value.
    if (i != 0)
    {
      (&St[i - 1])->pNext = pEntry;
    }
  }
  return &St[0];
}

void StuRead(StudAtt * pSt)
{
  StudAtt * pEntry = pSt; // same pointer thing from the above function; ease of use.
  while (pEntry != NULL)
  {
  int absence = 0; //our absence value. will be incremented with each A (absent) or 4 consecutive Ls (late).
  // for loop through the string/char array and strcmp accordingly.
  int Looper = 0; //for when counting consecutive Ls.

  for (int i = 0; i < (pEntry->lstr); ++i)
  {
    int gaia = (strncmp(&(pEntry->record)[i], "A", 1)); // for A
    int dragoon = (strncmp(&(pEntry->record)[i], "L", 1)); //for L
    // printf("%c, %d, | %d (%d counted absences)\n", (pEntry->record)[i], gaia, dragoon, absence); //tests
    if (gaia == 0)// for A.
    {
      absence++;
      Looper = 0; // anything that isnt L resets the consecutive read.
    }
    else if (dragoon == 0) // for L
    {
      Looper++;
      if (Looper >= 4)
      {
        absence++;
      }
    }
    else // for P.
    {
      Looper = 0;
    }
    // printf("%d", absence);
    if (absence >= 4)
    {
      pEntry->attval = 1;
    }
  }
  printf("%d\n", pEntry->attval); // print the final attendance value.
  pEntry = pEntry->pNext; //onto the next Node.

  }
  return;
}
