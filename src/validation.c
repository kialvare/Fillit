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

int		check_count(char *file)
{
	int i;
	int hashes;
	int newline;
	int period;

	i = 0;
	hashes = 0;
	newline = 0;
	period = 0;
	while (file[i] != '\0')
	{
		if ((file[i] == '.') || (file[i] == '#') || (file[i] == '\n'))
		{
			file[i] == '#' ? hashes++ : 1;
			file[i] == '\n' ? newline++ : 1;
			file[i] == '.' ? period++ : 1;
			i++;
		}
		else
			return (1);
	}
	if ((i == 20 || i == 19) && hashes == 4 && (newline == 3 || newline == 4) 
		&& period == 12)
		return (0);
	return (1);
}

int		count_tetri(char *file)
{
	int i;
	int connection;

	i = 0;
	connection = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '#')
		{
			if ((i + 1) < 19 && file[i + 1] == '#')
				connection++;
			if ((i - 1) >= 0 && file[i - 1] == '#')
				connection++;
			if ((i + 5) < 19 && file[i + 5] == '#')
				connection++;
			if ((i - 5) >= 0 && file[i - 5] == '#')
				connection++;
		}
		i++;
	}
	return (connection);
}

int		count_newlines(char *file)
{
	int i;
	int newline;
	int numerator;

	i = 0;
	newline = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
			newline++;
		i++;
	}
	numerator = (5 * i) - 16;
	if (numerator / 21 == newline && numerator % 21 == 0)
		return (0);
	return (1);
}

int		ft_valid(char *file)
{
	int		i;
	int		pieces;
	char	**new_str;

	i = 0;
	pieces = 0;
	new_str = ft_strsplitstr(file, "\n\n");
	if (count_newlines(file) == 0)
	{
		while (new_str[i] != NULL)
		{
			if (check_count(new_str[i]) == 0)
			{
				if (count_tetri(new_str[i]) == 6 || count_tetri(new_str[i]) == 8)
					pieces++;
				else
					return (1);
			}
			else
				return (1);
			i++;
		}
		return (0);
	}
	else
		return (1);
	return (pieces > 26 ? 1 : 0);
}

// count_tetri(new_str[i]) == 6 ? pieces++ : 1;
// count_tetri(new_str[i]) == 8 ? pieces++ : 1;