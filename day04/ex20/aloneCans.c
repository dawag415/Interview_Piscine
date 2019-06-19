#include "header.h"

void aloneCans(int *arr, int n)
{
  int i = -1;
  int num = arr[--n];
  while (n >= 0) num ^= arr[n--];
  int set = num & ~(num - 1)
  
  printf("%d\n", num);
}
