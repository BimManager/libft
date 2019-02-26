/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:55:03 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/16 11:59:19 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_enqueue(t_queue *queue, void *content, size_t content_size)
{
	t_list *new;

	if (!queue || !queue->tail)
		return ;
	new = ft_lstnew(content, content_size);
	if (!new)
		return ;
	queue->tail->next = new;
	queue->tail = new;
}
