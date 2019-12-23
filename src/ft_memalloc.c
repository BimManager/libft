/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:38:03 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/12 16:38:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *pv;

	pv = malloc(size * sizeof(char));
	if (!pv)
		return (0);
	while (size--)
		*((char*)pv + size) = 0;
	return (pv);
}
