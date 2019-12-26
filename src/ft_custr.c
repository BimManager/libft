/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:55:47 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/18 12:57:12 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_custr(va_list pa, t_format *fmt, const char **sfmt)
{
	fmt->length = sizeof(unsigned long);
	return (ft_ustr(pa, fmt, sfmt));
}
