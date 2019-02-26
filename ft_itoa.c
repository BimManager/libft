/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:35:43 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/16 11:19:10 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cdigits(int n)
{
	size_t ndigits;

	ndigits = 1;
	if (n < 0)
		++ndigits;
	while ((n = n / 10))
		++ndigits;
	return (ndigits);
}

static void		ft_itoa_it(char **nb, unsigned int n)
{
	if (n > 9)
		ft_itoa_it(nb, n / 10);
	*(*nb)++ = (n % 10) + '0';
}

char			*ft_itoa(int n)
{
	char			*itr;
	char			*ret;
	unsigned int	unb;

	ret = malloc((ft_cdigits(n) + 1) * sizeof(char));
	if (!ret)
		return (0);
	itr = ret;
	unb = n;
	if (n < 0)
	{
		*itr++ = '-';
		unb = -n;
	}
	ft_itoa_it(&itr, unb);
	*itr = 0x00;
	return (ret);
}
