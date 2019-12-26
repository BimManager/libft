/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvtarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:55:27 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/09 14:55:50 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_cvtarg(va_list pa, t_format *fmt)
{
	size_t	res;

	if (fmt->length == sizeof(long))
		res = va_arg(pa, long);
	else if (fmt->length == sizeof(long long))
		res = va_arg(pa, long long);
	else
		res = va_arg(pa, int);
	return (res);
}
