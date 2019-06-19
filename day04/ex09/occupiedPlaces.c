#include "header.h"

int add(int x, int y)
{
    if (y == 0)
        return x;
    else
        return add( x ^ y, (x & y) << 1);
}

int occupiedPlaces(unsigned int parkingRow)
{
  int num = 0;

  while (parkingRow)
  {
    num = add(num,(parkingRow & 1));
    parkingRow >>= 1;
  }
  return (num);
}
