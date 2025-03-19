/*
  take an argument of two ints; the first existing in our given list, the second to be inserted.
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
void LilyPop(Node * li, int num_count, int faiz[]); //linked list populate and display.
void LilyDisp(Node * li, int num_count);
void LilySeekInsertion(Node *li, int num_count, char * argv[]);

// mainer
int main(int argc, char * argv[])
{
  int realnums = atoi(argv[1]);
  int sizer = 10;
  int faiz[10] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
  Node *pLily = (Node*)malloc(sizer * sizeof(Node));

  if (pLily == NULL)
  {
    printf("Failed to allocate memory.\n");
    return 0;
  }

  //function calling
  LilyPop(pLily, sizer, faiz);
  LilySeekInsertion(pLily, sizer, argv);
  LilyDisp(pLily, sizer);

  free(pLily);
  return 0;
}

void LilyPop(Node * li, int num_count, int faiz[])
{
  for (int i = 0; i < num_count; i++)
  {
    Node *nGo = &li[i];
    nGo->value = (faiz[i]);
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

void LilySeekInsertion(Node * li, int num_count, char * argv[])
{
  // we need to reallocate li to insert our new item.
  Node * li2 = realloc(li, (num_count + 1) * sizeof(Node));
  if (li2 == NULL)
  {
    printf("Could not reallocate memory for insertion.\n");
    return;
  }
  int zeeker = atoi(argv[1]);
  Node * targ = &li2[0];
  while (targ != NULL && targ->value != zeeker)
  {
    targ = targ->next;
  }
  if (targ != NULL)
  {
    Node *nGo = &li2[num_count]; // index doesnt matter if we're tracking by links only.
    nGo->value = atoi(argv[2]);
    // printf("%d,\n", nGo->value);
    nGo->next = targ->next;
    targ->next = nGo;
  }
  else
  {
    printf("Could not find searched value.\n");
  }
  return;
}
