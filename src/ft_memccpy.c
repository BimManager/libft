/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:59:47 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/12 15:08:23 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
	{
		if (*((unsigned char*)src + i) == (unsigned char)c)
		{
			*((unsigned char*)dst + i) = (unsigned char)c;
			return ((char*)dst + ++i);
		}
		*((char*)dst + i) = *((char*)src + i);
	}
	return (0);
}
