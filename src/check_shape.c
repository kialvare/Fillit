/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:18:46 by phoreau           #+#    #+#             */
/*   Updated: 2016/11/08 20:44:29 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 
** 
** The official code
** 
*/

int		check_connection(char **str)
{
	int 	x;
	int 	y;
	int		c;

	y = 0;
	c = 0;
	if (*str == NULL)
		return (0);
	while (y <= 3)
	{
		x = 0;
		while (x <= 3)
		{
			if (str[y][x] == '#')
			{
				if (x <= 2 && str[y][x + 1] == '#')
					c++;
				if (y <= 2 && str[y + 1][x] == '#')
				 	c++;
			}
			x++;
		}
		y++;
	}
	if (c != 3 && c != 4)
		return (0);
	return (1);
}

// int		check_connection(char **str)
// {
// 	int		i;
// 	int		yt;
// 	int		count;
// 	int		x;
// 	int		y;

// 	i = 0;
// 	yt = 4;
// 	while (str[i])
// 	{
// 		y = 0;
// 		count = 0;
// 		yt = 4;
// 		if (*str == NULL)
// 			return (0);
// 		count = 0;
// 		while (count <= 3)
// 		{
// 			x = 0;
// 			while (x <= 3)
// 			{
// 				if (str[y][x] == '#')
// 				{
// 					if (x <= 2 && str[y][x + 1] == '#')
// 						count++;
// 					if (y <= yt - 2 && str[y + 1][x] == '#')
// 					 	count++;
// 					x++;
// 					y++;
// 				}
// 			}
// 			yt = y;
// 		}
// 		if (count != 3 && count != 4)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }