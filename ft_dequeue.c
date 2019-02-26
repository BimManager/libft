/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:59:39 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/16 12:00:04 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dequeue(t_queue *queue)
{
	void		*content;

	if (!queue || !queue->head)
		return (0);
	content = malloc(queue->head->content_size * sizeof(char));
	if (!content)
		return (0);
	ft_memcpy(content, queue->head->content, queue->head->content_size);
	ft_lstdelone(&queue->head, queue->free_fn);
	return (content);
}
