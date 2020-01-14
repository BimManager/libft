/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbnodedel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:52:44 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/13 14:53:08 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbnodedel(t_dbnode **node, void (*del)(void *, size_t))
{
	ft_datadel(&(*node)->data, del);
	free(*node);
	*node = NULL;
}
