/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbnodenew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:51:16 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/13 14:53:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbnode	*ft_dbnodenew(t_data *data, t_dbnode *prv, t_dbnode *nxt)
{
	t_dbnode	*node;

	node = malloc(sizeof(t_dbnode));
	node->data = data;
	node->prev = prv;
	node->next = nxt;
	return (node);
}
