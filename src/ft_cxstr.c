/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cxstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:58:02 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/11 11:52:22 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cxstr(va_list pa, t_format *fmt, const char **sfmt)
{
	char	*ret;

	ret = ft_xstr(pa, fmt, sfmt);
	ft_strupcase(ret);
	return (ret);
}
