/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:43:12 by iwagner           #+#    #+#             */
/*   Updated: 2017/10/18 21:44:01 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void	sinkIsland(int **map, int row, int col){
	if (!map)
		return ;
	if (row < 0 || map[row] == NULL || col < 0 ||
		map[row][col] != 1)
		return ;
	map[row][col] = 0;
	sinkIsland(map, row, col - 1);
	sinkIsland(map, row, col + 1);
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row - 1, col);
}
