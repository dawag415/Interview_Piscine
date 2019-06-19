#include <stdio.h>
#include "header.h"

int isPowerOfTwo(unsigned n)
{
  return (n && (!(n & (n - 1))));
}

int carPosition(unsigned int parkingRow)
{
  if (!isPowerOfTwo(parkingRow)) return (-1);
  unsigned int i = 1, pos = 1;
  while (!(i & parkingRow))
  {
    i = i << 1;
    ++pos;
  }
  return (pos - 1);
}