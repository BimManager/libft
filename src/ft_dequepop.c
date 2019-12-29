/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequepop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:45:35 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/29 13:09:09 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_dequepop(t_deque *deque)
{
	t_list	*ret;

	ret = deque->head;
	if (deque->head)
	{
		if (deque->head == deque->tail)
		{
			deque->head = NULL;
			deque->tail = NULL;
		}
		else
		{
			deque->head = deque->head->next;
			ret->next = NULL;
		}
	}
	return (ret);
}
