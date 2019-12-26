/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:06:26 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/05 15:39:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	g_oct_digits[] = { '0', '1', '2', '3', '4', '5', '6', '7' };

char	*ft_octstr(const void *pnb, size_t size)
{
	return (ft_radstr(pnb, size, g_oct_digits,
				sizeof(g_oct_digits) / sizeof(g_oct_digits[0])));
}
