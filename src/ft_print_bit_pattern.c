/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit_pattern.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:36:57 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/04 10:29:06 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print_bits(unsigned char byte)
{
	unsigned char	pattern;
	size_t			i;

	pattern = 1;
	pattern <<= 7;
	i = -1;
	while (++i < BYTE)
		((pattern >> i) & byte) == 0 ? ft_putchar('0') : ft_putchar('1');
}

void			ft_print_bit_pattern(void *pv, size_t elem_size)
{
	size_t	i;

	i = elem_size;
	while (i--)
	{
		ft_print_bits(*((char*)pv + i));
		ft_putchar(' ');
	}
}
