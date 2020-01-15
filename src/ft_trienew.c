/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trienew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:01:04 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/15 13:01:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_trie	*ft_trienew(t_data *data)
{
	t_trie	*trie;
	int		i;

	trie = malloc(sizeof(t_trie));
	trie->data = data;
	i = -1;
	while (++i < TRIE_SIZE)
		(trie->next)[i] = NULL;
	return (trie);
}
