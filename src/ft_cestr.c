/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cestr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:41:07 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 17:13:07 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cestr(va_list pa, t_format *fmt, const char **sfmt)
{
	char	*ret;

	ret = ft_estr(pa, fmt, sfmt);
	ft_strupcase(ret);
	return (ret);
}
