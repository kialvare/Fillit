/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:13:14 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/24 18:37:38 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int count_newlines(char *s)
{
	int i;
	int newline;
	int numerator;

	i = 0;
	newline = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			newline++;
		i++;
	}
	numerator = (5 * i) - 16;
	printf("%d\n", i);
	printf("numerator: %d\n", numerator);
	printf("numerator / 21: %d\n", numerator / 21);
	printf("numerator mod 21: %d\n", numerator % 21);
	if (numerator % 21 != 0)
	{
		ft_putendl("error");
		return (1);
	}
	if (numerator / 21 == newline)
	{
		return (0);
	}
	else
	{
		ft_putendl("error");
		return (1);
	}
}

int		check_count(char *s)
{
	int i;
	int hashes;
	int newline;
	int period;

	i = 0;
	hashes = 0;
	newline = 0;
	period = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '.') || (s[i] == '#') || (s[i] == '\n'))
		{
			if (s[i] == '#')
				hashes++;
			if (s[i] == '\n')
				newline++;
			if (s[i] == '.')
				period++;
			i++;
		}
		else
			return (1);
	}
	if (i == 19 && hashes == 4 && newline == 3)
		return (0);
	else
		return (1);
}

int		count_tetri(char *s)
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

int		ft_valid(char *s)
{
	int		i;
	int		len;
	int		pieces;
	char	**new_str;

	i = 0;
	pieces = 0;
	new_str = ft_strsplitstr(s, "\n\n");
	len = ft_arrlen((void **)new_str);
	while (new_str[i] != NULL)
	{
		if (check_count(new_str[i]) == 0)
			if ((count_tetri(new_str[i]) == 6) ||
				(count_tetri(new_str[i]) == 8))
				pieces++;
		i++;
	}
	if (pieces != len || pieces > 26)
		return (1);
	return (0);
}
