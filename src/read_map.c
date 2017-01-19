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

void		hash_to_alph(char **str, int len)
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

void		put_error(void)
{
	ft_putendl("error");
}

char		***store_tetri(char *raw_map)
{
	char	**str;
	char	***pieces;
	int		i;
	int		len;

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
		return (pieces);
	}
	else
	{
		put_error();
		return (0);
	}
}
