/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequesnoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:29:37 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/29 13:17:42 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dequesnoc(t_deque *deque, const void *data, size_t size)
{
	t_list	*tail;

	tail = ft_lstnew(data, size);
	if (!deque->head)
		deque->head = tail;
	else
		deque->tail->next = tail;
	deque->tail = tail;
}
