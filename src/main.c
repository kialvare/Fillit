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

int		main(int ac, char **av)
{
	char		*file;
	t_list		*pieces;
	t_map		*map;

	if (ac == 2)
	{
		file = read_file(av[1]);
		pieces = store_tetri(file);
		map = get_a_piece(pieces);
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
