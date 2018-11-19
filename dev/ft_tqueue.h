/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tqueue.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:10:03 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/13 20:37:33 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TQUEUE_H
# define FT_TQUEUE_H

# include "ft_lib.h"

typedef struct		s_queue
{
	unsigned int	logical_size;
	unsigned int	elem_size;
	void			*front;
	void			*rear;
	void			*elems;
	void			(*free_fn)(void *);
}					t_queue;

void				tqueue_create(t_queue **queue, unsigned int size,
					unsigned int elem_size, void (*dis_fn) (void *));
void				tqueue_dispose(t_queue *queue);
void				tqueue_enqueue(t_queue *queue, void *item);
void				tqueue_dequeue(t_queue *queue, void *item);
void				tqueue_peek(t_queue *queue, void *item);
int					tqueue_empty(t_queue *queue);

#endif
