/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:37:43 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/02 11:58:42 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list *prv;
	t_list *cur;
	t_list *nxt;

	if (!alst || !*alst)
		return ;
	prv = 0;
	cur = *alst;
	while (cur)
	{
		nxt = cur->next;
		cur->next = prv;
		prv = cur;
		cur = nxt;
	}
	*alst = prv;
}
