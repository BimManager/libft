/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaceflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 10:07:22 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/09 09:13:54 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spaceflag(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	++(*sfmt);
	fmt->space = 1;
	return (NULL);
}
