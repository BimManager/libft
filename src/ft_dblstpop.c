/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:21:38 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/17 11:45:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_dblstpop(t_dblst *lst)
{
	t_data		*ret;
	t_dbnode	*node;

	if (!lst->head)
		return (NULL);
	--lst->elems;
	ret = lst->head->data;
	if (lst->head == lst->head->next)
	{
		free(lst->head);
		lst->head = NULL;
	}
	else
	{
		node = lst->head->next;
		node->prev = lst->head->prev;
		lst->head->prev->next = node;
		free(lst->head);
		lst->head = node;
	}
	return (ret);
}
