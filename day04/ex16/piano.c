#include "header.h"
#include <stdlib.h>


static void convert(int num, int l, int *matrix)
{
  int   i;

  i = 0;
  while (i < l)
  {
    if (num & 1)
      matrix[i] = 1;
    else
      matrix[i] = 0;
    num >>= 1;
    i++;
  }
}

int     **pianoDecompress(struct s_bit *bit, int l)
{
  int   **matrix;
  int   i;

  i = 0;
  matrix = malloc(sizeof(int *) * bit->n);
  while (i < bit->n)
  {
    matrix[i] = calloc(l, sizeof(int));
    convert(bit->arr[i], l, matrix[i]);
    i++;
  }
  return (matrix);
}