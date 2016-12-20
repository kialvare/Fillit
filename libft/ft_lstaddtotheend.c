/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtotheend.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:22:57 by phoreau           #+#    #+#             */
/*   Updated: 2016/11/22 15:23:02 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We add the link the the end of the list.
** We need to make sure that our add-link is not NULL so we set it to new in case that it is.
** Otherwise, we create a while loop where it will always point to the next struct.
** 
*/

void	ft_lstaddtotheend(t_list **alst, t_list *new)
{
	t_list		*tmp;

	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
