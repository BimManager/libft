/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:46:33 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/21 15:26:26 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelif(t_list **alst, void *ref_data,
			int (*cmp)(const void *, const void *),
			void (*del) (void *, size_t))
{
	t_list	*prv;
	t_list	*itr;

	if (!alst || !ref_data)
		return ;
	itr = *alst;
	while (itr)
	{
		if (!cmp(itr->content, ref_data))
		{
			if (itr == *alst)
			{
				*alst = itr->next;
				ft_lstdelone(&itr, del);
				itr = *alst;
				continue;
			}
			prv->next = itr->next;
			ft_lstdelone(&itr, del);
			itr = prv->next;
			continue ;
		}
		prv = itr;
		itr = itr->next;
	}
}
