/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:54:33 by kialvare          #+#    #+#             */
/*   Updated: 2016/10/07 13:57:09 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char str1;
	unsigned char str2;

	str1 = *s1;
	str2 = *s2;
	if (!n)
		return (0);
	else if (!str1 && !str2)
		return (0);
	else if (str1 != str2)
		return (str1 - str2);
	return (ft_strncmp(++s1, ++s2, --n));
}
