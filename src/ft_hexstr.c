/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:13:38 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 15:44:23 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	g_hex_digits[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f' };

char		*ft_hexstr(const void *pnb, size_t size)
{
	return (ft_radstr(pnb, size, g_hex_digits,
				sizeof(g_hex_digits) / sizeof(g_hex_digits[0])));
}
