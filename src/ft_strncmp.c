/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:22:13 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/19 16:06:46 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *us1;
	const unsigned char *us2;

	if (!n)
		return (0);
	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	while (*us1 && n--)
		if (*us1++ != *us2++)
			return (*--us1 - *--us2);
	if (!n)
		return (*--us1 - *--us2);
	return (*us1 - *us2);
}
