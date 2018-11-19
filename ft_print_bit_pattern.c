/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit_pattern.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:36:57 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/14 15:13:02 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

#define BYTE 8

void	ft_print_bits(unsigned char byte)
{
	unsigned char	pattern;
	int				i;

	pattern = 1;
	pattern <<= 7;
	i = -1;
	while (++i < BYTE)
	{
		((pattern >> i) & byte) == 0 ? ft_putchar('0') : ft_putchar('1');
	}
}

void	ft_print_bit_pattern(void *pv, unsigned int elem_size)
{
	int i;

	i = -1;
	while ((unsigned int)(++i) < elem_size)
	{
		ft_print_bits(*((char*)pv + i));
		ft_putchar(' ');
	}
}
