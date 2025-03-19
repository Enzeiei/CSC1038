/*
  a program which accepts a number of positive integers and removes the primes present. the average of the remaining values is calculated. Doubly linked lists and Dynamic memory allocation will be used.
  author: Rafael Lance Catalan
*/


// includes.
#include <stdio.h>
#include <stdlib.h> // required for malloc, free() after the fact and atoi().


// typedef for our node structure of the linked list - ease of use
typedef struct Node Node;


// node structure - includes integer value, as well as address of next/prev Nodes.
struct Node
{
  int value;
  float subval;
  Node * pNextNode;
  Node * pPrevNode;
};


// prototyping.
Node * LiliPop(Node * li, int * argcount, char * argv[]); //linked list populate. given a linked list pointer, the numbers to enter, and argv. Returns the head of the list upon exit.
int PrimeDiscern(int * target); //discern whether or not the given int is a prime or not.
int LiliSum(Node * pLi); // uses the Node pointer given by Lilipop to sum the numbers after the fact.
void LiliRead(Node * pLi);
// main.
int main(int argc, char * argv[])
{
  // initialise variables.
  int argcount;
  Node * pLiliNum; // linked list based on our node, which will be added to later.
  // variable action.
  argcount = argc - 1; //argc counts argv[0], the program name. -1 to account for this.
  pLiliNum = (Node *)malloc((argcount + 1) * (sizeof(Node))); // memory allocated for the amount of ints we are storing.
  // adding one in case the argv is full of nonprimes
  if (!pLiliNum) // in the case that the memory allocation fails.
  {
    printf("The memory could not be allocated.\n");
    return 0;
  }
  // initial population and sorting.
  Node * pHead = LiliPop(pLiliNum, &argcount, argv);

  // printf("%d\n", argcount); ditto below
  // printf("%d\n", pHead->value); old test for if pHead was returned successfully.

  float argsum = LiliSum(pHead);
  int argweird = LiliSum(pHead); //for checking if float and int ver are the same.
  if (!argsum)
  {
    printf("0\n");
  }
  else
  {
    float argdone = (argsum / argcount);
    int arghuh = (argweird / argcount);
    Node * pGoF;
    pGoF = &pLiliNum[argcount];
    if (argdone == arghuh)
    {
      pGoF->value = arghuh;
    }
    else
    {
      pGoF->subval = argdone; // a workaround to printing an int vs float value at the end.
    }
    pGoF->pPrevNode = &pLiliNum[argcount - 1];
    (pGoF->pPrevNode)->pNextNode = pGoF;
    pGoF->pNextNode = NULL; // the final node has to be added to our original list outside of the loop.
    LiliRead(pHead);
  }

  free(pLiliNum); // free the allocated memory.
  return 0; // program exit.
}

// function programming
Node * LiliPop(Node * li, int * argcount, char * argv[])
{
  Node * pGo; // initialize our pointer to be used per loop.
  //for loop to populate the linked list.
  int stablecount = *argcount; // copied argcount.
  int offsetter = 0; // in the case where we read over a prime, we need to offset the position in the array of nodes to account for this.
  for (int i = 0; i < stablecount; ++i)
  {
    int num = atoi(argv[i +1]);
    if (PrimeDiscern(&num))
    {
      Node * pGo = &li[i - offsetter]; // special pointer for each loop.
      pGo->value = num;
      pGo->pPrevNode = NULL;
      pGo->pNextNode = NULL; //next and previous are set to null before the position in the loop is checked.
      if (i > 0)
      {
        pGo->pPrevNode = &li[i - 1 - offsetter];
        li[i - 1 - offsetter].pNextNode = pGo;
      }

      //printf("%d\n", pGo->value); // old test to ensure the right vlaues are being entered, repurposed due to the nature of the question.
    }
    else
    {
      offsetter++;
    }

  }
  // argcount must be modified in order to account for the potential loss of primes
  *argcount -= offsetter;

  return &li[0];
}

int PrimeDiscern(int * target)
{
  int a = (*target % 2) == 0;
  int b = (*target % 3) == 0;
  int c = (*target % 5) == 0; // if the target
  int d = (*target % 7) == 0;
  int e = (*target % 17) == 0;
  int f = (*target % 19) == 0;
  int g = (*target % 13) == 0;
  // printf("%d | %d %d %d %d\n", *target, a, b, c, d);
  if ((*target == 2) || (*target == 3) || (*target == 5) || (*target == 7))
  {
    // printf("huh\n");
    return 0;
  }
  else if (a || b || c || d || e || f || g)
  {
    // printf("5437 passes here..\n");
    return 1;
  }
  else if (*target == 1)
  {
    return 1;
  }
  // printf("sigma\n");
  return 0;
}

int LiliSum(Node * pLi)
{
  int sum = 0; // sum variable.
  while (pLi)
  {
    sum += (pLi->value);
    pLi = pLi->pNextNode;
  }
  return sum;
}

void LiliRead(Node *pLi)
{
  while (pLi)
  {
    if (pLi->subval)
    {
      printf("%.2f\n", (pLi->subval));
    }
    else
    {
      printf("%d\n", pLi->value);
    }
    pLi = pLi->pNextNode;
  }
  return;
}
