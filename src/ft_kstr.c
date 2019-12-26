/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:24:49 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 14:11:59 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define DATE_FMT_LEN	10

static void	ft_copy_date(char *dst, const char *src, size_t n)
{
	if (ft_strlen(src) < 2)
		ft_strncpy(dst + 1, src, n - 1);
	else
		ft_strncpy(dst, src, n);
}

static char	*ft_fmtdate(struct tm *date)
{
	char	*ret;
	int		nb;
	char	*str;

	ret = malloc((DATE_FMT_LEN + 1) * sizeof(char));
	ft_strcpy(ret, "0000-00-00");
	nb = date->tm_year + 1900;
	str = ft_decstr(&nb, sizeof(int));
	ft_strncpy(ret, str, 4);
	free(str);
	nb = date->tm_mon;
	str = ft_decstr(&nb, sizeof(int));
	ft_copy_date(ret + 5, str, 2);
	free(str);
	nb = date->tm_mday;
	str = ft_decstr(&nb, sizeof(int));
	ft_copy_date(ret + 8, str, 2);
	free(str);
	return (ret);
}

char		*ft_kstr(va_list pa, t_format *fmt, const char **sfmt)
{
	char		*ret;
	struct tm	*date;
	char		*null;

	date = va_arg(pa, void *);
	if (ft_nullguard(date, &null))
		ret = null;
	else
		ret = ft_fmtdate(date);
	ret = ft_fixwidth(ret, fmt);
	fmt->done = 1;
	++(*sfmt);
	return (ret);
}
