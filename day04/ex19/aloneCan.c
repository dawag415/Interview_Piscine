#include "header.h"
#include <stdio.h>

void aloneCan(int *arr, int n)
{
  int num = arr[--n];
  while (n >= 0)
  	num ^= arr[n--];
  printf("%d\n", num);
}
