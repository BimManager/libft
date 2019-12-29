/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequecons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:26:04 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/29 12:36:18 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dequecons(t_deque *deque, const void *data, size_t size)
{
	t_list	*head;

	head = ft_lstnew(data, size);
	head->next = deque->head;
	deque->head = head;
	if (!deque->tail)
		deque->tail = head;
}
