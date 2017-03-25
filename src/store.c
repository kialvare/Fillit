/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:15:49 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/24 18:33:42 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	hash_to_alph(char **str, int len)
{
	int		i;
	int		j;
	char	c;

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

char	***store_tetri(char *file)
{
	char	**str;
	char	***pieces;
	int		i;
	int		len;

	if (ft_valid(file) == 0)
	{
		i = 0;
		str = ft_strsplitstr(file, "\n\n");
		len = ft_arrlen((void **)str);
		hash_to_alph(str, len);
		pieces = ft_memalloc(sizeof(char **) * (len + 1));
		while (i < len)
		{
			printf("Is it going in here\n");
			pieces[i] = ft_strsplitstr(str[i], "\n");
			i++;
		}
		return (pieces);
	}
	else
	{
		// printf("Is it this error?\n");
		ft_putendl("error");
		return (0);
	}
}
