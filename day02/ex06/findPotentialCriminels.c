#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

#define R 10

int LENGTH = 0;

int getDescription(struct s_info *info)
{
  int desc = 0;

  desc += info->gender    * pow(10, 6);
  desc += info->height    * pow(10, 5);
  desc += info->hairColor * pow(10, 4);
  desc += info->eyeColor  * pow(10, 3);
  desc += info->glasses   * pow(10, 2);
  desc += info->tattoo    * pow(10, 1);
  desc += info->piercing  * pow(10, 0);
  return (desc);
}

void countSort(struct s_criminal **criminals, int n, int pos)
{
  int i = -1;
  int count[R] = {0};
  struct s_criminal *out[n];

  while (++i < n)
    count[(criminals[i]->description / pos) % R] += 1;
  i = 0;
  while (++i < R)
    count[i] += count[i - 1];
  i = n;
  while (--i >= 0)
  {
    out[count[(criminals[i]->description / pos) % R] - 1] = criminals[i];
    count[(criminals[i]->description / pos) % R] -= 1;
  }
  i = -1;
  while (++i < n)
    criminals[i] = out[i];
}

void sortCriminals(struct s_criminal **criminals)
{
  int len = -1;
  int pos = 1;
  int max = 0;

  while (criminals[++len])
    if (criminals[len]->description > max)
      max = criminals[len]->description;
  LENGTH = len;
  while (max)
  {
    countSort(criminals, len, pos);
    pos *= 10;
    max /= 10;
  }
}

int searchShifted(int *rocks, int length, int value)
{
  int left = 0, right = length - 1;

  while (left <= right)
  {
    int mid = left + ((right - left) / 2);
    if (rocks[mid] == value) return (mid);
    if (rocks[left] <= rocks[right])
    {
      if (rocks[left] <= value && value < rocks[mid])
        right = mid - 1;
      else
        left = mid + 1;
    }
    else
    {
      if (rocks[mid] < value && value <= rocks[right])
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  return (left);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
  int desc = getDescription(info);
  struct s_criminal **pot;
  int end = LENGTH;
  int start = 0;
  int pos = 0;
  int i = -1;

  //while (criminals[++end]);
  pot = (struct s_criminal**)malloc(end * sizeof(struct s_criminal));
  pos = (start + end) / 2;
  while (start < end)
  {
    if (criminals[pos]->description < desc)
      start = pos + 1;
    else if (criminals[pos]->description > desc)
      end = pos - 1;
    else if (criminals[pos]->description == desc)
    {
      pot[++i] = criminals[pos];
      int l = pos - 1;
      int r = pos + 1;
      while (criminals[l]->description == desc)
        pot[++i] = criminals[l--];
      while (criminals[r]->description == desc)
        pot[++i] = criminals[r++];
      return (pot);
    }
    pos = (start + end) / 2;
  }
  return (pot);
}
