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

char *read_file(char *file)
{
	int fd;
	int ret;
	int i;
	char tmp[545];
	char buf[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_putendl("error");
	while((ret = read(fd, buf, 1)))
	{
		tmp[i++] = buf[0];
		if (i > 545)
			ft_putendl("error");
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_putendl("error");
	return(ft_strdup(tmp));
}

int		main(int ac, char **av)
{
	char		*file;
	char		***pieces;
	int size;
	t_map		*map;

	if (ac == 2)
	{
		file = read_file(av[1]);
		if ((pieces = store_tetri(file)) == 0)
			return (0);
		size = ft_arrlen(ft_strsplitstr(file, "\n\n"));
		map = start(pieces, size);
		print_map(map);
		//free_map(map);
		return (1);
	}
	else
	{
		ft_putendl("usage: ./fillit target_file");
		return (0);
	}
	return (1);
}
