/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:49:48 by kialvare          #+#    #+#             */
/*   Updated: 2016/10/11 16:44:20 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

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
			new[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (new);
}
