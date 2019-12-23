/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:59:39 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/03 13:53:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_dequeue(t_queue *queue)
{
	t_list	*ret;

	if (!queue || !queue->head)
		return (NULL);
	ret = queue->head;
	queue->head = queue->head->next;
	if (queue->tail == ret)
		queue->tail = queue->head;
	ret->next = NULL;
	return (ret);
}
