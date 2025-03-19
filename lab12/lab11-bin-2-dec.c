/*
  a program that converts binary to decimal, making light use of singly linked lists,
  author: Rafael Lance Catalan
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node; // ease of use typedef

struct Node
{
  int val;
  Node *next;
};
//prototyping
void nodemoder(Node * pNo, int countup, char * argv[], int * checker); // populates the noding
void bineater(int *resultor, Node * pNo, int * countdown);
int power(int base, int exp);

//mainer
int main(int argc, char * argv[])
{
  int numtime = argc - 1; // remove the prog name from the counted args
  if (numtime > 8)
  {
    printf("Too many binary digits entered.\n");
    return 0;
  }

  Node *pLily = (Node*)malloc(numtime * sizeof(Node));

  if (pLily == NULL)
  {
    printf("Failed to allocate memory.\n");
    return 0;
  }
  int checker = 1;
  int result = 0; // result thang
  // function call
  nodemoder(pLily, numtime, argv, &checker);
  if (checker == 1)
  {
  numtime--;
  bineater(&result, pLily, &numtime);
  printf("%d\n", result);
  }
  free(pLily);
  return 0;
}

void nodemoder(Node *pNo, int countup, char * argv[], int * checker)
{
  for (int i = 0; i < countup; i++)
  {
    Node *nGo = &pNo[i];
    // printf("%d, %d, %d\n", atoi(argv[i + 1]), atoi(argv[i + 1]) != 1, atoi(argv[i + 1]) != 0);
    if ((*(argv[i + 1]) != '1') && (*argv[i + 1] != '0'))
    {
      printf("Only digits 1 and 0 are permitted.\n");
      // printf("%d is not real.\n", (*(argv[i + 1])));
      *checker = 0;
      return;
    }
    nGo->val = atoi(argv[i + 1]);
    nGo->next = NULL;
    if (i != 0)
    {
      pNo[i - 1].next = (nGo);
    }
  }

  return;
}

void bineater(int * resultor, Node * pNo, int * countdown)
{
  double bassist;
  Node *targ = &pNo[0];
  while(targ != NULL)
  {
    bassist = power(2, *countdown);
    // printf("current bitval: %d, position left: %d\n", bassist, *countdown);
    *resultor = *resultor + ((targ->val) * bassist);
    targ = targ->next;
    *countdown = *countdown - 1;
  }

  return;
}

int power(int base, int exp)
{
  // printf("%d\n", exp);
  int pvv = 1, i;
  for (i = 1; i <= exp; ++i)
  {
    // printf("%d!!\n", pvv);
    pvv = pvv * base;
  }
  // printf("%d real\n", pvv);
  return pvv;
}
