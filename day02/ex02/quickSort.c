#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void swap(struct s_player **a, struct s_player **b)
{
  struct s_player *tmp = *a;
  *a = *b;
  *b = tmp;
}

int   rot(struct s_player **players, int a, int z)
{
  struct s_player *p = players[z];
  int i = (a - 1);
  int j = a;

  while (j <= z - 1)
  {
    if (players[j]->score >= p->score)
      swap(&players[++i], &players[j]);
    j++;
  }
  swap(&players[i + 1], &players[z]);
  return (i + 1);
}

struct s_player **recurse(struct s_player **players, int a, int z)
{
  if (a < z)
  {
    int r = rot(players, a, z);
    recurse(players, a, r - 1);
    recurse(players, r + 1, z);
  }
  return (players);
}

void quickSort(struct s_player **players)
{
  int   i = -1;

  while (players[++i]);
  players = recurse(players, 0, i - 1);
}
