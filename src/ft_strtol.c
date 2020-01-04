/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 13:21:36 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/04 10:32:42 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define OCT	8
#define DEC	10
#define HEX	16

static char	g_digits[] =
{
	['0'] = 0,
	['1'] = 1,
	['2'] = 2,
	['3'] = 3,
	['4'] = 4,
	['5'] = 5,
	['6'] = 6,
	['7'] = 7,
	['8'] = 8,
	['9'] = 9,
	['a'] = 10,
	['b'] = 11,
	['c'] = 12,
	['d'] = 13,
	['e'] = 14,
	['f'] = 15,
	['A'] = 10,
	['B'] = 11,
	['C'] = 12,
	['D'] = 13,
	['E'] = 14,
	['F'] = 15
};

static int	ft_isws(char c)
{
	return (' ' == c || '\t' == c
			|| '\n' == c);
}

static void	ft_sign(const char **str, int *neg)
{
	if ('-' == **str)
		*neg = 1;
	else if ('+' == **str)
		*neg = 0;
	else
		return ;
	++(*str);
}

static void	ft_base(const char **str, int *pbase)
{
	const char	*px;

	if (*pbase)
		return ;
	if ((px = ft_strchr(*str, 'x'))
		|| (px = ft_strchr(*str, 'X')))
	{
		*pbase = HEX;
		*str = ++px;
	}
	else if ('0' == **str)
	{
		*pbase = OCT;
		++(*str);
	}
	else
		*pbase = 10;
}

static int	ft_ishexdigit(char c)
{
	return ('0' <= c && 'f' >= c);
}

long		ft_strtol(const char *str, int base)
{
	long	res;
	int		neg;

	res = 0;
	neg = -1;
	while (ft_isws(*str))
		++str;
	ft_sign(&str, &neg);
	if (!ft_ishexdigit(*str))
		return (res);
	ft_base(&str, &base);
	while (*str && ft_ishexdigit(*str))
	{
		if (res && (LONG_MIN / base > res))
			return (1 == neg ? LONG_MIN : LONG_MAX);
		if (LONG_MIN - res * base >= -8 && g_digits[(int)*str] >= 9)
			return (1 == neg ? LONG_MIN : LONG_MAX);
		res = res * base - g_digits[(int)*str];
		++str;
	}
	if (LONG_MIN == res && -1 == neg)
		return (LONG_MAX);
	return (1 == neg ? res : ~res + 1);
}
