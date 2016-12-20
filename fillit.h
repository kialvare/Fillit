/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 10:30:56 by kialvare          #+#    #+#             */
/*   Updated: 2016/11/27 18:56:16 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h> // ************************* remove it at the end!!!!!



/* ********************* VALIDATION ********************** */

typedef struct 			s_init 
{
	int					ipiece;
	int					hash;
	int					dot;
	int					endline;
}						t_init;

typedef struct 			s_init2
{
	int 				count;
	int 				line_5;
	int 				lines;
	int 				i;
}						t_init2;


/* ********************** MAP ************************** */

typedef struct			s_shape
{
	char				**content;
	size_t				content_size;
	struct s_shape		*next;
}						t_shape;

typedef struct 			s_map
{
	int					size;
	char 				**arr;
}						t_map;

/* ********************* STORING ********************** */

// typedef struct 		s_piece
// {
// 	char				*str;
// }					t_piece;

typedef struct 			s_piece
{
	char 				**str;
	char				c;
}						t_piece;

/* ********************* convert.c ******************** */
char					**allocate_array(char **str);
char 					**convert(char *str);

/* ********************* count_tetri.c ******************** */
int						count_tetri(char *s);
int						tetri_valid(char *s, int i);

/* ********************* algo3.c ******************** */
int						test_map(t_map *map, char **piece, int i, int j);
int						test_piece(t_map *map, char **piece);
t_map 					*start(char **piece, int num);
t_map 					*get_a_piece(t_list *piece);
int						place_piece(t_piece *piece, t_map *map, int x, int y);


/* ********************* check_shape.c ******************** */

int						check_connection(char **str);
t_piece 				*get_piece(char *str, char value);

/* ********************* check_tetri.c ******************** */

int						check_all_char(char *str);
int						check_charperline(char *str);

/* ************************* map.c ************************ */

int						free_map(t_map *map);
int						smallest_square(int n);
void					print_map(t_map *map);
t_map					*make_map(int n);

/* ********************** read_map.c ********************** */

char					*read_file(int fd);
t_list					*store_tetri(char *raw_map);
t_list *put_error(void);
// t_store				*free_list(t_store *list);
// void					free_tetri(t_piece *piece);



/* ************* Haven't been categorized yet ************** */

int						check_place(char *str);
int						ft_check(char **tab);
t_list					*check_valid(int fd);
int 					check_new_lines_at_end(char *str);
void					init(t_init *all_char, t_init2 *charperline);
// void    				init_struct(t_check *tmp);
// void    				check_character(char c, t_check *tmp);
void					increment_counter(char c, int *dot, int *hash, int *endline);

#endif
