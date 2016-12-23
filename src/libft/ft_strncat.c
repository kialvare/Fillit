/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:08:01 by kialvare          #+#    #+#             */
/*   Updated: 2016/11/21 15:44:45 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int destlen;
	int srclen;
	int i;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen((char*)src);
	while ((destlen <= (destlen + srclen)) && ((int)n > 0))
	{
		dest[destlen] = src[i];
		destlen++;
		srclen--;
		i++;
		n--;
	}
	dest[i + destlen] = '\0';
	return (dest);
}
