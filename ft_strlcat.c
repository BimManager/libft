/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:45:14 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/11 16:34:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int		dlen;
	int		slen;
	int		max;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	max = size - dlen - 1;
	dest += dlen;
	if (max <= 0)
		return (size + slen);
	while (max--)
		*dest++ = *src++;
	*dest = '\0';
	return (dlen + slen);
}
