/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:05:26 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/23 15:36:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Heap's algorithm generates all possible
**	permutations of n objects.
*/

static void	generate(int **tab, int *arr, int n, int k)
{
	int			i;
	static int	c;

	if (1 == k)
	{
		ft_memcpy(tab[c++], arr, n * sizeof(int));
		return ;
	}
	generate(tab, arr, n, k - 1);
	i = -1;
	while (++i < k - 1)
	{
		if (0 == k % 2)
			ft_swap(&arr[i], &arr[k - 1], sizeof(int));
		else
			ft_swap(&arr[0], &arr[k - 1], sizeof(int));
		generate(tab, arr, n, k - 1);
	}
}

int			**ft_permute(int *nums, int nsize, int *outsize, int **outcsizes)
{
	int		**ret;
	size_t	size;
	size_t	i;

	size = ft_fac(nsize);
	*outsize = size;
	*outcsizes = malloc(size * sizeof(int));
	ret = malloc(size * sizeof(void *));
	i = -1;
	while (++i < size)
	{
		ret[i] = malloc(nsize * sizeof(int));
		(*outcsizes)[i] = nsize;
	}
	generate(ret, nums, nsize, nsize);
	return (ret);
}
