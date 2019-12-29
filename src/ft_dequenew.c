/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:18:50 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/29 12:20:02 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_deque	*ft_dequenew(void)
{
	t_deque	*ret;

	ret = malloc(sizeof(t_deque));
	ret->head = NULL;
	ret->tail = NULL;
	return (ret);
}
