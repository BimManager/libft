/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insrtsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:42:30 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/16 19:42:31 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insrtsort(void *base, size_t nel, size_t width,
			int (*cmp)(const void *, const void *))
{
	size_t	i;
	size_t	j;

	i = 0;
	while (++i < nel)
	{
		j = i;
		while (0 < j && cmp((char *)base + (j - 1) * width,
							(char *)base + j * width) > 0)
		{
			ft_swap((char *)base + (j - 1) * width,
					(char *)base + j * width, width);
			--j;
		}
	}
}
