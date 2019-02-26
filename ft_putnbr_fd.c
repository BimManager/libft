/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:42:58 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/12 17:45:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_fd_it(unsigned int un, int fd)
{
	if (un <= 9)
		ft_putchar_fd(un + '0', fd);
	else
	{
		ft_putnbr_fd_it(un / 10, fd);
		ft_putchar_fd(un % 10 + '0', fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int unb;

	unb = n;
	if (n < 0)
	{
		unb = -n;
		ft_putchar_fd('-', fd);
	}
	ft_putnbr_fd_it(unb, fd);
}
