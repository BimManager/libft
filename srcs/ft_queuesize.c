/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuesize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:02:55 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/16 14:03:21 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_queuesize(t_queue *queue)
{
	if (!queue || !queue->head)
		return (0);
	return (ft_lstsize(queue->head));
}
