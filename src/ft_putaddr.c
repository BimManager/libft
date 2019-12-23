/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:22:12 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/08 16:28:12 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr(size_t addr)
{
	const char	base[] = "0123456789abcdef";
	size_t		mask;
	size_t		mv;

	mask = 0b1111UL << (sizeof(mask) * BYTE - BYTE / 2);
	mv = sizeof(addr) * (BYTE / 4);
	ft_putstr("0x");
	while ((addr & mask) == 0)
	{
		--mv;
		mask >>= (BYTE / 2);
	}
	while (mask)
	{
		--mv;
		ft_putchar(base[((addr & mask) ?
			(addr & mask) >> (mv * (BYTE / 2)) : 0)]);
		mask >>= (BYTE / 2);
	}
}
