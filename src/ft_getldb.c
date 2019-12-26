/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getldb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:32:15 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 11:32:50 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_getldb(va_list pa, t_format *fmt)
{
	t_ext80	ext80;
	double	db;

	if (sizeof(long double) == fmt->length)
		ext80.value = va_arg(pa, long double);
	else
	{
		db = va_arg(pa, double);
		ext80.value = db;
	}
	if (ext80.bits.sign)
	{
		fmt->neg = 1;
		ext80.value *= -1;
	}
	return (ext80.value);
}
