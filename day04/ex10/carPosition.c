#include "header.h"
int add(int x, int y)
{
    if (y == 0)
        return x;
    else
        return add( x ^ y, (x & y) << 1);
}

int sub(int x, int y)
{
    if (y == 0)
        return x;
    return sub(x ^ y, (~x & y) << 1);
}


int carPosition(unsigned int parkingRow)
{
  int cars = 0;
	int pos = 0;

  while (parkingRow)
  {
    cars =add(cars, parkingRow & 1);
    parkingRow >>= 1;
	if  (sub(cars,1))
	  pos =add (pos, 1);
  }
  return (!sub(cars, 1)? pos: -1);
}
