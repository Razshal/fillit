/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placenext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:46:08 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/08 15:31:40 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	chk_place(char *block, char **grid, int line, int row)
{
	if (grid[line][row] && !ft_isalpha(grid[line][row])
			&& placeblock(block, grid, line, row))
		return (1);
	return (0);
}

static int	chk_decal(int decal, char **grid, char letter)
{
	if (alphablock(grid, letter) && decal < 1)
		return (1);
	else
	{
		eraseblock(grid, letter);
		return (0);
	}
}

int			placenext(char *block, char **grid, char letter, int decal)
{
	int line;
	int row;
	int limit;

	limit = chk_limit(grid);
	line = -1;
	while (++line <= limit)
	{
		row = -1;
		while (grid[line][++row])
		{
			if ((chk_place(block, grid, line, row)
					&& chk_decal(decal--, grid, letter)))
				return (1);
		}
	}
	return (0);
}
