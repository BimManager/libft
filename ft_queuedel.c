/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:01:36 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/16 12:01:58 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queuedel(t_queue **queue)
{
	if (!*queue)
		return ;
	ft_lstdel(&(*queue)->head, (*queue)->free_fn);
	free(*queue);
	*queue = 0;
}
