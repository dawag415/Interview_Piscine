/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 23:07:20 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/12 23:07:23 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

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
