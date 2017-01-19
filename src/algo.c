/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:25:08 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/05 09:25:12 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*reset(char **piece, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[j][i] != '.')
				map->arr[y + j][x + i] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		check_piece(char **piece, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (ft_isupper(piece[j][i]) &&
				(((y + j) >= map->size  ||
					(y + j) < 0 ||
					(x + i) >= map->size ||
					(x + i) < 0) ||
					map->arr[y + j][x + i] != '.'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	place_piece(char **piece, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[j][i] != '.')
				map->arr[y + j][x + i] = piece[j][i];
			j++;
		}
		i++;
	}
}

int		solve(char ***pieces, int k, t_map *map, int size)
{
	int i;
	int j;

	j = -3;
	if (pieces[k] == NULL)
		return (1);
	while (j < size + 3)
	{
		i = -3;
		while (i < size + 3)
		{
			if (check_piece(pieces[k], map, i, j))
			{
				place_piece(pieces[k], map, i, j);
				if (solve(pieces, k + 1, map, size))
					return (1);
				else
					reset(pieces[k], map, i, j);
			}
			i++;
		}
		j++;
	}
	return (0);
}

t_map		*start(char ***pieces)
{
	int 	size;
	t_map	*map;

	size = 2;
	map = make_map(size);
	while (!(solve(pieces, 0, map, size)))
	{
		size++;
		free_map(map);
		map = make_map(size);
	}
	return (map);
}
