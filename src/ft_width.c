/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:32:51 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 15:01:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_width(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	fmt->width = ft_fmtnb(sfmt);
	return (NULL);
}
