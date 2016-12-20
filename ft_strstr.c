/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:49:27 by kialvare          #+#    #+#             */
/*   Updated: 2016/10/05 21:21:53 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *str;
	char *tofind;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		if (*big == *little)
		{
			str = (char *)big;
			tofind = (char *)little;
			while (*str && *tofind && *str == *tofind)
			{
				str++;
				tofind++;
			}
			if (!*tofind)
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
