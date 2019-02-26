/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:00:05 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/15 17:15:04 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	nchars;
	size_t	copied;

	if (!dst || !src)
		return (0);
	copied = ft_strlen(src);
	if (!dstsize)
		return (copied);
	nchars = dstsize - 1;
	while (*src && nchars--)
		*dst++ = *src++;
	*dst++ = 0x00;
	return (copied);
}
