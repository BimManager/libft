/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:21:33 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/14 15:49:09 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char *const g_base = "0123456789abcdef";

static size_t		ft_count_digits(int value, int base)
{
	size_t	i;
	size_t	uval;

	i = 1;
	if (value < 0)
	{
		if (base == 10)
			++i;
		else
			return (0);
	}
	uval = ft_abs(value);
	while ((uval /= base) > 0)
		++i;
	return (i);
}

char				*ft_itoa_base(int value, int base)
{
	char			*out;
	size_t			uval;
	size_t			digits;

	digits = ft_count_digits(value, base);
	out = malloc((digits + 1) * sizeof(char));
	out[digits] = 0x00;
	if (!out)
		return (0);
	if (value < 0 && base == 10)
		out[0] = '-';
	else if (value == 0)
		out[0] = '0';
	uval = ft_abs(value);
	while (uval)
	{
		*(out + --digits) = *(g_base + uval % base);
		uval /= base;
	}
	return (out);
}
