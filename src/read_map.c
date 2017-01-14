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

t_piece	*put_error(void)
{
	ft_putendl("error");
	return (0);
}

t_piece	*store_tetri(char *raw_map)
{
	char	**str;
	t_piece	*string;
	int i;
	int len;

	str = ft_strsplitstr(raw_map, "\n\n");
	//printf("%s\n", str[1]);
	string = ft_memalloc(sizeof(t_piece));
	len = ft_arrlen(str);
	if (ft_valid(raw_map) == 1)
	{
		i = 0;
		while (i < len)
		{
			if (ft_strlen(str[i]) == 19)
			{
				str[i] = *ft_strsplitstr(str[i], "\n");
				string->pieces = &str[i];
				printf("%d: %s\n", i, string->pieces[i]);
				i++;
			}
			else
			{
				return (0);
			}
		}
	}
	else if (ft_valid(raw_map) == 0)
		return (put_error());
	return(0);
}
