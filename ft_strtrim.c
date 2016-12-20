/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:21:54 by kialvare          #+#    #+#             */
/*   Updated: 2016/10/15 23:19:23 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iswhitespace(int c)
{
	return ((c == ' ') || (c == '\n') || (c == '\t'));
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_iswhitespace(s[j - 1]))
		j--;
	while (ft_iswhitespace(s[i]))
		i++;
	if (s[i] == '\0')
	{
		str = ft_strnew(0);
		return (str);
	}
	len = j - i;
	str = ft_strsub(s, i, len);
	return (str);
}
