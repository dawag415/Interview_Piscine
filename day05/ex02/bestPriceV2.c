/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:21:22 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/18 21:22:12 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h> 

double optSlices(int size, double *max, double *prices) {
	double sum;

	if (max[size])
		return (max[size]);
	if (max[size] == 0)
		max[size] = prices[size];
	for (int i = 1; i <= size / 2; i++)
		if ((sum = (optSlices(i, max, prices) +
			optSlices(size - i, max, prices))) > max[size]) 
			max[size] = sum;
	return (max[size]);}

double optimizedBestPrice(int pizzaSize, double *prices) { 
	double *max = calloc(pizzaSize, sizeof(double));

	for (int i = 0; i <= pizzaSize; i++)
		max[i] = 0;
	return (optSlices(pizzaSize, max, prices));}
