/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblsteject.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:36:20 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/13 19:48:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_dblsteject(t_dblst *lst)
{
	t_data		*ret;
	t_dbnode	*head;

	if (!(head = lst->head))
		return (NULL);
	lst->head = lst->head->prev;
	ret = ft_dblstpop(lst);
	if (lst->head)
		lst->head = head;
	return (ret);
}
