#include "header.h"
#include <math.h>
int sub(int x, int y)
{
    if (y == 0)
        return x;
    return sub(x ^ y, (~x & y) << 1);
}


int rightmostCar(unsigned int parkingRow)
{if (!parkingRow) return (-1);
  return (log2(parkingRow & (sub(0,parkingRow))));
}
