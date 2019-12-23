/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:42:32 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/04 09:26:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stacknew(void const *content, size_t content_size)
{
	t_stack	*stack;
	t_list	*new;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (!content)
		new = NULL;
	else
	{
		new = ft_lstnew(content, content_size);
		if (!new)
		{
			free(stack);
			return (NULL);
		}
	}
	stack->top = new;
	return (stack);
}
