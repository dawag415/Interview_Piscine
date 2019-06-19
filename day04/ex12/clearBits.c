#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
  parkingRow >>= n;
  return (parkingRow << n);
}
