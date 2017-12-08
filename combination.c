/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:34:15 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/08 15:35:21 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	combination(t_block_sort *maintab, int start, char **grid, int decal)
{
	if (!is_blocks_left(maintab))
		return (1);
	while (already_set(maintab[start]) && start < block_tab_size(maintab))
		start++;
	if (start > block_tab_size(maintab) || !(maintab[start]).block)
		return (0);
	if (already_set(maintab[start]))
		return (0);
	if (!placenext((maintab[start]).block, grid, start + 'A', decal))
		return (combination(maintab, start + 1, grid, decal));
	else
		maintab[start] = mark_as_set(maintab[start]);
	if (combination(maintab, 0, grid, 0))
		return (1);
	else
	{
		maintab[start] = mark_as_notset(maintab[start]);
		eraseblock(grid, start + 'A');
		return (combination(maintab, start, grid, ++decal));
	}
	return (0);
}
