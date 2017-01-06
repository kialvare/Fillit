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

t_list *read_file(int fd, char *raw_map)
{
	char *buf;
	int n;
	t_list *list;

	buf = ft_strnew(21);
	list = NULL;
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if ((tetri_valid(raw_map, count_tetri(raw_map))))
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd()
	}
}

char **split_at_newline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (str[i++] == '\n')
			{
				
			}
		}
	}
}

char	*read_file(int fd)
{
	char	*buf;
	int		ret;

	buf = (char *)ft_memalloc(sizeof(buf) * 546);
	while ((ret = read(fd, buf, 546)))
	{
		buf[ret] = '\0';
	}
    return (buf);
}

t_list	*put_error(void)
{
	ft_putendl("error");
	return (0);
}

// t_list	*store_tetri_two(t_list *first_link, char **str, int line)
// {
// 	ft_strcat(first_link->content, str[line++]);
// 	ft_strcat(first_link->content, str[line++]);
// 	ft_strcat(first_link->content, str[line++]);
// 	return (0);
// }

// t_list	*store_tetri(char *raw_map)
// {
// 	char	**str;
// 	int		line;
// 	t_list	*first_link;
// 	t_list	*next_link;
// 	t_list *list;

// 	line = 0;
// 	if (tetri_valid(raw_map, count_tetri(raw_map)))
// 	{
// 		str = split_at_newline(raw_map);

// 	}
// 	else if (!(tetri_valid(raw_map, count_tetri(raw_map))))
// 		return (put_error());
// 	return(0);
// }

t_list	*store_tetri_two(t_list *first_link, char **str, int line)
{
	ft_strcat(first_link->content, str[line++]);
	ft_strcat(first_link->content, str[line++]);
	ft_strcat(first_link->content, str[line++]);
	return (0);
}

t_list	*store_tetri(char *raw_map)
{
	char	**str;
	int		line;
	t_list	*first_link;
	t_list	*next_link;
	t_list *list;

	line = 0;
	if (tetri_valid(raw_map, count_tetri(raw_map)))
	{
		str = ft_strsplit(raw_map, '\n');
		first_link = ft_lstnew(str[line++], 17);
		store_tetri_two(first_link, str, line);
		line += 3;
		list = first_link;
		while (str[line])
		{
			next_link = ft_lstnew(str[line++], 17);
			store_tetri_two(next_link, str, line);
			line += 3;
			ft_lstadd(&first_link, next_link);
			while (first_link)
			{
				printf("%s\n", first_link->content);
				first_link = first_link->next;
			}
		}
		return (list);
	}
	else if (!(tetri_valid(raw_map, count_tetri(raw_map))))
		return (put_error());
	return(0);
}

// t_list	*store_tetri(char *raw_map)
// {
// 	// if (!(check_charperline(raw_map) && check_all_char(raw_map)\
// 	// 		&& check_new_lines_at_end(raw_map)))
// 	// if (!(check_charperline(raw_map)))
// 	// if (!(check_all_char(raw_map)))
// 	// if (!(check_new_lines_at_end(raw_map)))
// 	if (!(tetri_valid(raw_map, count_tetri(raw_map))))
// 	{
// 		printf("it doesn't work\n");
// 	}
// 	else
// 		printf("it works but why\n");
// 	return (0);
// }
