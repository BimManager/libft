/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:45:14 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/15 16:02:59 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*itr_dst;
	size_t	nchars;
	size_t	init_len;

	itr_dst = dst;
	nchars = dstsize - ft_strlen(dst) - 1;
	init_len = ft_strlen(dst) + ft_strlen(src);
	if (dstsize == 0 || (size_t)ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (*itr_dst)
		++itr_dst;
	while (*src && nchars--)
		*itr_dst++ = *src++;
	*itr_dst = 0x00;
	return (init_len);
}
