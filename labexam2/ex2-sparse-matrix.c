/*
  A program, which, given the matrix size and .
  Author: Rafael Lance Catalan
*/
// includes
#include <stdio.h>
#include <stdlib.h> // required for malloc, free() after the fact and atoi().

// typedef for our node structure of the linked list - ease of use
typedef struct Node Node;

// node structure - requires the value, row position and column position. We will use a doubly-linked list.
struct Node
{
  int value;
  int rowpos;
  int colpos;
  Node * pNextNode;
  Node * pPrevNode;
};

// function prototyping
Node * LiliPop(Node * li, int * argcount, char * argv[]); //linked list populate. given a linked list pointer, the numbers to enter, and argv. Returns the head of the list upon exit.
void LiliSort(Node * pLi); // sorts the given linked list, given a pointer for it.
void MatrixPrint(int * rows, int * columns, Node * pHead); //prints the matrix needs rows and columns to print, as well as the head of the linked list to figure out what data needs to be a non-zero.

//main
int main(int argc, char * argv[])
{
  // initialise variables.
  int argcount;
  int rowser; //row count.
  int colser; //column count.
  Node * pLiliNum; // linked list based on our node, which will be added to later.
  // variable action.
  argcount = atoi(argv[3]); //the amount of nodes to enter is given already.
  rowser = atoi(argv[1]);
  colser = atoi(argv[2]);
  pLiliNum = (Node *)malloc(argcount * (sizeof(Node))); // memory allocated for the amount of ints we are storing.

  if (!pLiliNum) // in the case that the memory allocation fails.
  {
    printf("The memory could not be allocated.\n");
    return 0;
  }
  // initial population and printting.
  Node * pHead = LiliPop(pLiliNum, &argcount, argv);

  MatrixPrint(&rowser, &colser, pHead);

  free(pLiliNum);
  return 0; // program exit.
}

// function programming
Node * LiliPop(Node * li, int * argcount, char * argv[])
{
  Node * pGo; // initialize our pointer to be used per loop - used for ease of understanding - it's our current Node in the loop.
  //for loop to populate the linked list.
  for (int i = 0; i < *argcount; ++i)
  {
    Node * pGo = &li[i]; // special pointer for each loop.
    pGo->value = atoi(argv[(i * 3) + 4]); //offset must be set per item, * 3 due to the 3 items in each thing.
    pGo->rowpos = atoi(argv[(i * 3) + 5]);
    pGo->colpos = atoi(argv[(i * 3) + 6]);
    // printf("%d, %d, %d\n", pGo->value, pGo->rowpos, pGo->colpos);
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

void MatrixPrint(int * rows, int * columns, Node * pHead)
{
  int sum = 0; // sum for the final diagonal calc.
  Node * pGo = pHead; // reusing pGo as before: just a name to use for our current node.
  // we will use two for loops, goign through the matrix as it was sized from argv[1] and argv[2], the given rows and columns respectively.
  for (int i = 0; i < *rows; ++i) // rows loop.
  {
    for (int j = 0; j < *columns; ++j) //columns loop.
    {
      int currval = 0; // the assumed value at the current position.
      if ((pGo) && (i == pGo->rowpos) && (j == pGo->colpos)) // while pGo is real, if the coords align.
      {
        printf("%d", pGo->value);
        currval = pGo->value;
        pGo = pGo->pNextNode; // next node after being found.
      }
      else
      {
        printf("0");
      }
      if (j < *columns)
      {
        printf(" ");
      }

      //adding up for final diag.
      if (i == j)
      {
        sum = sum + currval;
      }
      // printf("\n"); // incorrect position
    }
    printf("\n"); // for each row.
  }
  if (*rows != *columns)
  {
    sum = 0;
  } // set sum to 0 if the actual matrix isn't a square to begin with.

  printf("Sum of main diagonal: %d\n", sum); //final print for the value of the diagonal.
  return;
}
