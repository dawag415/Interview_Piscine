/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 22:37:32 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/18 22:37:36 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

void swap(char *a, char *b){
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	permutate(char *str, int start, int len){
	if (start == len)
		printf("%s\n", str);
	else
		for (int i = start; i <= len; i++){
			swap((str + start), (str + i));
			permutate(str, start + 1, len);
			swap((str + start), (str + i));}
}

void	printPermutations(char *str){
	if (!str)
		return ;
	permutate(str, 0, strlen(str) - 1);
}
