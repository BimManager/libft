/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:52:01 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/16 15:10:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	pa;
	int		n;

	va_start(pa, fmt);
	n = ft_xprintf(fd, fmt, pa);
	va_end(pa);
	return (n);
}
