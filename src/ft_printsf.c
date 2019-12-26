/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:52:20 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 11:44:23 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_pfmtfn	g_funcs[] =
{
	[0] = &ft_genstr,
	['1'] = &ft_width,
	['2'] = &ft_width,
	['3'] = &ft_width,
	['4'] = &ft_width,
	['5'] = &ft_width,
	['6'] = &ft_width,
	['7'] = &ft_width,
	['8'] = &ft_width,
	['9'] = &ft_width,
	['b'] = &ft_bstr,
	['c'] = &ft_cstr,
	['d'] = &ft_dstr,
	['e'] = &ft_estr,
	['E'] = &ft_cestr,
	['f'] = &ft_fstr,
	['g'] = &ft_gstr,
	['G'] = &ft_cgstr,
	['i'] = &ft_istr,
	['k'] = &ft_kstr,
	['o'] = &ft_ostr,
	['p'] = &ft_pstr,
	['r'] = &ft_rstr,
	['s'] = &ft_sstr,
	['u'] = &ft_ustr,
	['U'] = &ft_custr,
	['x'] = &ft_xstr,
	['X'] = &ft_cxstr,
	['-'] = &ft_alignflag,
	['+'] = &ft_plusflag,
	[' '] = &ft_spaceflag,
	['0'] = &ft_zeroflag,
	['#'] = &ft_hashflag,
	['%'] = &ft_percent,
	['*'] = &ft_asterisk,
	['.'] = &ft_prec,
	['h'] = &ft_hlength,
	['l'] = &ft_llength,
	['L'] = &ft_cllength,
	['j'] = &ft_jlength,
	['t'] = &ft_tlength,
	['z'] = &ft_zlength,
	['~'] = NULL
};

static int	ft_putnstr_fd(int fd, const char *s, size_t n)
{
	return (write(fd, s, n));
}

static int	ft_xputstr_fd(char *s, int fd, t_format *fmt)
{
	int		n;
	char	*pnull;

	n = ft_strlen(s);
	if (fmt->null)
	{
		pnull = ft_strchr(s, PSEUDO_NULL);
		*pnull = '\0';
	}
	return (ft_putnstr_fd(fd, s, n));
}

int			ft_printsf(int fd, const char **sfmt, va_list pa)
{
	t_format	*fmt;
	char		*str;
	int			check;

	check = 0;
	fmt = ft_formatnew();
	while (**sfmt)
	{
		check = g_funcs[(int)**sfmt] ? **sfmt : 0;
		str = g_funcs[check](pa, fmt, sfmt);
		if (fmt->done && str)
		{
			check = ft_xputstr_fd(str, fd, fmt);
			free(str);
			break ;
		}
		check = 0;
	}
	ft_memdel((void **)&fmt);
	return (check);
}
