/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:56:05 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/09 13:56:07 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include <string.h>
 
int searchPrice(struct s_art **arts, int n, char *name)
{
   int first, last, middle, cmp;

   first = 0;
   last = n - 1;
   middle = (first+last)/2;
 

   while (first <= last)
   {
      cmp=strcmp(arts[middle]->name, name);
      if (cmp < 0)
         first = middle + 1;    
      else if (cmp == 0) {
        return (arts[middle]->price);
    }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      return (-1);
 
   return 0;  
}
