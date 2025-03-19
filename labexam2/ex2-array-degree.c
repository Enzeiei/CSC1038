/*
  A program which receives a list of numbers from argv and prints out the degree of this list.
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
int CountNum(int value, Node * pHead); //given a number to search by, find how many times in the linked list this number appears.
int FindDeg(Node * pHead); // find the degree of the linked list.


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
  // initial population and degreefinding.
  Node * pHead = LiliPop(pLiliNum, &argcount, argv);

  printf("%d\n", FindDeg(pLiliNum));

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

  }
  return &li[0];
}
int CountNum(int val, Node * pGo)
{ //count the amount of times n occurs given linked list val and head.
  int count = 0;

  while (pGo) // while the current assumed Node is a Node, and not NULL.
  {
    if (pGo->value == val) // if the value is what we're looking for...
    {
      count++; // increase the counter.
    }
    pGo = pGo->pNextNode; // onto the next node. this continues until NULL is reached, at which point the while loop will cease.
  }
  return count;
}

int FindDeg(Node * pHead)
{
  Node * pGo = pHead; // pGo - current node and such - don't want to overwrite pHead.
  // vars
  int tmp; //temp variable to count up the degree of the given value.
  int degree = 0; // the highest degree/frequency of number within the linked list.

  while (pGo) // while pGo hasn't gone NULL.
  {
    tmp = CountNum(pGo->value, pGo); //uses the countNum function introduced earlier.
    if (tmp > degree)
    {
      degree = tmp; // if the found degree exceeds the currently held degree, assign that to the held degree.
    }

    pGo = pGo->pNextNode; // to the next node!
  }
  return degree; //return the final degree
}
