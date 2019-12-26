/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:54:36 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 18:01:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calcexp(long double ldb)
{
	int	exp;

	exp = 0;
	if (!ldb)
		return (exp);
	while (1 > ldb || 10 <= ldb)
	{
		if (1 > ldb)
		{
			--exp;
			ldb *= 10;
			continue;
		}
		++exp;
		ldb /= 10;
	}
	return (exp);
}

static int	ft_eorf(t_format *fmt, long double v)
{
	int			p;
	int			x;
	long double	t;

	if (-1 == fmt->prec)
		p = 6;
	else if (!fmt->prec)
		p = 1;
	else
		p = fmt->prec;
	x = ft_calcexp(v);
	if (p > x && x >= -4)
	{
		fmt->prec = p - (x + 1);
		t = ft_round(v, fmt->prec);
		if (t - v > 1)
			--fmt->prec;
		if ((long)v == v && !fmt->hash)
			fmt->prec = 0;
		return ('f');
	}
	fmt->prec = p - 1;
	return ('e');
}

char		*ft_rmzrs(char *snb, t_format *fmt)
{
	char	*pe;
	char	*px;

	if (1 == ft_strlen(snb))
		return (snb);
	if (!(pe = ft_strchr(snb, 'e')))
	{
		if (!(pe = ft_strchr(snb, '.')))
			return (snb);
		pe = snb + ft_strlen(snb);
		while ('0' == *--pe)
			*pe = '\0';
		if ('.' == *pe && !fmt->hash)
			*pe = '\0';
		return (snb);
	}
	px = pe;
	while ('0' == *--pe)
		;
	if ('.' == *pe && fmt->hash)
		++pe;
	if ((px - pe) > 1)
		ft_strcpy(snb + (pe - snb), px);
	return (snb);
}

char		*ft_gstr(va_list pa, t_format *fmt, const char **sfmt)
{
	long double	v;
	va_list		cpa;
	int			res;
	char		*ret;

	va_copy(cpa, pa);
	v = ft_getldb(pa, fmt);
	res = ft_eorf(fmt, v);
	if ('f' == res)
		ret = ft_fstr(cpa, fmt, sfmt);
	else
		ret = ft_estr(cpa, fmt, sfmt);
	if ((!v && !fmt->prec) || !fmt->hash)
		ft_rmzrs(ret, fmt);
	return (ret);
}
