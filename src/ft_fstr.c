/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:31:29 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/21 12:36:40 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fixfhash(char *str, t_format *fmt)
{
	char	*ret;
	int		len;

	if (!fmt->hash || fmt->prec)
		return (str);
	len = ft_strlen(str);
	ret = malloc((len + 2) * sizeof(char));
	ft_strcpy(ret, str);
	*(ret + len) = '.';
	*(ret + len + 1) = '\0';
	free(str);
	return (ret);
}

char		*ft_fstr(va_list pa, t_format *fmt, const char **sfmt)
{
	char		*ret;

	ret = ft_feg(pa, fmt, sfmt, &ft_ldbstr);
	if (ft_strcmp(ret, "nan"))
	{
		ret = ft_fixsign(ret, fmt);
		ret = ft_fixfhash(ret, fmt);
	}
	ret = ft_fixwidth(ret, fmt);
	ret = ft_mvsign(ret, fmt);
	return (ret);
}
