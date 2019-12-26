/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:17:14 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 15:41:26 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_pstr(va_list pa, t_format *fmt, const char **sfmt)
{
	void	*pv;
	char	*hex;
	char	*ret;

	pv = va_arg(pa, void *);
	if (!pv && !fmt->prec)
		hex = ft_strdup("");
	else
		hex = ft_hexstr(&pv, sizeof(void *));
	fmt->hash = 1;
	ret = ft_fixprec_dioux(hex, fmt);
	ret = ft_fixhash_boxp(ret, fmt, "0x");
	ret = ft_fixwidth(ret, fmt);
	ret = ft_mvhash(ret, fmt, 'x');
	fmt->done = 1;
	++(*sfmt);
	return (ret);
}
