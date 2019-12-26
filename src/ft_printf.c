/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:23:48 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/16 15:10:38 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	pa;
	int		n;

	va_start(pa, fmt);
	n = ft_xprintf(1, fmt, pa);
	va_end(pa);
	return (n);
}
