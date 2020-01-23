/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:27:48 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 15:38:04 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_dblstmax(t_dblst *lst, int (*cmp)(const void *, const void *))
{
	t_data		*max;
	t_dbnode	*it;

	if (!lst->head)
		return (NULL);
	it = lst->head;
	max = it->data;
	while ((it = it->next) != lst->head)
		if (cmp(max->content, it->data->content) < 0)
			max = it->data;
	return (max);
}
