/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:01:36 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/04 09:27:21 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queuedel(t_queue **queue, void (*del) (void *, size_t))
{
	if (!*queue)
		return ;
	ft_lstdel(&(*queue)->head, del);
	free(*queue);
	*queue = 0;
}
