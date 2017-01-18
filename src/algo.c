/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:25:08 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/05 09:25:12 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map *reset(char **piece, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] != '.')
				map->arr[x + i][y + j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int check_piece(char **piece, t_map *map, int x, int y)
{
	int i;
	int j;
	int h;
	int w;

	h = find_height(piece);
	w = find_width(piece);
	i = 0;
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			if (ft_isupper(piece[j][i]) && map->arr[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_map	*place_piece(char **piece, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] != '.')
				map->arr[x + i][y + j] = piece[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

int 	solve(char ***pieces, int k, t_map *map, int size)
{
	int i;
	int j;

	j = 0;
	if (pieces[k] == NULL)
		return (1);
	while (j < size - find_height(pieces[k]) + 1)
	{
		i = 0;
		while (i < size - find_width(pieces[k]) + 1)
		{
			if (check_piece(pieces[k], map, i, j))
			{
				if (solve(pieces, k + 1, map, size))
				{
					place_piece(pieces[k], map, i, j);
					return (1);
				}
				else
					reset(pieces[k], map, i, j);
			}
			i++;
		}
		j++;
	}
	// place_piece(pieces[k], map, i, j);
	return (0);
}

t_map 	*start(char ***pieces, int count)
{
	int k;
	int size;
	t_map *map;

	size = smallest_square(count); // count is the number of pieces
	map = make_map(size);
	k = 0;
	while (!(solve(pieces, ++k, map, size)))
	{
		size++;
		free_map(map);
		map = make_map(size);
		k = -1;
	}
	return (map);
}

// int	test_map(t_map *map, char **piece, int i, int j)
// {
// 	int x;
// 	int y;
// 	char **map_grid;

// 	map_grid = map->arr;
// 	y = 0;
// 	while (y < map->size)
// 	{
// 		x = 0;
// 		while (x < map->size)
// 		{
// 			if (piece[i][j] != '.' && map_grid[x][y] == '.')
// 				return (0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	place_piece(piece[i], map, x, y);
// 	return (0);
// }

// int test_piece(t_map *map, char **piece)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < 5)
// 	{
// 		j = 0;
// 		while (j < 5)
// 		{
// 			if (piece[i][j] != '.')
// 			{
// 				if(!test_map(map, piece, i, j))
// 					return (0);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// t_map 	*start(char ***pieces)
// {
// 	int current_map_size;
// 	int i;
// 	t_map *map;

// 	current_map_size = 10;
// 	map = make_map(current_map_size);
// 	i = 0;
// 	// while (pieces[i] != '\0')
// 	// {
// 	// 	test_piece(map, pieces[i]);
// 	// 	i++;
// 	// }
// 	while (pieces[i] != '\0')
// 	{
// 		place_piece(pieces[0], map, 0, 0);
// 		i++;
// 	}
// 	return (map);
// }
