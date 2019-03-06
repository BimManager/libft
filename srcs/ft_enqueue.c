/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:55:03 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/03 13:56:16 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_enqueue(t_queue *queue, void *content, size_t content_size)
{
	t_list *new;

	if (!queue)
		return ;
	new = ft_lstnew(content, content_size);
	if (!new)
		return ;
	if (queue->tail != NULL)
	{
		queue->tail->next = new;
		queue->tail = new;
	}
	else
	{
		queue->tail = new;
		queue->head = new;
	}
}
