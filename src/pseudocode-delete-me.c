int place_piece(t_map *map, t_piece *piece)

	
// starts at top left
int test_piece(t_map *map, t_piece *piece)
	int x;
	int y;

	x = 0;
	while looping through map => while x < 5 => while on the first row
	{
		y = 0;
		while y < 5 => while checking the first y-coordinate of this row
		{
			loop through the piece until you find the first hashtag
		when you find the first hashtag, check for a free spot on the map (marked by '.')
			once you see if the first hashtag fits on the map, loop through the map and the piece
			until you find the next hashtag and see if it fits inside the map
		if the entire piece fits in the map
			place_piece(map, piece)
		}
	}

int start(t_map *map, t_piece *pieces, int num_pieces)
	int current_map_size; (the size of the smallest board possible)
	int i; => counter for the number of pieces
	t_piece *current_piece;

	current_map_size = map->size;
	current_piece = piece->next;
	i = 0;
	while i is less than the number of pieces
			if(check_piece_against_map(map, current_piece) does not work)
				go to the next piece that was read and try that out (check_piece_against_map(map, piece->next))
				free_map(map);
				current_map_size++;
				map = make_map(current_map_size);
			otherwise
				place the piece => place_piece(map, piece)
			i++;

// Have a function that loops through the piece until a "#" is found?

t_piece go_through_piece(t_piece *piece)
	int i;
	int j;

	i = 0;
	j = 0;
	while (piece[i][j] != '\0')
		if (piece[i][j] == '.')
			i++;
		else

// Function that will loop through each string in the array where all the strings are stored
// And then convert them. Will also send to the start() function

t_map	*run_piece(t_list *piece)
{
	char *all_pieces;
	char **the_piece;
	int i;

	all_pieces = piece->content;
	i = 0;
	while (all_pieces[i] != '\0')
	{
		the_piece = convert(all_pieces[i]);
		start(the_piece, ft_strlen(all_pieces));
		i++;
	}
	return (map);
}