/*
  modified singly linked list. pop and pushing now functions.
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
void PopRem(Node * li, int * num_count); //Pops; removes the last item of the list, updates numcount as such.
void LilyPush(Node * li, int * num_count, int poppers, int total, char * argv[]); //pushes new item to the front of the list.

// mainer
int main(int argc, char * argv[])
{
  int sizer = atoi(argv[1]); // only used for initial populating.
  int foolsize = sizer; //copy of sizer for keeping index; the real size.
  int total = argc - 1; // grabbing the total args.
  Node *pLily = (Node*)malloc(sizer * sizeof(Node));

  if (pLily == NULL)
  {
    printf("Failed to allocate memory.\n");
    return 0;
  }

  //function calling
  LilyPop(pLily, sizer, argv);
  //LilyDisp(pLily, sizer);
  //printf("--, %d\n", sizer);
  PopRem(pLily, &foolsize);
  PopRem(pLily, &foolsize); // 2 pops
  LilyPush(pLily, &foolsize, sizer, total, argv);
  LilyPush(pLily, &foolsize, sizer, total, argv); // 2 pushes.
  LilyDisp(pLily, foolsize);
  // printf("--, %d\n", sizer);

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

void PopRem(Node * li, int * num_count)
{
  //li[*num_count - 1] = NULL; // target node is NULL'd.
  li[*num_count - 2].next = NULL; // its reference in the node before is also rendered NULL.
  *num_count = *num_count - 1;
  return;
}
void LilyPush(Node * li, int * num_count, int poppers, int total, char * argv[])
{
  Node *nGo = &li[*num_count]; // mostly the same as population
  nGo->value = atoi(argv[*num_count + (total - poppers) + 1]); // combination of offsets
  nGo->next = NULL;
  li[*num_count - 1]. next = nGo;
  *num_count = *num_count + 1;

  return;
}
