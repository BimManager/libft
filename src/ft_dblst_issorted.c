/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblst_issorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:36:16 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/15 13:43:06 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dblst_issorted(t_dblst *lst,
		int (*cmp)(const void *, const void *), int asc)
{
	t_dbnode	*it;
	t_dbnode	*prv;
	int			i;

	if (!lst->head)
		return (1);
	prv = lst->head;
	it = lst->head;
	i = asc ? 1 : -1;
	while ((it = it->next) != lst->head)
	{
		if (0 < (cmp(prv->data->content, it->data->content) * i))
			return (0);
		prv = it;
	}
	return (1);
}
