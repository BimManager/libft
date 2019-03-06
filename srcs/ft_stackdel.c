/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:57:15 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/01 09:10:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackdel(t_stack **stack, void (*del) (void *, size_t))
{
	if (!*stack)
		return ;
	ft_lstdel(&(*stack)->top, del);
	free(*stack);
	*stack = 0;
}
