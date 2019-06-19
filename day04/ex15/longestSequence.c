#include "header.h"
int add(int x, int y)
{
    if (y == 0)
        return x;
    else
        return add( x ^ y, (x & y) << 1);
}

int longestSequence(unsigned int parkingRow) {
  int count = 0;
  while (parkingRow)
  { 
    parkingRow = (parkingRow & (parkingRow << 1));
    count = add(count,1);
  }
  return count;
}