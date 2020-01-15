/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trieadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:01:50 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/15 13:02:10 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_trieadd(t_trie *trie, const char *query, t_data *data)
{
	t_trie	*tmp;

	tmp = trie;
	while (*query)
	{
		if (!(tmp->next)[(int)*query])
			(tmp->next)[(int)*query] = ft_trienew(NULL);
		++query;
		if (!*query)
			((tmp->next)[(int)*(query - 1)])->data = data;
		tmp = (tmp->next)[(int)*(query - 1)];
	}
}
