/*
  accept command line numbers and create a singly linked list for each from there.
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node; //typedef for ease of use

struct Node
{
  int value;
  Node *next;
};

// prototyping
void LilyPop(Node * li, int num_count, char * argv[]); //linked list populate and display.
void LilyDisp(Node * li, int num_count);

// mainer
int main(int argc, char * argv[])
{
  int sizer = atoi(argv[1]);
  Node *pLily = (Node*)malloc(sizer * sizeof(Node));

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
    nGo->value = atoi(argv[i + 2]);
    nGo->next = NULL;
    if (i != 0)
    {
      li[i - 1].next = (nGo);
    }
  }
  return;
}

void LilyDisp(Node * li, int num_count)
{
  Node * targ = & li[0];
  while(targ != NULL)
  {
    printf("%d\n", targ->value);
    targ = targ->next;
  }
  return;
}
