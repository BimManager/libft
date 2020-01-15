/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:00:28 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/14 16:19:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intcmp(const void *pv1, const void *pv2)
{
	return (*(int *)pv1 - *(int *)pv2);
}

int			*ft_cntsort(int *arr, size_t n)
{
	int		max;
	int		*tmp;
	int		*ret;
	size_t	i;

	max = *(int *)ft_fndmax(arr, n * sizeof(int), sizeof(int), &intcmp);
	++max;
	tmp = malloc(max * sizeof(int));
	ft_bzero(tmp, max * sizeof(int));
	i = -1;
	while (++i < n)
		tmp[arr[i]] += 1;
	i = 0;
	while (++i < (size_t)max)
		tmp[i] += tmp[i - 1];
	ret = malloc(n * sizeof(int));
	i = n;
	while (i--)
	{
		ret[tmp[arr[i]] - 1] = arr[i];
		tmp[arr[i]] -= 1;
	}
	free(tmp);
	return (ret);
}
