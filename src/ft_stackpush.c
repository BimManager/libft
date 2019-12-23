/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:49:57 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/04 09:36:47 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackpush(t_stack *stack, void *content, size_t content_size)
{
	t_list *new;

	if (!stack)
		return ;
	new = ft_lstnew(content, content_size);
	new->next = stack->top;
	stack->top = new;
}
