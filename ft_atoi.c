/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 18:08:46 by kialvare          #+#    #+#             */
/*   Updated: 2016/10/18 17:08:32 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkwhitespace(const char *str, int i)
{
	if ((str[i]) == ' ' || (str[i]) == '\t' || (str[i]) == '\n' ||
		(str[i]) == '\v' || (str[i]) == '\r' || (str[i]) == '\f')
		return (1);
	else
		return (0);
}

static int	ft_checksign(const char *str, int i)
{
	if ((str[i]) == '-' || (str[i]) == '+')
	{
		i++;
		if (!(((str[i]) >= '0') && ((str[i]) <= '9')))
			return (0);
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int a;
	int i;
	int j;

	a = 0;
	i = 0;
	j = 1;
	while (ft_checkwhitespace(str, i) == 1)
		i++;
	i = ft_checksign(str, i);
	while ((str[i]) != '\0')
	{
		if ((str[i - 1]) == '-')
			j = -1;
		if (((str[i]) >= '0') && ((str[i]) <= '9'))
		{
			a = a * 10 + str[i] - '0';
			i++;
		}
		else
			return (j * a);
	}
	return (j * a);
}
