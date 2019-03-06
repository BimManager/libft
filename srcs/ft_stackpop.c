/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:51:25 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/04 09:32:44 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_stackpop(t_stack *stack)
{
	t_list	*top;

	if (!stack || !stack->top)
		return (NULL);
	top = stack->top;
	stack->top = stack->top->next;
	top->next = NULL;
	return (top);
}
