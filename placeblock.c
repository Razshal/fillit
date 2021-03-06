/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeblock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:45:22 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/06 14:45:25 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static int	revlast(char *block, char **grid, int line, int row)
{
	if (block[-1] == 'l')
		row++;
	if (block[-1] == 'r')
		row--;
	if (block[-1] == 'u')
		line++;
	if (block[-1] == 'd')
		line--;
	if (placeblock(&block[1], grid, line, row))
		return (1);
	return (0);
}

int			placeblock(char *block, char **grid, int line, int row)
{
	int placeres;

	placeres = 0;
	if (line < 0 || row < 0 || line > chk_limit(grid) || row > chk_limit(grid))
		return (0);
	if (!block[0])
		placeres = 1;
	if (!grid[line][row] || ft_isalpha(grid[line][row]))
		return (0);
	if (grid[line][row])
	{
		if (block[0] == 'l')
			placeres = placeblock(&block[1], grid, line, row - 1);
		if (block[0] == 'r')
			placeres = placeblock(&block[1], grid, line, row + 1);
		if (block[0] == 'u')
			placeres = placeblock(&block[1], grid, line - 1, row);
		if (block[0] == 'd')
			placeres = placeblock(&block[1], grid, line + 1, row);
		if (block[0] == 'b')
			placeres = revlast(&block[0], grid, line, row);
	}
	if (placeres == 1 && grid[line][row] && grid[line])
		grid[line][row] = '#';
	return (placeres);
}
