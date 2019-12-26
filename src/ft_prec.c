/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:34:32 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 14:57:36 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_prec(va_list pa, t_format *fmt, const char **sfmt)
{
	int	prec;

	++(*sfmt);
	if ('*' == **sfmt)
	{
		prec = va_arg(pa, int);
		if (0 <= prec)
			fmt->prec = prec;
		++(*sfmt);
	}
	else
		fmt->prec = ft_fmtnb(sfmt);
	return (NULL);
}
