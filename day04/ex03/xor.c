#include <string.h>
#include "header.h"
#include <stdlib.h>

char *getXor(char *a, char *b)
{
  int len = strlen(a);
  char *ret = (char*)malloc(len * sizeof(char));

  while (--len >= 0)
  {
    if (a[len] == '1' && b[len] == '0') ret[len] = '1';
    else if (a[len] == '0' && b[len] == '1') ret[len] = '1';
    else if (a[len] == '1' && b[len] == '1') ret[len] = '0';
    else if (a[len] == '0' && b[len] == '0') ret[len] = '0';
  }
  return (ret);
}

int toInt(char *bits)
{
  int len = strlen(bits);
  int i = 1;
  int ret = 0;
  int isNeg = 1;

  while (--len >= 0)
  {
    if (bits[len] == '0') isNeg = 0;
    ret += (bits[len] - '0') * i;
    i *= 2;
  }
  if (isNeg) ret = -ret;
  return (ret);
}
