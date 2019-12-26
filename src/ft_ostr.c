/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:36:58 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 10:47:10 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ostr(va_list pa, t_format *fmt, const char **sfmt)
{
	size_t	nb;
	char	*ret;

	nb = va_arg(pa, size_t);
	if (!nb && !fmt->prec && !fmt->hash)
		ret = ft_strdup("");
	else
	{
		if (!nb)
			fmt->hash = 0;
		ret = ft_octstr(&nb, fmt->length);
	}
	ret = ft_fixhash_boxp(ret, fmt, "0");
	ret = ft_fixprec_dioux(ret, fmt);
	ret = ft_fixwidth(ret, fmt);
	++(*sfmt);
	fmt->done = 1;
	return (ret);
}
