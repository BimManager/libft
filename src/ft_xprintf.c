/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:03:57 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 13:33:47 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_xprintf(int fd, const char *fmt, va_list pa)
{
	int	n;

	n = 0;
	while (*fmt)
	{
		if ('%' == *fmt)
		{
			++fmt;
			n += ft_printsf(fd, &fmt, pa);
		}
		else
			n += write(fd, fmt++, sizeof(char));
	}
	return (n);
}
