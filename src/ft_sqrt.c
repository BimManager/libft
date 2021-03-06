/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:16:40 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/12 14:35:37 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double x)
{
	double	a;
	double	b;

	if (x < 0)
		return (-1);
	a = 1;
	while ((b = (a + x / a) / 2))
	{
		if (b == a)
			break ;
		a = b;
	}
	return (a);
}
