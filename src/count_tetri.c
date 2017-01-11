/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:25:27 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/05 09:25:28 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

// int	count_tetri(char *s)
// {
// 	int i;

// 	i = 0;
// 	while(s[i])
// 	{
// 		if((((i % 20) == 0 && i <= 20) || (i % 21 == 0 && i > 21)) 
// 		 && s[i] != '\n')
// 			return (0);
// 		i++;
// 	}
// 	if (i > 20)
// 		if ((i - 20) % 21 == 0 && (i / 21) <= 26)
// 			return ((i + 1) / 21);
// 	if (i == 20)
// 		return (1);
// 	return (0);
// }

int	check_count(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '.') || (s[i] == '#') || (s[i] == '\n'))
			i++;
		else
			return (0);
		i++;
	}
	if (i != 21)
		return (0);
	else
		return (1);
}

// int	count_tetri(char *s)
// {
// 	int i;
// 	int len;
// 	char **new_str;

// 	i = 0;
// 	new_str = ft_strsplitstr(s, "\n\n");
// 	len = ft_arrlen(new_str);
// 	printf("Length of array: %d\n", len);
// 	while(i < len)
// 	{
// 		if (check_count(new_str[i]) != 1)
// 			return (0);
// 		else
// 			i++;
// 	}
// 	return (1);
// }

int	tetri_valid(char *s, int i)
{
	int	j;
	int	limit;
	int	k;
	int	hashes;
	int ans;

	ans = 0;
	hashes = 0;
	j = (i * 21);
	limit = (j + 21);
	k = j;
	while (s[k] && k < limit)
	{
		if(s[k] == '#')
			hashes++;
		k++;
	}
	if ((hashes % 4) != 0)
		return (1);
	while (j < limit)
	{
		if (s[j] == '#')
		{
			if (s[j + 1] == '#')
				ans += 1;
			if (s[j + 5] == '#')
				ans += 1;
		}			
		j++;
	}
	if (ans >= 4)
		return (0);
	return (1);
}

int ft_valid(char *s)
{
	int i;
	int len;
	char **new_str;

	i = 0;
	new_str = ft_strsplitstr(s, "\n\n");
	len = ft_arrlen(new_str);
	while(i < len)
	{
		ft_putstr(new_str[i]);
		if ((check_count(new_str[i]) != 1) && (tetri_valid(new_str[i], len) != 1))
			return (0);
		i++;
	}
	return (1);
}

// int ft_valid(char *s)
// {
// 	int n;
// 	int i;

// 	n = ft_arrlen(ft_strsplitstr(s, "\n\n"));
// 	i = 0;
// 	if (n == 0 || n > 26)
// 		return (0);
// 	if (count_tetri(s) != 1)
// 		return (0);
// 	while (i <= n && i >= 0)
// 	{
// 		if (tetri_valid(s, i) != 1)
// 			return (0);
// 		i++;
// 	}
// 	return (0);
// }
