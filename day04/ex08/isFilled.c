#include "header.h"

int isFilled(unsigned int parkingRow) // 1 = TRUE, 0 = FALSE
{
  if (parkingRow & 1) return (isFilled(parkingRow >> 1));
  else return ((parkingRow > 0)? 0 : 1);
}
