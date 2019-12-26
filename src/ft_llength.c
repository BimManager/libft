/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:39:33 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/17 16:06:30 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_llength(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	fmt->length = sizeof(long);
	if (**sfmt == *(*sfmt + 1))
	{
		fmt->length = sizeof(long long);
		++(*sfmt);
	}
	++(*sfmt);
	return (NULL);
}
