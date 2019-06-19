#include "header.h"
#include <string.h>
#include <stdlib.h>

void negate(char *a)
{
  for (int i=1; i<5 ; i++)
  {
    if (a[i]=='0')
      a[i]='1';
    else
      a[i]='0';
  }
  return;
}

char *getAnd(char *a, char *b)
{  char *ret;
  ret= (char*)malloc(5 * sizeof(char));
  ret[4]=0;
  if (a[0] == '~')
  {
    negate(a);
    a++;
  }
  if (b[0]=='~')
  {
    negate(b);
    b++;
  }
  for (int i=0;i<=3; i++)
    ret[i]=a[i]&b[i];
  return (ret);
}

char *getOr(char *a, char *b)
{ char *ret;
  ret = (char*)malloc(5 * sizeof(char));
  ret[4]=0;
  if (a[0] == '~')
  {
    negate(a);
    a++;
  }
  if (b[0]=='~')
  {
    negate(b);
    b++;
  }
  for (int i=0;i<=3; i++)
    ret[i]=(a[i]|b[i]);
  return (ret);
}

int toInt(char *bits)
{
  // int len =strlen(bits);


  // int n = (int) strtol(bits, &bits+len, 2);
  // return (n);
  int len = strlen(bits);
  int i = 1;
  int ret = 0;

  while (--len >= 0)
  {
    ret += (bits[len] - '0') * i;
    i *= 2;
  }
  return (ret);
}
