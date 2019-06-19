/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 23:06:53 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/12 23:06:56 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "header.h"

#define R 256

void countSort(unsigned char *utensils, int n)
{
  int i = -1;
  int count[R];
  char out[n];

  memset(count, 0, sizeof(count));
  while (utensils[++i])
    count[utensils[i]] += 1;
  i = 0;
  while (++i < R)
    count[i] += count[i - 1];
  i = -1;
  while (utensils[++i])
  {
    out[count[utensils[i]] - 1] = utensils[i];
    count[utensils[i]] -= 1;
  }
  i = -1;
  while (utensils[++i])
    utensils[i] = out[i];
}
