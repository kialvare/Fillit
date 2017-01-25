/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 10:30:56 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/24 18:39:19 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
** MAP
*/

typedef struct		s_map
{
	int				size;
	char			**arr;
}					t_map;

/*
** main.c
*/
char				*read_file(char *file);
void				free_pieces(char ***pieces, char *file);

/*
** validation.c
*/
int					count_tetri(char *s);
int					check_count(char *s);
int					ft_valid(char *s);

/*
** algo3.c
*/
int					solve(char ***pieces, int k, t_map *map, int size);
t_map				*start(char ***pieces);
void				place_piece(char **piece, t_map *map, int x, int y);
t_map				*reset(char **piece, t_map *map, int x, int y);
int					check_piece(char **piece, t_map *map, int x, int y);

/*
** map.c
*/

int					free_map(t_map *map);
void				print_map(t_map *map);
t_map				*make_map(int n);

/*
** store.c
*/

char				***store_tetri(char *raw_map);
void				hash_to_alph(char **str, int len);

/*
** Libft funcs
*/

char				**ft_strsplitstr(char const *s, char *delim);
int					ft_arrlen(void **arr);

#endif
