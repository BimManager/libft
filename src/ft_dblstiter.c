/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:09:29 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/14 14:12:50 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dblstiter(t_dblst *lst, void (*fn)(t_dbnode *))
{
	t_dbnode *it;

	if (!lst->head)
		return ;
	it = lst->head;
	fn(it);
	while ((it = it->next) != lst->head)
		fn(it);
}
