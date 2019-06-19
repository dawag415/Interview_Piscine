#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char *getSum(char *a, char *b)
{
  int carry =48;
  int len = 5;
  char *ret = (char*)calloc(len+2, sizeof(char));

  while (len > 0)
  {
    if ((a[len] == b[len] && a[len] == '1') ||  (((a[len] == '1' && b[len] == '0') ||
             (a[len] == '0' && b[len] == '1')) && (carry-48)))
                           ret[len] = '0';
    else if ((a[len] == '1' && b[len] == '0') ||
             (a[len] == '0' && b[len] == '1')) 
             ret[len] = '1';
    else if ((a[len] == b[len] && a[len] == '0')&& carry==49)
      ret[len]='1';
    else
      {ret[len]='0';}
    carry= ((a[len] & b[len])|(b[len] & carry) |(carry & a[len]));
    len--;
  }
    if (carry=='1' || a[0]=='1' ||b[0]=='1')
      ret[0]='1';
    else  ret[0]='0';
    
  return (ret);
}

int toInt(char *bits)
{
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
