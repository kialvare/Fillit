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

t_list	*put_error(void)
{
	ft_putendl("error");
	return (0);
}

t_list	*store_tetri(char *raw_map)
{
	char	**str;
	//t_piece	string;
	int i;
	//int j;
	//int k;
	// int len;
	// t_list	*next_link;
	// t_list *list;

	// line = 0;
	// len = ft_arrlen(ft_strsplitstr(raw_map, "\n\n"));
	i = 0;
	if (ft_valid(raw_map) == 1)
	{
		str = ft_strsplitstr(raw_map, "\n\n");
		while (str[i] != '\0')
		{
			// printf("%d: %s\n", i, str[i]);
			i++;
		}
		// str = ft_strsplitstr(raw_map, "\n");
		// while (i < len)
		// {
		// 	j = 0;
		// 	k = 0;
		// 	while (j < 4)
		// 	{
		// 		string.str[k] = &str[i][j];
		// 		// printf("%d: %s\n", k, string.str[k]);
		// 		j++;
		// 		k++;
		// 	}
		// 	i++;
		// }
	}
	else if (ft_valid(raw_map) == 0)
		return (put_error());
	return(0);
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
// 		str = ft_strsplit(raw_map, '\n');
// 		first_link = ft_lstnew(str[line++], 17);
// 		store_tetri_two(first_link, str, line);
// 		line += 3;
// 		list = first_link;
// 		while (str[line])
// 		{
// 			next_link = ft_lstnew(str[line++], 17);
// 			store_tetri_two(next_link, str, line);
// 			line += 3;
// 			ft_lstadd(&first_link, next_link);
// 			while (first_link)
// 			{
// 				printf("%s\n", first_link->content);
// 				first_link = first_link->next;
// 			}
// 		}
// 		return (list);
// 	}
// 	else if (!(tetri_valid(raw_map, count_tetri(raw_map))))
// 		return (put_error());
// 	return(0);
// }
