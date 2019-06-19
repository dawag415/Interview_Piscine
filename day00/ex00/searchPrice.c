/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:24:13 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/09 10:24:16 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int  searchPrice(struct s_art **arts, char *name)
{
	if (!name || !arts || !*arts)
		return (-1);
	while (*arts)
	{
		if (strcmp((*arts)->name, name) == 0)
			return ((*arts)->price);
		arts++;
	}
	return (-1);
}
