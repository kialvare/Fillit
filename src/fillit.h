/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 10:30:56 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/05 09:25:34 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h> // ************************* remove it at the end!!!!!

/* ********************** MAP ************************** */

typedef struct 			s_map
{
	int					size;
	char 				**arr;
}						t_map;

/* ********************* STORING ********************** */

typedef struct 			s_piece
{
	char 				**str;
}						t_piece;

/* ********************* convert.c ******************** */
char					**allocate_array(char **str);
char 					**convert(char *str);

/* ********************* count_tetri.c ******************** */
int						count_tetri(char *s);
int						check_count(char *s);
int 					ft_valid(char *s);

/* ********************* algo3.c ******************** */
int						test_map(t_map *map, char **piece, int i, int j);
int						test_piece(t_map *map, char **piece);
t_map 					*start(char **piece, int num);
t_map 					*get_a_piece(t_piece **piece);
int						place_piece(t_piece *piece, t_map *map, int x, int y);

/* ************************* map.c ************************ */

int						free_map(t_map *map);
int						smallest_square(int n);
void					print_map(t_map *map);
t_map					*make_map(int n);

/* ********************** read_map.c ********************** */

char 					*read_file(char *file);
t_list					*store_tetri(char *raw_map);
t_list 					*put_error(void);
// t_store				*free_list(t_store *list);
// void					free_tetri(t_piece *piece);

char			**ft_strsplitstr(char const *s, char *delim);

#endif
