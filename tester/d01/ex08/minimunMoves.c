#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int minimumMoves(struct s_node *node)
{
  int i = 0;
  int j = 0;
  if (!node) return (0);
  if (node->isFinal)
  {
//    printf("FINAL\n");
    return(1);
  
  }
  if (node->isFinal==0)
  {
    if (node->next != NULL)
      i=minimumMoves(node->next);
 //   printf("i : %d\n", i);
    if (node->random !=NULL)
      j=minimumMoves(node->random);
//    printf("j : %d\n", j);
    if (i==0 && j!=0)
      return(j+1);
    if (j==0 && i!=0)
      return(i+1);

  }
 // printf("value: %d  ;  i or j : %d\n",node->value , (i<j )? i+1 :j+1);
  return ((i<j) ? i+1 :j+1);
}