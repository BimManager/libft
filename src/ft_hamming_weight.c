/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hamming_weight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 08:53:01 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/30 09:00:03 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hamming_weight(const void *pv, size_t elem_size)
{
	int	bits;
	int	res;

	bits = BYTE * elem_size;
	res = 0;
	while (elem_size--)
	{
		bits = BYTE;
		while (bits--)
			if (*((char *)pv + elem_size) & (1 << bits))
				++res;
	}
	return (res);
}
