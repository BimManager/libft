/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:35:14 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/18 13:01:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hlength(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	if (sizeof(int) >= (size_t)fmt->length)
	{
		fmt->length = sizeof(short);
		if (**sfmt == *(*sfmt + 1))
		{
			fmt->length = sizeof(char);
			++(*sfmt);
		}
	}
	++(*sfmt);
	return (NULL);
}
