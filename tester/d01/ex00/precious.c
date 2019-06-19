#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

char *precious(int *text, int size)
{
  char *arr;
  int   i = 0;
  struct s_node *list;
  int n = 0;
  struct s_node *start;
  int j = 0;
  int len = (int)strlen(CS);

  arr = (char*)malloc(size * sizeof(char));
  list = (struct s_node*)malloc(sizeof(struct s_node));
  start = (struct s_node*)malloc(sizeof(struct s_node));
  start = list;
  while (n < len - 1)
  {
    list->next = (struct s_node*)malloc(sizeof(struct s_node));
    list->next->prev = list;
    list->c = CS[n];
    list = list->next;
    list->next = NULL;
    ++n;
  }
  list->next = start;
  list->next->prev = list;
  list = list->next;
  while (i < size)
  {
    j = text[i];
    if (j == 0)
          arr[i] = list->c;
    else if (text[i] < 0)
    {
      while (j++ < 0)
        list = list->prev;
      arr[i] = list->c;
    }
    else if (text[i] > 0)
    {
      while (j-- > 0)
        list = list->next;
      arr[i] = list->c;
    }
    ++i;
  }
  return (arr);
}