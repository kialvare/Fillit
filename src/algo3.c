/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:25:08 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/05 09:25:12 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int place_piece(t_map *map, t_piece *piece, int x, int y)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i != x)
// }

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

int	test_map(t_map *map, char **piece, int i, int j)
{
	int x;
	int y;
	char **map_grid;

	map_grid = map->arr;
	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (piece[i][j] != '.' && map_grid[x][y] == '.')
				return (0);
			x++;
		}
		y++;
	}
	return (0);
}

int test_piece(t_map *map, char **piece)
{
	int x;
	int y;

	x = 0;
	while (x < 5)
	{
		y = 0;
		while (y < 5)
		{
			if (piece[x][y] != '.')
			{
				if(!test_map(map, piece, i, j))
					return (0);
			}
			y++;
		}
		x++;
	}
	return (0);
}

t_map 	*start(char ***pieces)
{
	int current_map_size;
	int i;
	t_map *map;

	current_map_size = 10;
	map = make_map(current_map_size);
	i = 0;
	while (pieces[i] != '\0')
	{
		test_piece(map, piece);
		i++;
	}
	// while (pieces[i] != '\0')
	// {
	// 	place_piece(pieces[i], map, 0, 0);
	// 	i++;
	// }
	print_map(map);
	return (map);
}

// t_map	*get_a_piece(t_piece *piece)
// {
// 	int n;
// 	int size;
// 	// t_map **map;

// 	n = ft_arrlen(piece->str);
// 	n = 2;
// 	size = smallest_square(n);
// 	printf("%d\n", size);

// 	return (0);
// }
