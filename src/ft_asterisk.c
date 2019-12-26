/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:31:25 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/18 14:16:40 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_asterisk(va_list pa, t_format *fmt, const char **sfmt)
{
	int	v;

	v = va_arg(pa, int);
	if (0 > v)
	{
		fmt->align = 1;
		v = ~v + 1;
	}
	fmt->width = v;
	++(*sfmt);
	return (NULL);
}
