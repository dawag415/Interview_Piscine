/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 23:02:18 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/18 23:02:21 by iwagner          ###   ########.fr       */
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

void	permutate(char *str, int start, int len, struct s_dict *dict){
	if (start == len){
		if (dictSearch(dict, str) != 1){
			puts(str);
			dictInsert(dict, str, 1);
		}
	}
	else
		for (int i = start; i <= len; i++){
			swap((str + start), (str + i));
			permutate(str, start + 1, len, dict);
			swap((str + start), (str + i));
		}
}

void	printUniquePermutations(char *str){
	struct s_dict *dict;
	int exp = 1;
	int len;
	
	if (!str)
		return ;
	len = strlen(str);
	for (int i = 1; i <= len; i++)
		exp *= i;
	dict = dictInit(exp);
	permutate(str, 0, len - 1, dict);
}
