#include <stdlib.h>
#include <string.h>
#include "header.h"

char *getSum(char *a, char *b)
{
  int len = strlen(a);
  char *ret = (char*)malloc(sizeof(char) * len);

  while (--len >= 0)
  {
    if (a[len] == b[len] && a[len] == '1')
      ret[len] = '0', ret[--len] = '1';
    else if ((a[len] == '1' && b[len] == '0') ||
             (a[len] == '0' && b[len] == '1'))
             ret[len] = '1';
    else ret[len] = '0';
  }
  return (ret);
}

char *negate(char *a, int len)
{
  int i;
  for (i = 0; i < len; i++)
  {
    if (a[i] == '0') a[i] = '1';
    else a[i] = '0';
  }
  return (getSum(a, "000001"));
}

char *rightShift(char *bin, int k)
{
  int len = strlen(bin);
  int l = len;
  char *ret = (char*)malloc(len * sizeof(char));
char val = '1';
if (bin[0]=='0')
  val = '0';
  while (--len >= 0)
  {
    if (len + k < l) ret[len + k] = bin[len];
    ret[len] = val;
  }
  return (ret);
}

char *leftShift(char *bin, int k)
{
  int len = strlen(bin);
  char *ret = (char*)malloc(len * sizeof(char));
  int i = -1;

  while (++i < len)
  {
    if (i - k >= 0) ret[i - k] = bin[i];
    ret[i] = '0';
  }
  return (ret);
}

int toInt(char *bits)
{
  int len = strlen(bits);
  int l = len;
  int i = 1;
  int ret = 0;
  int isNeg = 1;
  char *tmp = (char*)malloc(sizeof(char));

  while (--l >= 0) tmp[l] = bits[l];
  if (bits[0] == '0') isNeg = 0;
  else tmp = negate(tmp, len);
  while (--len > 0)
  {
    ret += (tmp[len] - '0') * i;
    i *= 2;
  }
  if (isNeg) ret = -ret;
  return (ret);
}