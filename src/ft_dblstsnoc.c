/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstsnoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:31:33 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/14 14:05:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dblstsnoc(t_dblst *lst, t_data *data)
{
	t_dbnode	*node;

	if (!lst->head)
	{
		node = ft_dbnodenew(data, NULL, NULL);
		node->prev = node;
		node->next = node;
		lst->head = node;
	}
	else
	{
		node = ft_dbnodenew(data, lst->head->prev, lst->head);
		lst->head->prev->next = node;
		lst->head->prev = node;
	}
}
