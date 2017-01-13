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

// int		place_piece(t_piece *piece, t_map *map, int x, int y)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < map->size)
// 	{
// 		j = 0;
// 		while (j < map->size)
// 		{
// 			if (piece->str[j][i] == '#' && map->arr[y + j][x + i] != '.')
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

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
// 			if (piece[i][j] == '#' && map_grid[x][y] == '.')
// 				return (0);
// 			x++;
// 		}
// 		y++;
// 	}
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
// 			if (piece[i][j] == '#')
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

// t_map 	*start(t_piece *piece, int num)
// {
// 	int current_map_size;
// 	int i;
// 	t_map *map;

// 	current_map_size = num;
// 	map = make_map(current_map_size);
// 	i = 0;
// 	while (piece[i] != '\0')
// 	{
// 		// if (!test_piece(map, piece))
// 		// {
// 		// 	free_map(map);
// 		// 	current_map_size++;
// 		// 	map = make_map(current_map_size);
// 		// }
// 	}
// 	return (map);
// }

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
