/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:09:46 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/05 15:38:54 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	g_dec_digits[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

char	*ft_decstr(const void *pnb, size_t size)
{
	return (ft_radstr(pnb, size, g_dec_digits,
				sizeof(g_dec_digits) / sizeof(g_dec_digits[0])));
}
