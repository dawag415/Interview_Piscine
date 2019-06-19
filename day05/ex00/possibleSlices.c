/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:16:25 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/18 21:17:16 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void split(struct s_array *pie, int max, int cur, int *dec){
	if (cur == 0){
			*dec = 0;
			return ;}	
	if (*dec)
		split(arrayInit(), max, cur-1, dec);
	arrayAppend(pie, cur);
	if (pie->sum < max)
		for (int i = max; i > 0; i--)
			split(arrayClone(pie), max, i, dec);
	if (pie->sum == max)
		arrayPrint(pie);}

void printPossibleSlices(int pizzaSize){
	int dec = 1;

	split(arrayInit(), pizzaSize, pizzaSize, &dec);}
	
