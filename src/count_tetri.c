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

int	count_tetri(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if((((i = 20) == 0 && i <= 20) || (i + 1 % 21 == 0 && i > 21)) && s[i] != '\n')
			return (0);
		i++;
	}
	if (i > 20)
		if ((i - 20) % 21 == 0 && (i / 21) <= 26)
			return ((i + 1) / 21);
	if (i == 20)
		return (1);
	return (0);
}

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
		return (0);
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
	if (ans >= 3)
		return (1);
	return (0);
}
