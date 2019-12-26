/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 10:05:04 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/09 15:42:11 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_alignflag(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	++(*sfmt);
	fmt->align = 1;
	return (NULL);
}
