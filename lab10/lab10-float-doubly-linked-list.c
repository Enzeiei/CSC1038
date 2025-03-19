/*
  accept command line floats and link them up good.
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node; //typedef for ease of use

struct Node
{
  float value;
  Node *next;
  Node *prev; //new node to make doubly
};

// prototyping
void LilyPop(Node * li, int num_count, char * argv[]); //linked list populate and display.
void LilyDisp(Node * li, int num_count); // modified from singly; will print in reverse.

// mainer
int main(int argc, char * argv[])
{
  int sizer = atoi(argv[1]);
  Node *pLily = (Node*)malloc(sizer * sizeof(Node)); // memory allocate on Node size

  if (pLily == NULL)
  {
    printf("Failed to allocate memory.\n");
    return 0;
  }

  //function calling
  LilyPop(pLily, sizer, argv);
  LilyDisp(pLily, sizer);

  free(pLily);
  return 0;
}

void LilyPop(Node * li, int num_count, char * argv[])
{
  for (int i = 0; i < num_count; i++)
  {
    Node *nGo = &li[i];
    nGo->value = atof(argv[i + 2]);
    // printf("%s, %f\n", argv[i + 2], nGo->value);
    nGo->next = NULL;
    nGo->prev = NULL;
    if (i != 0)
    {
      li[i - 1].next = (nGo);
      nGo->prev = &(li[i - 1]);
    }
  }
  return;
}

void LilyDisp(Node * li, int num_count)
{
  Node * targ = & li[num_count - 1];
  while(targ != NULL)
  {
    printf("%.2f\n", targ->value);
    targ = targ->prev;
  }
  return;
}
