/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:02:46 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/03 17:02:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue	*ft_queuenew(void const *content, size_t content_size)
{
	t_queue	*queue;
	t_list	*new;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	if (!content)
		new = NULL;
	else
	{
		new = ft_lstnew(content, content_size);
		if (!new)
		{
			free(queue);
			return (NULL);
		}
	}
	queue->head = new;
	queue->tail = new;
	return (queue);
}
