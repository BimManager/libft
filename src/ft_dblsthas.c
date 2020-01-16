/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblsthas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:06:27 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/15 14:41:36 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dblsthas(t_dblst *lst, const void *content,
		int (*cmp)(const void *, const void *))
{
	t_dbnode	*it;

	if (!lst->head)
		return (0);
	if (0 == cmp((it = lst->head)->data->content, content))
		return (1);
	while ((it = it->next) != lst->head)
	{
		if (0 == cmp(it->data->content, content))
			return (1);
	}
	return (0);
}
