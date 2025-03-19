/*
  a program which accepts a number of books and their details,stores them with linked lists and dynamic memory allocation, and thus displays them based on the year given in the command line.
  Author: Rafael Lance Catalan
*/
// includes
#include <stdio.h>
#include <stdlib.h> // required for malloc, free() after the fact and atoi().
#include <string.h> // required for strcpy().
// typedef for our node structure of the linked list - ease of use
typedef struct Node Node;

// node structure - requires the book name, author, year of publication and the pointer for the next/previous. We will use a doubly-linked list.
struct Node
{
  char title[100];
  char author[100];
  int YearPub;
  Node * pNextNode;
  Node * pPrevNode;
};

// function prototyping
Node * LiliPop(Node * li, int * argcount, char * argv[]); //linked list populate. given a linked list pointer, the numbers to enter, and argv. Returns the head of the list upon exit.
void BookPrint(Node * pLi); // prints out the entire catalogue in the order it was entered, given the linked list head node.
void YearSeek(Node * pLi, int Year); // Seeks through the linked list (given its head) and prints books which are published after it.
//main
int main(int argc, char * argv[])
{
  // initialise variables.
  int argcount;
  Node * pLiliNum; // linked list based on our node, which will be added to later.
  // variable action.
  argcount = atoi(argv[1]); // the amount of books to enter is given by argv[1]. we skip by argc shenanigans altogether.
  pLiliNum = (Node *)malloc(argcount * (sizeof(Node))); // memory allocated for the amount of ints we are storing.

  if (!pLiliNum) // in the case that the memory allocation fails.
  {
    printf("The memory could not be allocated.\n");
    return 0;
  }
  // initial population, catalog print and yearseek-ing.
  Node * pHead = LiliPop(pLiliNum, &argcount, argv);

  // printf("%d\n", atoi(argv[argc - 1])); // argc only used to find the final command argument, which holds the year required for YearSeek().
  BookPrint(pHead); //print the catalog.
  YearSeek(pHead, atoi(argv[argc - 1])); // find the books published after the given year.

  free(pLiliNum);
  return 0; // program exit.
}

// function programming
Node * LiliPop(Node * li, int * argcount, char * argv[])
{
  Node * pGo; // initialize our pointer to be used per loop, to simplify the names: it is our current node within the loop to populate this linked list.
  //for loop to populate the linked list.
  for (int i = 0; i < *argcount; ++i)
  {
    Node * pGo = &li[i]; // pointer assigned to array li at position i.
    strcpy(pGo->title, (argv[(i * 3) + 2])); // argv hasn't changed. pass by argv[0] and [2], but multiply by three to account for the offset created by 4 items require for each node
    strcpy(pGo->author, (argv[(i * 3) + 3]));
    pGo->YearPub = atoi(argv[(i * 3) + 4]); // publication year must be converted to an integer for later.
    pGo->pPrevNode = NULL;
    pGo->pNextNode = NULL; //next and previous are set to null before the position in the loop is checked.
    if (i > 0)
    {
      pGo->pPrevNode = &li[i -1];
      li[i-1].pNextNode = pGo; //where we are no longer at the head of the linked list, we assign the current node's previous, and the previous node's next.
    }

  }
  return &li[*argcount - 1]; //return the tail, due to how the question requires us to go backwards through the way items were entered.
}

void BookPrint(Node * pLi) //seeks through the entire linked list, given its head, until it hits the tail (where the final Nodes pNextNode is NULL.)
{
  printf("Library Catalog:\n");
  Node * pGo = pLi; //reusing the language from LiliPop, we use pGo as the shorthand for our current Node.
  while (pGo) // while pGo is real and not NULL.
  {
    printf("Title: %s, Author: %s, Year: %d\n", pGo->title, pGo->author, pGo->YearPub);
    pGo = pGo->pPrevNode; // go to the next node.
  }
  return;
}

void YearSeek(Node * pLi, int Year)
{
  int checker = 0; // set to 1 each time a book is found. otherwise, it remains 0...
  printf("\nBooks published after %d:\n", Year); // print a new line, then print the text to indicate that we are seeking for books published after Year.
  Node * pGo = pLi;
  while (pGo)
  {
    // printf("Now looking at %s\n", pGo->title); old comments to seek which book we are currently viewing.
    if (Year < pGo->YearPub)
    {
      printf("Title: %s, Author: %s, Year: %d\n", pGo->title, pGo->author, pGo->YearPub);
      checker++;
    }
    pGo = pGo->pPrevNode; //due to how the question requires the output, we go back through to the previous node.
  }

  if (checker == 0) // ...which, at the end of the loop, will tell whether or not a book was found to begin with.
  {
    printf("No books found published after %d.\n", Year);
  }

  return;
}
