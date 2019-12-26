/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldbstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:26:54 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/21 13:18:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_xfrcstr(long double db, size_t prc)
{
	char	*ret;
	char	*it;
	char	dg;

	ret = malloc((prc + 2) * sizeof(char));
	it = ret;
	if (prc)
		*it++ = '.';
	while (prc--)
	{
		dg = db * 10;
		db = db * 10 - dg;
		*it++ = dg + '0';
	}
	*it = '\0';
	return (ret);
}

char		*ft_ldbstr(const void *pnb, size_t prec)
{
	long		tmp;
	char		*dec;
	char		*ret;
	long double	ldb;

	ldb = *(long double *)pnb;
	ldb = ft_round(ldb, prec);
	tmp = ldb;
	dec = ft_decstr(&tmp, sizeof(size_t));
	if (ldb < 0)
		ldb *= -1;
	tmp = ft_strlen(dec);
	ret = malloc((tmp + prec + 2) * sizeof(char));
	ft_strncpy(ret, dec, tmp);
	free(dec);
	dec = ft_xfrcstr(ldb - (long)ldb, prec);
	ft_strncpy(ret + tmp, dec, ft_strlen(dec) + 1);
	free(dec);
	return (ret);
}
