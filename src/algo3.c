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

// t_map 	*start(char **piece, int num)
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

// t_map	*get_a_piece(t_list *piece)
// {
// 	t_map *thing;
// 	int size;
// 	char *all_pieces;
// 	char **the_piece;
// 	int i;

// 	size = smallest_square(ft_lstcount(piece));
// 	all_pieces = piece->content;
// 	printf("%s\n", all_pieces);
// 	i = 0;
// 	while (all_pieces[i] != '\0')
// 	{
// 		the_piece = convert(&all_pieces[i]);
// 		thing = start(the_piece, ft_strlen(all_pieces));
// 		i++;
// 	}
// 	return (thing);
// }

t_map	*get_a_piece(t_list *piece)
{
	t_map *map;
	int size;
	// int size1;
	char *all_pieces;
	// char **the_piece;
	// int i;
	int count;

	size = smallest_square(ft_lstcount(piece) * 4);
	// size1 = ft_lstcount(piece);
	count = piece->content_size;
	// ft_putnbr(count);
	ft_putnbr(size);
	ft_putchar('\n');
	map = make_map(size);
	// ft_putnbr(size);
	all_pieces = piece->content;
	// printf("%s\n", all_pieces);
	// i = 0;
	// while (all_pieces[i] != '\0')
	// {
	// 	the_piece = convert(&all_pieces[i]);
	// 	thing = start(the_piece, ft_strlen(all_pieces));
	// 	i++;
	// }
	return (0);
}