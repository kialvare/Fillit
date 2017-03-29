/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:25:41 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/28 10:08:47 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	free_pieces(char ***pieces, char *file)
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
	ft_memdel((void **)&file);
}

char	*read_file(char *file)
{
	int		fd;
	int		ret;
	int		i;
	char	tmp[545];
	char	buf[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		exit(0);
	}
	while ((ret = read(fd, buf, 1)))
	{
		tmp[i++] = buf[0];
		if (i > 545)
			break ;
	}
	tmp[i] = '\0';
	close(fd);
	return (ft_strdup(tmp));
}

int		main(int ac, char **av)
{
	char	*file;
	char	***pieces;
	t_map	*map;

	if (ac == 2)
	{
		file = read_file(av[1]);
		if (file[0] == '\0')
		{
			ft_putendl("error");
			return (1);
		}
		if ((pieces = store_tetri(file)) == 0)
			return (0);
		map = start(pieces);
		print_map(map);
		free_map(map);
		free_pieces(pieces, file);
		return (1);
	}
	else
	{
		ft_putendl("usage: ./fillit target_file");
		return (0);
	}
}
