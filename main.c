/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:22:08 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/08 15:02:49 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			error(void)
{
	ft_putstr("error\n");
	exit(1);
}

static char		*ft_read(char *file)
{
	int		fd;
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	if ((fd = open(file, O_RDONLY)) == -1)
		error();
	while ((ret = read(fd, buffer, BUFF_SIZE)))
		buffer[ret] = '\0';
	if (close(fd) == -1)
		error();
	return (ft_strdup(buffer));
}

static t_list	*check_parse(char *file)
{
	t_list	*list;

	list = is_file_valid(ft_read(file));
	return (list);
}

int				main(int argc, char **argv)
{
	t_list	*tetriminos;

	tetriminos = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit tetriminos_file\n");
		return (1);
	}
	tetriminos = check_parse(argv[1]);
	controller(tetriminos);
	return (0);
}
