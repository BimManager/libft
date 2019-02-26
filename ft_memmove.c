/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:12:46 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/15 09:48:06 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*itr_d;
	const char	*itr_s;

	if (dst < src)
	{
		itr_d = (char *)dst;
		itr_s = (const char *)src;
		while (len--)
			*itr_d++ = *itr_s++;
	}
	else
	{
		itr_d = (char *)dst + len - 1;
		itr_s = (const char *)src + len - 1;
		while (len--)
			*itr_d-- = *itr_s--;
	}
	return (dst);
}
