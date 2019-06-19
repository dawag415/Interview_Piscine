/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:18:38 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/18 21:20:19 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

static double bestSlices(double cur, int size, double *prices, double max)
{
	if (size == 0 && cur > max)
		max = cur;
	else if (size > 0)
		for (int i = size; i > 0; i--)
			max = bestSlices(cur + prices[i], size - i, prices, max);
	return(max);	
}

double bestPrice(int pizzaSize, double *prices){
 	double max = 0;
 	
	max = prices[pizzaSize];
	for (int i = pizzaSize; i > 0; i--)
		max = bestSlices(0, pizzaSize, prices, max);
	return (max);
}
