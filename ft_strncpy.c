/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:35:48 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/15 10:02:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*itr_dst;

	itr_dst = dst;
	while (*src && len)
	{
		*itr_dst++ = *src++;
		--len;
	}
	while (len--)
		*itr_dst++ = 0x00;
	return (dst);
}
