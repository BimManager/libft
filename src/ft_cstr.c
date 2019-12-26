/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:23:48 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 09:07:40 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cstr(va_list pa, t_format *fmt, const char **sfmt)
{
	char	*ret;
	char	ch;

	++(*sfmt);
	fmt->done = 1;
	ch = va_arg(pa, int);
	if (!ch)
	{
		fmt->null = 1;
		ch = PSEUDO_NULL;
	}
	ret = malloc(2 * sizeof(char));
	*ret = (char)ch;
	*(ret + 1) = '\0';
	ret = ft_fixwidth(ret, fmt);
	return (ret);
}
