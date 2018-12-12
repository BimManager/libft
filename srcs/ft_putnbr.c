/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 08:24:05 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/11 12:12:00 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int unb;

	if (nb < 0)
	{
		ft_putchar('-');
		unb = -nb;
	}
	else
		unb = nb;
	if (unb <= 9)
		ft_putchar(unb + '0');
	else
	{
		ft_putnbr(unb / 10);
		ft_putchar(unb % 10 + '0');
	}
}
