/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:52:14 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/16 12:55:33 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_fac(t_uint16 n)
{
	t_uint16	i;
	size_t		res;

	i = 0;
	res = 1;
	while (++i <= n)
		res *= i;
	return (res);
}