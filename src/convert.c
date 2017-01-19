/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:25:20 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/05 09:25:22 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Converts the 1D string after checking validation into a 2D array
*/

char		**allocate_array(char **str)
{
	int		i;

	i = 0;
	str = malloc(4 * sizeof(char));
	while (i < 4)
	{
		str = malloc(4 * sizeof(char *));
		i++;
	}
	return (str);
}

char		**convert(char *str)
{
	int		x;
	int		y;
	char	**str1;

	x = 0;
	str1 = NULL;
	str1 = allocate_array(str1);
	while (x < 0)
	{
		y = 0;
		while (y < 0)
		{
			str1[x][y] = str[y * 2 + x];
			x++;
		}
		y++;
	}
	return (str1);
}
