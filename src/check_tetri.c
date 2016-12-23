/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 17:01:29 by phoreau           #+#    #+#             */
/*   Updated: 2016/11/27 19:51:42 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 
** We are going through all the characters to check if they are the right characters.
** Also checking if we have the right number of the right characters.
** We are on a board of 20 characters = 4 x 5 (\n).
*/

void	init(t_init *all_char, t_init2 *charperline)
{
	if(all_char)
	{
		(*all_char).ipiece = 0;
		(*all_char).hash = 0;
		(*all_char).dot = 0;
		(*all_char).endline = 0;
	}
	if(charperline)
	{
		(*charperline).i = 0;
		(*charperline).count = 0;
		(*charperline).line_5 = 4;
		(*charperline).lines = 0;
	}
}

void	increment_counter(char c, int *dot, int *hash, int *endline)
{
	if (c == '.')
		(*dot)++;
	if (c == '#')
		(*hash)++;
	if (c == '\n')
		(*endline)++;
}

int		check_all_char(char *str)
{
	t_init		tmp;
	int 		i;

	i = 0;
	init(&tmp , (NULL));
	if(!str || *str == '\0' || str == NULL)
		return (0);
	while (str[(++i) - 1] != '\0')
	{
		while (((++tmp.ipiece) - 1) < 20)
		{
			increment_counter(str[i - 1], &tmp.dot, &tmp.hash, &tmp.endline);
			if (str[i - 1] != '#' && str[i - 1] != '.' && str[i - 1] != '\n')
				return (0);
			i++;
		}
		if ((tmp.dot) != 12 || (tmp.hash) != 4 || (tmp.endline) != 4)
			return (0);
		(tmp.ipiece)++;
	}
	return (1);
}

int		check_charperline(char *str)
{
	t_init2		tmp;

	init(NULL , &tmp);
	while (str[tmp.i] != '\0')
	{
		if (str[tmp.i] == '.' || str[tmp.i] == '#')
			tmp.count++;
		if (tmp.count > 4)
			return (0);
		if (str[tmp.i] == '\n' && tmp.i == tmp.line_5)
		{
			tmp.count = 0;
			tmp.line_5 += 5;
			tmp.lines++;
		}
		if (str[tmp.i] == '\n' && str[tmp.i + 1] == '\n' && tmp.lines == 4)
		{
			tmp.line_5++;
			tmp.lines = 0;
		}
		tmp.i++;
	}
	return (1);
}

int 	check_new_lines_at_end(char *str)
{
	int 	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != '\0')
	{
		if (str[i] == '\n' && str[i - 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}
