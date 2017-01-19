/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 09:38:37 by kialvare          #+#    #+#             */
/*   Updated: 2016/10/27 12:36:28 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		s1_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	else
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		s1_len = ft_strlen(s1);
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcpy(&str[s1_len], s2);
	}
	return (str);
}
