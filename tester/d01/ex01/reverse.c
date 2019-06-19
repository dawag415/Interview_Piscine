#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void printReverse(struct s_node *lst)
{
  static int q = 0;
  if (lst)
  {
    q++;
    printReverse(lst->next);
    q--;
    printf("%s", lst->word);
    if (q) printf(" ");
    else printf("\n");
  }
  return ;
}