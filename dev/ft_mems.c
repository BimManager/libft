/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:35:59 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/13 16:39:44 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	*ft_memcpy(void *dest, void *src, unsigned int count)
{
	unsigned int	i;
	unsigned char	*buf;

	if ((char*)dest == (char*)src || !(char*)dest
		|| !(char*)src || !count)
		return (dest);
	buf = malloc(count * sizeof(char));
	if (!buf)
		return (dest);
	i = -1;
	while (++i < count)
		*(buf + i) = *((unsigned char*)src + i);
	i = -1;
	while (++i < count)
		*((char*)dest + i) = *(buf + i);
	free(buf);
	return (dest);
}

int		ft_memcmp(void *lhs, void *rhs, unsigned int count)
{
	unsigned int i;

	i = 0;
	while (i < count)
	{
		if (*((char*)lhs + i) != *((char*)rhs + i))
			return (*((char*)lhs + i) - *((char*)rhs + i));
		++i;
	}
	return (0);
}
