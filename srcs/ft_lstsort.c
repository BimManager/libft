/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:28:22 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/17 11:41:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_content(t_list *node)
{
	return (node->content || node->content_size);
}

static void		ft_swap_content(t_list *n1, t_list *n2)
{
	ft_swap(n1->content, n2->content, sizeof(void *));
	ft_swap(&n1->content_size, &n2->content_size, sizeof(size_t));
}

t_list			*ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*itr_i;
	t_list	*itr_j;

	itr_i = lst;
	while (itr_i)
	{
		itr_j = itr_i->next;
		while (itr_j)
		{
			if (ft_content(itr_i) && ft_content(itr_j) &&
				!cmp(itr_i->content, itr_j->content))
				ft_swap_content(itr_i, itr_j);
			itr_j = itr_j->next;
		}
		itr_i = itr_i->next;
	}
	return (lst);
}
