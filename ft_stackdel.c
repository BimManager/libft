/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:57:15 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/16 13:57:31 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackdel(t_stack **stack)
{
	if (!*stack)
		return ;
	ft_lstdel(&(*stack)->top, (*stack)->free_fn);
	free(*stack);
	*stack = 0;
}
