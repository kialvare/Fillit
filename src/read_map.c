/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:26:23 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/05 09:26:30 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

// t_shape	*free_list(t_shape *list)
// {
// 	t_piece *piece;
// 	t_list *next;

// 	while (list)
// 	{
// 		piece = (t_piece *)list->content;
// 		next = list->next;
// 		free_tetri(piece);
// 		ft_memdel((void **)&list);
// 		list = next;
// 	}
// 	return (NULL);
// }

// void	free_tetri(t_piece *piece)
// {
// 	int y;
// t_shape	*free_list(t_shape *list)
// {
// 	t_piece *piece;
// 	t_list *next;

// 	while (list)
// 	{
// 		piece = (t_piece *)list->content;
// 		next = list->next;
// 		free_tetri(piece);
// 		ft_memdel((void **)&list);
// 		list = next;
// 	}
// 	return (NULL);
// }

// void	free_tetri(t_piece *piece)
// {
// 	int y;
// 	y = 0;
// 	while (y < piece->h)
// 	{
// 		ft_memdel((void **)(&(piece->str[y])));
// 		y++;
// 	}
// 	ft_memdel((void **)(&(piece->str)));
// 	ft_memdel((void **)&piece);
// }

char *read_file(char *file)
{
	int fd;
	int ret;
	int i;
	char tmp[545];
	char buf[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		put_error();
	while((ret = read(fd, buf, 1)))
	{
		tmp[i++] = buf[0];
		if (i > 545)
			put_error();
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		put_error();
	return(ft_strdup(tmp));
}

void 	hash_to_alph(char **str, int len)
{
	int i;
	int j;
	char c;

	i = 0;
	c = 'A';
	while (i < len)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
			{
				str[i][j] = c;
			}
			j++;
		}
		c++;
		i++;
	}
}

void	put_error(void)
{
	ft_putendl("error");
}

char	***store_tetri(char *raw_map)
{
	char	**str;
	char ***pieces;
	int i;
	int len;

	if (ft_valid(raw_map) == 1)
	{
		i = 0;
		str = ft_strsplitstr(raw_map, "\n\n");
		len = ft_arrlen((void **)str);
		hash_to_alph(str, len);
		pieces = ft_memalloc(sizeof(char **) * (len + 1));
		while (i < len)
		{
			pieces[i] = ft_strsplitstr(str[i], "\n");
			// printf("%s\n", pieces[i][0]);
			// printf("%s\n", pieces[i][1]);
			// printf("%s\n", pieces[i][2]);
			// printf("%s\n", pieces[i][3]);
			i++;
		}
		return(pieces);
	}
	else
	{
		put_error();
		return (0);
	}
}
