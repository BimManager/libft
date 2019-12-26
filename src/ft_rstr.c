/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:06:59 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/17 14:23:27 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define NONPRINT_LEN	4

static char	*g_nonprint[] = {
	"\\nul", "\\soh", "\\stx",
	"\\etx", "\\eot",
	"\\enq", "\\ack", "\\bel",
	"\\bs", "\\ht", "\\nl",
	"\\vt", "\\np", "\\cr",
	"\\so", "\\si", "\\dle",
	"\\dc1", "\\dc2", "\\dc3",
	"\\dcNONPRINT_LEN", "\\nak", "\\syn",
	"\\etb", "\\can", "\\em",
	"\\sub", "\\esc", "\\fs",
	"\\gs", "\\rs", "\\us",
	[0177] = "\\del"
};

static int	ft_count_nonprint(const char *s)
{
	int	ret;

	ret = 1;
	while (*s)
		if (!ft_isprint(*s++))
			++ret;
	return (ret);
}

static char	*ft_cvtnonprint(const char *s)
{
	char	*ret;
	char	*it;
	char	*v;
	int		n;

	n = ft_count_nonprint(s);
	ret = malloc((ft_strlen(s) + NONPRINT_LEN * n + 1) * sizeof(char));
	it = ret;
	while (*s)
	{
		if (ft_isprint(*s))
			*it++ = *s++;
		else if ((v = g_nonprint[(int)*s++]))
		{
			n = ft_strlen(v);
			ft_strncpy(it, v, n);
			it += n;
		}
	}
	ft_strncpy(it, g_nonprint['\0'], NONPRINT_LEN);
	it += NONPRINT_LEN;
	*it = '\0';
	return (ret);
}

static char	*ft_fixsprec(char *str, t_format *fmt)
{
	int		nch;
	char	*ret;

	nch = (-1 == fmt->prec) ? ft_strlen(str) : fmt->prec;
	ret = malloc((nch + 1) * sizeof(char));
	ft_strncpy(ret, str, nch);
	*(ret + nch) = '\0';
	return (ret);
}

char		*ft_rstr(va_list pa, t_format *fmt, const char **sfmt)
{
	char	*str;
	char	*ret;

	str = va_arg(pa, char *);
	ret = ft_cvtnonprint(str);
	ret = ft_fixsprec(ret, fmt);
	ret = ft_fixwidth(ret, fmt);
	fmt->done = 1;
	++(*sfmt);
	return (ret);
}
