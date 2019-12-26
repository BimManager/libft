/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:39:05 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 13:27:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_xstr(va_list pa, t_format *fmt, const char **sfmt)
{
	size_t	nb;
	char	*ret;

	nb = va_arg(pa, size_t);
	if (!nb)
		fmt->hash = 0;
	if (fmt->prec)
		ret = ft_hexstr(&nb, fmt->length);
	else
		ret = ft_strdup("");
	ret = ft_fixprec_dioux(ret, fmt);
	ret = ft_fixhash_boxp(ret, fmt, "0x");
	ret = ft_fixwidth(ret, fmt);
	ret = ft_mvhash(ret, fmt, 'x');
	++(*sfmt);
	fmt->done = 1;
	return (ret);
}
