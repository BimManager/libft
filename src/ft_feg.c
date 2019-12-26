/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:16:42 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 11:36:08 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_feg(va_list pa, t_format *fmt, const char **sfmt,
				char *(*pfn)(const void *pnb, size_t prec))
{
	long double	v;
	char		*ret;

	++(*sfmt);
	fmt->done = 1;
	v = ft_getldb(pa, fmt);
	if (!(ret = ft_infnan(v)))
		ret = pfn(&v, -1 != fmt->prec ? fmt->prec : 6);
	return (ret);
}
