/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:25:57 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/05 09:26:09 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_memdel or ft_lstdel/ft_lstdelone?
*/

int		free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->arr));
		i++;
	}
	ft_memdel((void **)&(map->arr));
	ft_memdel((void **)&map);
	return (0);
}

/*
** After checking if we can place the piece on the map
** This sets the piece on the map
*/

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putendl(map->arr[i]);
		i++;
	}
}

/* 
** Allocates memory for smallest square
** Print out smallest square map
*/

t_map			*make_map(int n)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = n;
	map->arr = (char **)ft_memalloc(sizeof(char *) * n);
	i = 0;
	while (i < n)
	{
		map->arr[i] = ft_strnew(n);
		j = 0;
		while (j < n)
		{
			map->arr[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
