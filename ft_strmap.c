/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:32:25 by kialvare          #+#    #+#             */
/*   Updated: 2016/10/13 20:34:59 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	else
	{
		new = ft_strnew(ft_strlen(s));
		if (!new)
			return (NULL);
		i = 0;
		while (s[i])
		{
			new[i] = (*f)(s[i]);
			i++;
		}
	}
	return (new);
}
