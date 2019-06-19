#include <stdlib.h>
#include "header.h"

struct s_node  *recurse(int start, int *arr, int end)
{
  if (start > end) return (NULL);
  int mid = (start + end) / 2;
  struct s_node *new = (struct s_node*)malloc(sizeof(struct s_node));

  new->value = arr[mid];
  new->left = recurse(start, arr, mid - 1);
  new->right = recurse(mid + 1, arr, end);
  return (new);
}

struct s_node *createBST(int *arr, int n)
{
  struct s_node *bst = (struct s_node*)malloc(sizeof(struct s_node));

  bst = recurse(0, arr, n - 1);
  return (bst);
}