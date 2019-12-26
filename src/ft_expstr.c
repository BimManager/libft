/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 09:41:34 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 14:37:00 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calcexp(long double ldb)
{
	int	exp;

	exp = 0;
	if (!ldb)
		return (exp);
	while (1 > ldb || 10 <= ldb)
	{
		if (1 > ldb)
		{
			--exp;
			ldb *= 10;
			continue;
		}
		++exp;
		ldb /= 10;
	}
	return (exp);
}

static char	*ft_exptostr(int exp)
{
	char	*ret;
	char	*ds;
	int		len;

	ret = malloc(5 * sizeof(char));
	ft_strncpy(ret, "e", 1);
	ft_strncpy(ret + 1, 0 > exp ? "-" : "+", 1);
	if (0 > exp)
		exp *= -1;
	ds = ft_decstr(&exp, sizeof(int));
	len = ft_strlen(ds);
	if (1 < len)
		ft_strcpy(ret + 2, ds);
	else
	{
		ft_strncpy(ret + 2, "0", 1);
		ft_strcpy(ret + 3, ds);
	}
	free(ds);
	return (ret);
}

static void	ft_fixrounding(char *str, int *exp)
{
	char	*pdp;

	if ((pdp = ft_strchr(str, '.')) || (!pdp && 1 < ft_strlen(str)))
	{
		if (pdp && (pdp - str) > 1)
		{
			ft_swap(str + 1, pdp, 1);
			*(str + ft_strlen(str) - 1) = '\0';
			++*exp;
		}
		else if (!pdp)
		{
			*(str + 1) = '\0';
			++*exp;
		}
	}
}

char		*ft_expstr(const void *pnb, size_t prec)
{
	long double	ldb;
	char		*ret;
	char		*tmp;
	int			exp;

	ldb = *(long double *)pnb;
	exp = ft_calcexp(ldb);
	if (exp > 0)
		ldb /= ft_powl(10, exp);
	else
		ldb *= ft_powl(10, -exp);
	tmp = ft_ldbstr(&ldb, prec);
	ret = malloc((ft_strlen(tmp) + 5) * sizeof(char));
	ft_strcpy(ret, tmp);
	free(tmp);
	ft_fixrounding(ret, &exp);
	tmp = ft_exptostr(exp);
	ft_strcpy(ret + ft_strlen(ret), tmp);
	free(tmp);
	return (ret);
}
