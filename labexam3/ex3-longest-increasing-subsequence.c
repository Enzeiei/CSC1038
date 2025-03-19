/*
  A program which given an array of ints finds the largest subsequence within.
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
int LiliLIS(Node * li, int * argcount); // finds the largest increasing subseq.

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
  // initial population and thus, finding the largest subsequence.
  Node * pHead = LiliPop(pLiliNum, &argcount, argv);

  printf("%d\n", LiliLIS(pHead, &argcount));

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
    // printf("%d entered.\n", pGo->value);
  }
  return &li[0];
}

int LiliLIS(Node * li, int * argcount)
{
  int largo = 0; // largest LIS sequence
  int templarg;
  int tracker;
  for (int i = 0; i < (*argcount); ++i)
  {
    templarg = 1;
    tracker = li[i].value;
    for (int j = (i + 1); j < (*argcount); ++j)
    {
      if (tracker < li[j].value)
      {
        //printf("%d smaller than %d |", tracker, li[j].value);
        templarg++;
        tracker = li[j].value;
      }
    }
    if (templarg > largo)
    {
      largo = templarg;
    }
    //printf("\n");
  }
  return largo;

} // the above function is of O(n^2), using the bones of a bubble sort and working from there.

