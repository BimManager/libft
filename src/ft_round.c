/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:30:47 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 18:02:17 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	g_powers_of_ten[] = {
	1, 10, 100, 1000, 10000, 100000,
	1000000, 10000000, 100000000
};

static long double	ft_frcround(long double frc, int prec)
{
	long		dec;
	long double	frcfrc;

	if (NSIN >= prec)
	{
		frc *= g_powers_of_ten[prec];
		frc += 0.5;
		return (frc / g_powers_of_ten[prec]);
	}
	dec = (long)(frc * g_powers_of_ten[prec]);
	frcfrc = (long double)dec / g_powers_of_ten[NSIN];
	return (frcfrc + ft_frcround((frc - frcfrc) *
		g_powers_of_ten[NSIN], prec - NSIN) / g_powers_of_ten[NSIN]);
}

long double			ft_round(long double ldb, int prec)
{
	int			neg;

	if (!ldb)
		return (ldb);
	neg = 0;
	if (ldb < 0)
	{
		neg = 1;
		ldb *= -1;
	}
	ldb = (long)ldb + ft_frcround(ldb - (long)ldb, prec);
	if (neg)
		ldb *= -1;
	return (ldb);
}
