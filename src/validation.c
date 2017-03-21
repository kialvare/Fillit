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
	// if (numerator % 21 != 0)
	// 	return (1);
	printf("numerator: %d\n", numerator);
	printf("numerator / 21:%d\n", numerator / 21);
	printf("numerator mod 21: %d\n", numerator % 21);
	if (numerator / 21 == newline && numerator % 21 == 0)
		return (0);
	else
		return (1);
}

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
		// printf("%c\n", file[i]);
		if ((file[i] == '.') || (file[i] == '#') || (file[i] == '\n'))
		{
			//printf("Does it even go in here\n");
			if (file[i] == '#')
			{
				// printf("Hashes: %d\n", hashes);
				hashes++;
			}
			if (file[i] == '\n')
			{
				// printf("Newlines: %d\n", newline);
				newline++;
			}
			if (file[i] == '.')
			{
				// printf("Period: %d\n", period);
				period++;
			}
			// printf("i: %d\n", i);
			i++;
		}
		else
			return (1);
	}
	printf("i: %d\n", i);
	printf("Hashes: %d\n", hashes);
	printf("Newlines: %d\n", newline);
	printf("Period: %d\n", period);
	if (i == 20 && hashes == 4 && newline == 4 && period == 12)
	{
		//printf("Catches error?\n");
		return (0);
	}
	else
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
			//printf("Does it even go in here\n");
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
	printf("Connection: %d\n", connection);
	if (connection == 6 || connection == 8)
		return (0);
	else
		return (1);
}

int		ft_valid(char *file)
{
	int		i;
	int		len;
	int		pieces;
	char	**new_str;

	i = 0;
	pieces = 0;
	new_str = ft_strsplitstr(file, "\n\n");
	len = ft_arrlen((void **)new_str);
	while (new_str[i] != NULL)
	{
		if (count_newlines(new_str[i]) == 0 && check_count(new_str[i]) == 0)
		{
			// printf("Does it even pass through here\n");
			if (count_tetri(new_str[i]) == 0)
			{
				printf("Do you even spoon bro\n");
				// printf("%d\n", count_tetri(new_str[i]));
				pieces++;
			}
			else
			{
				printf("Does it pass here\n");
				return (1);
				break ;
			}
		}
		i++;
	}
	if (pieces != len || pieces > 26)
		return (1);
	else
		return (0);
}
