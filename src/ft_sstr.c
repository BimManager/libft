/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:40:53 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 16:10:07 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fixprec_s(char *str, t_format *fmt, int null)
{
	int		nch;
	char	*ret;

	nch = (-1 == fmt->prec) ? ft_strlen(str) : fmt->prec;
	ret = malloc((nch + 1) * sizeof(char));
	ft_strncpy(ret, str, nch);
	*(ret + nch) = '\0';
	if (null)
		free(str);
	return (ret);
}

char		*ft_sstr(va_list pa, t_format *fmt, const char **sfmt)
{
	char	*ret;
	int		null;

	ret = va_arg(pa, char *);
	null = ft_nullguard(ret, &ret);
	ret = ft_fixprec_s(ret, fmt, null);
	ret = ft_fixwidth(ret, fmt);
	fmt->done = 1;
	++(*sfmt);
	return (ret);
}
