/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */           
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:23:29 by phoreau           #+#    #+#             */
/*   Updated: 2016/11/27 20:02:31 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	char		*str;
	t_list		*pieces;
	// t_map		*map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putendl("usage: ./fillit target_file");
			return (-1);
		}
		str = read_file(fd);
		pieces = store_tetri(str);
		// map = get_a_piece(pieces);
		// print_map(map);
		// free_map(map);
		// free_list(pieces);
		return (0);
	}
	else
	{
		ft_putendl("usage: ./fillit target_file");
		return (-1);
	}
	return (0);
}
