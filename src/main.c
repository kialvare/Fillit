/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:25:41 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/05 09:25:50 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_pieces(char ***pieces)
{
	int i;
	int j;
	int size;

	size = ft_arrlen((void **)pieces);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 4)
		{
			ft_memdel((void **)&pieces[i][j]);
			j++;
		}
		ft_memdel((void **)&pieces[i]);
		i++;
	}
}

char		*read_file(char *file)
{
	int 	fd;
	int 	ret;
	int 	i;
	char	tmp[545];
	char	buf[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_putendl("error");
	while ((ret = read(fd, buf, 1)))
	{
		tmp[i++] = buf[0];
		if (i > 545)
			ft_putendl("error");
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_putendl("error");
	return (ft_strdup(tmp));
}

int			main(int ac, char **av)
{
	char	*file;
	char	***pieces;
	t_map	*map;

	if (ac == 2)
	{
		file = read_file(av[1]);
		if ((pieces = store_tetri(file)) == 0)
			return (0);
		if (pieces == '\0' || pieces == "\n")
		{
			ft_putendl("error");
			return (0);
		}
		map = start(pieces);
		print_map(map);
		free_map(map);
		ft_memdel((void **)&file);
		free_pieces(pieces);
		return (1);
	}
	else
	{
		ft_putendl("usage: ./fillit target_file");
		return (0);
	}
	return (1);
}
