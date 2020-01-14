/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:01:08 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/13 19:48:28 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dblstdel(t_dblst **lst, void (*del)(void *, size_t))
{
	t_dbnode	*it;
	t_dbnode	*tmp;

	it = (*lst)->head;
	while (it)
	{
		it->prev->next = NULL;
		tmp = it->next;
		ft_dbnodedel(&it, del);
		it = tmp;
	}
	free(*lst);
	*lst = NULL;
}
