/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:20:40 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/29 14:06:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dequedel(t_deque **deque, void (*del)(void *, size_t))
{
	t_list	*hd_tl;

	if ((hd_tl = (*deque)->head))
		ft_lstdel(&hd_tl, del);
	free(*deque);
	*deque = NULL;
}
