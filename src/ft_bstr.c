/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:17:21 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/22 15:02:39 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_bstr(va_list pa, t_format *fmt, const char **sfmt)
{
	size_t	*data;
	char	*ret;
	int		nbits;

	++(*sfmt);
	fmt->done = 1;
	data = va_arg(pa, void *);
	nbits = fmt->length * BYTE;
	if (-1 != fmt->prec)
		nbits = fmt->prec;
	if (!ft_nullguard(data, &ret))
	{
		ret = ft_nbitstr(data, nbits);
		ret = ft_fixhash_boxp(ret, fmt, "0b");
	}
	ret = ft_fixwidth(ret, fmt);
	ret = ft_mvhash(ret, fmt, 'b');
	return (ret);
}
