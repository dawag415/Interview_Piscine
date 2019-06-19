/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 23:08:11 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/12 23:08:14 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int  recurse(int *ages, int a, int z)
{
  if (a == z)
    return (a);
  if ((z == a + 1) && ages[a] < ages[z])
    return (a);

  int m = (a + z) / 2;
  int l = recurse(ages, a, m);
  int r = recurse(ages, m + 1, z);
  static int min = 0;

  if (ages[l] < ages[r])
    min = l;
  else if (ages[r] < ages[l])
    min = r;
  return (min);
}

void printYoungest(int *ages, int length)
{
  int start = 0;
  int end = length - 1;
  if (!ages) return ;
  if (length == 1) printf("Youngest : %d\n", ages[0]);
  else printf("Youngest : %d\n", ages[recurse(ages, start, end)]);
}
