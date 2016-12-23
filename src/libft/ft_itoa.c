/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:22:31 by kialvare          #+#    #+#             */
/*   Updated: 2016/10/15 22:28:14 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*num_str(int n, char *s, unsigned int i)
{
	unsigned int num;

	i--;
	if (n < 0)
	{
		num = -n;
		s[0] = '-';
	}
	else
		num = n;
	if (num >= 10)
	{
		num_str((num / 10), s, i);
		s[i] = ((num % 10) + '0');
	}
	else
		s[i] = (num + '0');
	return (s);
}

static unsigned int		num_len(int n)
{
	unsigned int i;
	unsigned int num;

	i = 0;
	if (n < 0)
	{
		num = (unsigned int)-n;
		i++;
	}
	else
		num = (unsigned int)n;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char					*ft_itoa(int n)
{
	unsigned int	size;
	char			*s;

	size = num_len(n);
	if (n == 0)
	{
		if (!(s = ft_strnew(1)))
			return (NULL);
		s[0] = '0';
	}
	else
	{
		if (!(s = ft_strnew(size)))
			return (NULL);
		s = num_str(n, s, size);
	}
	return (s);
}
