/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:14:08 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/05 11:19:10 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	memswap(void *pv1, void *pv2, size_t n)
{
	char	temp;

	while (n--)
	{
		temp = *((char *)pv1 + n);
		*((char *)pv1 + n) = *((char *)pv2 + n);
		*((char *)pv2 + n) = temp;
	}
}

static void	maxheapify(void *base, size_t nel, size_t width,
				size_t i, int (*cmp)(const void *, const void *))
{
	size_t	left;
	size_t	right;
	size_t	max;

	left = LEFT(i);
	right = RIGHT(i);
	max = i;
	if (left < nel
		&& 0 > cmp((char *)base + max * width, (char *)base + left * width))
		max = left;
	if (right < nel
		&& 0 > cmp((char *)base + max * width, (char *)base + right * width))
		max = right;
	if (max != i)
	{
		memswap((char *)base + i * width, (char *)base + max * width, width);
		maxheapify(base, nel, width, max, cmp);
	}
}

static void	maxheapbuild(void *base, size_t nel, size_t width,
				int (*cmp)(const void *, const void *))
{
	int	i;

	i = (nel >> 1) + 1;
	while (--i >= 0)
		maxheapify(base, nel, width, i, cmp);
}

void		ft_heapsort(void *base, size_t nel, size_t width,
				int (*cmp)(const void *, const void *))
{
	int	i;

	maxheapbuild(base, nel, width, cmp);
	i = nel;
	while (--i > 0)
	{
		memswap((char *)base, (char *)base + i * width, width);
		--nel;
		maxheapify(base, nel, width, 0, cmp);
	}
}
