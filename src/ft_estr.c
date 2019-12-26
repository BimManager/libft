/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_estr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 09:31:45 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/17 14:13:32 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fixehash(char *str, t_format *fmt)
{
	char	*pe;
	char	*ret;

	if (!fmt->hash && fmt->length)
		return (str);
	pe = ft_strchr(str, 'e');
	if (!pe)
		return (str);
	ret = malloc((ft_strlen(str) + 2) * sizeof(char));
	ft_strncpy(ret, str, pe - str);
	*(ret + (pe - str)) = '.';
	ft_strcpy(ret + (pe - str) + 1, pe);
	free(str);
	return (ret);
}

char		*ft_estr(va_list pa, t_format *fmt, const char **sfmt)
{
	char		*ret;

	ret = ft_feg(pa, fmt, sfmt, &ft_expstr);
	if (ft_strcmp(ret, "nan"))
	{
		ret = ft_fixsign(ret, fmt);
		ret = ft_fixehash(ret, fmt);
	}
	ret = ft_fixwidth(ret, fmt);
	return (ret);
}
