/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fndmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:23:15 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/12 15:26:33 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_fndmax(void *base, size_t nel, size_t width,
			int (*cmp)(const void *, const void *))
{
	void	*pmax;

	pmax = base;
	while (1 < nel--)
		if (cmp((char *)base + nel * width, pmax) > 0)
			pmax = (char *)base + nel * width;
	return (pmax);
}
