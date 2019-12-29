/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeeject.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:47:26 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/29 13:04:23 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_dequeeject(t_deque *deque)
{
	t_list	*ret;
	t_list	*it;

	ret = deque->tail;
	if (deque->head == deque->tail)
	{
		deque->head = NULL;
		deque->tail = NULL;
	}
	it = deque->head;
	while (it)
	{
		if (it->next == ret)
		{
			deque->tail = it;
			it->next = NULL;
		}
		it = it->next;
	}
	return (ret);
}
