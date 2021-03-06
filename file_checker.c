/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:54:42 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/07 16:45:23 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		valid_char(char c)
{
	if (c == '.' || c == '#' || c == '\n')
		return (1);
	return (0);
}

static int		check_layout(char *block)
{
	int		i;
	int		connec;

	i = 0;
	connec = 0;
	while (block[i])
	{
		if (block[i] == '#' && block[i + 1] == '#')
			connec++;
		if (block[i] == '#' && block[i + 5] == '#')
			connec++;
		i++;
	}
	return (connec > 2 ? 1 : 0);
}

static void		check_file_errors(char *file, int nl, int i)
{
	if (!(valid_char(file[i])))
		error();
	if (nl == 4 && (file[i] != '\n' || !file[i]))
		error();
}

static char		*is_block_valid(char *block, int i, int nl)
{
	int		diese;
	int		point;

	diese = 0;
	point = 0;
	while (block[i] && valid_char(block[i]))
	{
		if (block[i] == '\n')
			nl++;
		else if (block[i] == '#')
		{
			if ((block[i + 1] == '#' || block[i - 1] == '#' ||
			block[i + 5] == '#' || block[i - 5] == '#') && check_layout(block))
				diese++;
			else
				error();
		}
		else if (block[i] == '.')
			point++;
		i++;
	}
	if (nl == 4 && diese == 4 && point == 12)
		return (block_parser(block));
	error();
	return (NULL);
}

t_list			*is_file_valid(char *file)
{
	int		i;
	int		nl;
	t_list	*list;

	i = 0;
	nl = 0;
	list = NULL;
	while (file[i])
	{
		check_file_errors(file, nl, i);
		if (file[i] == '\n')
			nl++;
		else if (i == 0 || nl == 5)
		{
			list = ft_list_push_back(is_block_valid(
				ft_strsub(file, i, 20), 0, 0), list);
			nl = 0;
		}
		i++;
	}
	if (nl != 4 || !file[0] || (file[i - 1] == '\n' && file[i - 2] == '\n'))
		error();
	return (list);
}
