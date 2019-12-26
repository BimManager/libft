/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cgstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:43:23 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 11:44:12 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cgstr(va_list pa, t_format *fmt, const char **sfmt)
{
	char	*ret;

	ret = ft_gstr(pa, fmt, sfmt);
	ft_strupcase(ret);
	return (ret);
}
