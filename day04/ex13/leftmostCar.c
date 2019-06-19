#include "header.h"
int add(int x, int y)
{
    if (y == 0)
        return x;
    else
        return add( x ^ y, (x & y) << 1);
}

int isGt(int a, int b)
{
    int diff = a ^ b;
    diff |= diff >> 1;
    diff |= diff >> 2;
    diff |= diff >> 4;
    diff |= diff >> 8;
    diff |= diff >> 16;

    diff &= ~(diff >> 1) | 0x80000000;
    diff &= (a ^ 0x80000000) & (b ^ 0x7fffffff);

    return diff;
}

int leftmostCar(unsigned int parkingRow)
{
	if (!parkingRow) return (-1);
	int ndx = 0;
	while (isGt(parkingRow,1)) {
  		parkingRow = (parkingRow >> 1);
   		ndx= add(1, ndx);
 	}
 return ndx;
}
