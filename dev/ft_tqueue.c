/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tqueue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:15:10 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/15 10:17:30 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tqueue.h"

void	tqueue_create(t_queue **queue,
			unsigned int size, unsigned int elem_size,
			void (*dis_fn) (void *))
{
	*queue = malloc(sizeof(t_queue));
	(*queue)->logical_size = size;
	(*queue)->elem_size = elem_size;
	(*queue)->free_fn = dis_fn;
	(*queue)->elems = malloc((*queue)->logical_size * (*queue)->elem_size);
	(*queue)->front = (*queue)->elems;
	(*queue)->rear = (*queue)->elems;
}

int		tqueue_empty(t_queue *queue)
{
	if ((char*)queue->front == (char*)queue->rear)
		return (1);
	return (0);
}

void	tqueue_dispose(t_queue *queue)
{
	unsigned int i;

	if (!queue->free_fn)
		return;
	i = -1;
	while (++i < queue->logical_size)
	{
		if (!ft_memcmp((char*)queue->elems + queue->elem_size * i,
					   queue->rear, queue->elem_size))
			break ;
		queue->free_fn((char*)queue->elems + queue->elem_size * i);
	}
	free(queue->elems);
}

void	tqueue_enqueue(t_queue *queue, void *item)
{
	if (((char*)queue->rear - (char*)queue->elems)
		/ queue->elem_size == queue->logical_size)
	{
		ft_putstr("Size limit has been reached\n");
		return ;
	}
	ft_memcpy(queue->rear, item, queue->elem_size);
	queue->rear = queue->rear + queue->elem_size;
}

void	tqueue_dequeue(t_queue *queue, void *item)
{
	if (tqueue_empty(queue))
		return ;
	ft_memcpy(item, queue->front, queue->elem_size);
	queue->front = queue->front + queue->elem_size;
}

void	tqueue_peek(t_queue *queue, void *item)
{
	if (tqueue_empty(queue))
		return ;
	if (!item)
		item = malloc(queue->elem_size * sizeof(char));
	ft_memcpy(item, queue->front, queue->elem_size);
}
