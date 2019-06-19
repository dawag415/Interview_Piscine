/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 23:06:24 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/12 23:06:28 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_player **merge(struct s_player **players, int start, int mid, int end)
{
  int i, j, k;
  int n1 = mid - start + 1;
  int n2 = end - mid;

  struct s_player *left[n1];
  struct s_player *right[n2];

  for (i = 0; i < n1; i++)
    left[i] = players[start + i];
  for (j = 0; j < n2; j++)
    right[j] = players[mid + 1 + j];

  i = 0;
  j = 0;
  k = start;
  while (i < n1 && j < n2)
  {
    if (left[i]->score >= right[j]->score)
    {
      players[k] = left[i];
      i++;
    }
    else
    {
      players[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    players[k] = left[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    players[k] = right[j];
    j++;
    k++;
  }
  return (players);
}

struct s_player **recurse(struct s_player **players, int start, int end)
{
  if (end > start)
  {
    int mid = (start + end) / 2;
    recurse(players, start, mid);
    recurse(players, mid + 1, end);
    players = merge(players, start, mid, end);
  }
  return (players);
}

struct s_player **mergeSort(struct s_player **players)
{
  int i = -1;
  while (players[++i]);
  players = recurse(players, 0, i - 1);
  return (players);
}
