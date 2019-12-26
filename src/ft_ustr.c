/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:56:26 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 09:36:34 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ustr(va_list pa, t_format *fmt, const char **sfmt)
{
	size_t	unb;
	char	*ret;

	++(*sfmt);
	unb = va_arg(pa, size_t);
	if (!unb && !fmt->prec)
		ret = ft_strdup("");
	else
		ret = ft_decstr(&unb, fmt->length);
	ret = ft_fixprec_dioux(ret, fmt);
	ret = ft_fixwidth(ret, fmt);
	fmt->done = 1;
	return (ret);
}
