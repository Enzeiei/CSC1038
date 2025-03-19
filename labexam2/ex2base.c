/*
  a program which accepts a number of books and their details,stores them with linked lists and dynamic memory allocation, and thus displays them based on the year given in the command line.
  Author: Rafael Lance Catalan
*/
// includes
#include <stdio.h>
#include <stdlib.h> // required for malloc, free() after the fact and atoi().

// typedef for our node structure of the linked list - ease of use
typedef struct Node Node;

// node structure - requires the value and the pointer for the next/previous. We will use a doubly-linked list.
struct Node
{
  int value;
  Node * pNextNode;
  Node * pPrevNode;
};

// function prototyping
Node * LiliPop(Node * li, int * argcount, char * argv[]); //linked list populate. given a linked list pointer, the numbers to enter, and argv. Returns the head of the list upon exit.
void LiliSort(Node * pLi); // sorts the given linked list, given a pointer for it.
//main
int main(int argc, char * argv[])
{
  // initialise variables.
  int argcount;
  Node * pLiliNum; // linked list based on our node, which will be added to later.
  // variable action.
  argcount = argc - 1; //argc counts argv[0], the program name. -1 to account for this.
  pLiliNum = (Node *)malloc(argcount * (sizeof(Node))); // memory allocated for the amount of ints we are storing.

  if (!pLiliNum) // in the case that the memory allocation fails.
  {
    printf("The memory could not be allocated.\n");
    return 0;
  }
  // initial population and sorting.
  Node * pHead = LiliPop(pLiliNum, &argcount, argv);

  printf("%d\n", pHead->value);
  //LiliSort(pLiliNum);

  free(pLiliNum);
  return 0; // program exit.
}

// function programming
Node * LiliPop(Node * li, int * argcount, char * argv[])
{
  Node * pGo; // initialize our pointer to be used per loop.
  //for loop to populate the linked list.
  for (int i = 0; i < *argcount; ++i)
  {
    Node * pGo = &li[i]; // special pointer for each loop.
    pGo->value = atoi(argv[i + 1]);
    pGo->pPrevNode = NULL;
    pGo->pNextNode = NULL; //next and previous are set to null before the position in the loop is checked.
    if (i > 0)
    {
      pGo->pPrevNode = &li[i -1];
      li[i-1].pNextNode = pGo;
    }
    printf("%d entered.\n", pGo->value);
  }
  return &li[0];
}

