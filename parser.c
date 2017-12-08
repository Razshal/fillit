/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:55:06 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/08 13:41:54 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_charchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		get_i(int i, int dir, char *parsed, int hash)
{
	if (dir == 5)
		parsed[hash] = 'd';
	else if (dir == -1)
		parsed[hash] = 'l';
	else if (dir == 1)
		parsed[hash] = 'r';
	else if (dir == -5)
		parsed[hash] = 'u';
	else if (dir == 0)
	{
		parsed[hash] = 'b';
		return (0);
	}
	return (i + dir);
}

static int		get_topleft(char **tab)
{
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tab[i][j] == '#')
				return ((i + 1) * 5 - (4 - j) - 1);
			i++;
		}
		j++;
	}
	return (0);
}

static int		back_parser(char *block, int *coo, char *parsed, int hash)
{
	if (!ft_charchr(block, '#'))
		return (0);
	parsed[hash] = 'b';
	return (coo[hash - 1]);
}

char			*block_parser(char *b)
{
	int		i;
	int		hash;
	int		coo[4];
	char	*parsed;

	if ((parsed = exce_parsing(b)))
		return (parsed);
	parsed = ft_strnew(4);
	i = get_topleft(ft_strsplit(b, '\n'));
	hash = -1;
	while (++hash < 4 && (b[i] = '.'))
	{
		coo[hash] = i;
		if (b[i + 5] == '#')
			i = get_i(i, 5, parsed, hash);
		else if (b[i - 1] == '#')
			i = get_i(i, -1, parsed, hash);
		else if (b[i + 1] == '#')
			i = get_i(i, 1, parsed, hash);
		else if (b[i - 5] == '#')
			i = get_i(i, -5, parsed, hash);
		else if (!(i = back_parser(b, coo, parsed, hash)))
			return (parsed);
	}
	return (parsed);
}
