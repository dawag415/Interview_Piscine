/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 23:05:29 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/12 23:05:32 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void insertionSort(struct s_player **players)
{
  int i = -1;
  int j = 0;
  struct s_player *p;

  while (players[++i])
  {
    p = players[i];
    j = i - 1;
    while (j >= 0 && players[j]->score < p->score)
    {
      players[j + 1] = players[j];
      j = j - 1;
    }
    players[j + 1] = p;
  }
}