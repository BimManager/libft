/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:36:26 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/15 16:53:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *lstmap;
	t_list *lstitr;

	if (!lst)
		return (0);
	lstmap = f(lst);
	if (!lstmap)
		return (0);
	lstitr = lstmap;
	while ((lst = lst->next))
	{
		lstitr->next = f(lst);
		lstitr = lstitr->next;
	}
	return (lstmap);
}
