/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:12:34 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/15 13:41:41 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	xtriedel(t_trie *trie, void (*del)(void *, size_t))
{
	int	i;

	i = -1;
	while (++i < TRIE_SIZE)
	{
		if ((trie->next)[i])
			xtriedel((trie->next)[i], del);
	}
	if (trie->data)
		ft_datadel(&trie->data, del);
	free(trie);
}

void		ft_triedel(t_trie **trie, void (*del)(void *, size_t))
{
	xtriedel(*trie, del);
	*trie = NULL;
}
