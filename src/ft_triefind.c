/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triefind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:02:18 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/15 13:02:31 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_triefind(t_trie *trie, const char *query)
{
	t_trie	*tmp;

	tmp = trie;
	while (*query)
	{
		if (!(tmp = (tmp->next)[(int)*query]))
			return (NULL);
		++query;
	}
	return (tmp->data);
}
