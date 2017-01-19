/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:15:49 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/16 15:15:53 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		find_width(char **str)
{
	int i;
	int j;
	int hold;
	int width;

	i = 0;
	hold = 0;
	while (str[i] != '\0')
	{
		j = 0;
		width = 0;
		while (str[i][j] != '\0')
		{
			if (ft_isupper(str[i][j]) || str[i][j] != '.')
				width++;
			j++; 
		}
		if (width > hold)
			hold = width;
		i++;
	}
	return (hold);
}

int		find_height(char **str)
{
	int i;
	int j;
	int height;
	int hold;

	i = 0;
	height = 0;
	while (str[i] != '\0')
	{
		j = 0;
		hold = height;
		while (str[i][j] != '\0' && hold == height)
		{
			if (str[i][j] != '.')
				height++;
			j++;
		}
		i++;
	}
	return (height);
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
			i++;
		}
		return(pieces);
	}
	else
	{
		ft_putendl("error");
		return (0);
	}
}
