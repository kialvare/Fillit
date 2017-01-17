/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:13:14 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/12 21:13:23 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_count(char *s)
{
	int i;
	int hashes;

	i = 0;
	hashes = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '.') || (s[i] == '#') || (s[i] == '\n'))
		{
			if (s[i] == '#')
				hashes++;
			i++;
		}
		else
			return (1);
	}
	if (i == 19 && hashes == 4)
		return (1);
	else
		return (0);
}

int count_tetri(char *s)
{
	int i;
	int connection;

	i = 0;
	connection = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if ((i + 1) < 19 && s[i + 1] == '#')
				connection++;
			if ((i - 1) >= 0 && s[i - 1] == '#')
				connection++;
			if ((i + 5) < 19 && s[i + 5] == '#')
				connection++;
			if ((i - 5) >= 0 && s[i - 5] == '#')
				connection++;
		}
		i++;
	}
	return (connection);
}

int ft_valid(char *s)
{
	int i;
	int len;
	int pieces;
	char **new_str;

	i = 0;
	pieces = 0;
	new_str = ft_strsplitstr(s, "\n\n");
	len = ft_arrlen(new_str);
	while (new_str[i] != NULL)
	{
		if (check_count(new_str[i]) == 1 )
			if ((count_tetri(new_str[i]) == 6) || (count_tetri(new_str[i]) == 8))
				pieces++;
		i++;
	}
	if (pieces != len || pieces > 26)
		return (0);
	return (1);
}
