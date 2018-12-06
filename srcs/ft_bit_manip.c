/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:34:44 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/14 15:09:18 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BYTE 8

void	ft_set_bit(void *pv, unsigned int elem_size, unsigned int bit_pos)
{
	if (bit_pos > elem_size * BYTE)
		return ;
	*((char*)pv + bit_pos / BYTE) |= 1 << (bit_pos % BYTE);
}

void	ft_zero_bit(void *pv, unsigned int elem_size, unsigned int bit_pos)
{
	if (bit_pos > elem_size * BYTE)
		return ;
	*((char*)pv + bit_pos / BYTE) &= ~(1 << (bit_pos % BYTE));
}

int		ft_test_bit(void *pv, unsigned int elem_size, unsigned int bit_pos)
{
	if (bit_pos > elem_size * BYTE)
		return (0);
	if (*((char*)pv + bit_pos / BYTE) & (1 << (bit_pos % BYTE)))
		return (1);
	return (0);
}

void	ft_reverse_bits(void *pv, unsigned int elem_size)
{
	unsigned int i;

	i = -1;
	while (++i < elem_size * BYTE / 2)
		if ((*((char*)pv + i / BYTE) & (1 << i % BYTE)))
		{
			ft_set_bit(pv, elem_size, elem_size * BYTE - i - 1);
			ft_zero_bit(pv, elem_size, i);
		}
}
