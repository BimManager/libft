/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:04:48 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/13 12:05:42 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_assert(const char *expr, const char *file, int nline)
{
	ft_putstr("Assertion failed: (");
	ft_putstr(expr);
	ft_putstr("), file ");
	ft_putstr(file);
	ft_putstr(", line ");
	ft_putnbr(nline);
	ft_putstr(".\n");
	exit(1);
}
