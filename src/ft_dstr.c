/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:02:11 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 13:22:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_dstr(va_list pa, t_format *fmt, const char **sfmt)
{
	char	*ret;
	size_t	dec;

	dec = ft_cvtarg(pa, fmt);
	if (!dec)
		fmt->hash = 0;
	if (dec >> (fmt->length * BYTE - 1) & 1)
	{
		dec *= -1;
		fmt->neg = 1;
	}
	if (!dec && !fmt->prec)
		ret = ft_strdup("");
	else
		ret = ft_decstr(&dec, fmt->length);
	ret = ft_fixprec_dioux(ret, fmt);
	ret = ft_fixsign(ret, fmt);
	ret = ft_fixwidth(ret, fmt);
	ret = ft_mvsign(ret, fmt);
	fmt->done = 1;
	++(*sfmt);
	return (ret);
}
