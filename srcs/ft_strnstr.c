/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:55:04 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/14 14:57:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *ret;
	const char *init_needle;

	init_needle = needle;
	while (*(ret = haystack) && len)
	{
		while (len-- && *haystack++ == *needle++)
			if (!*needle)
			  return ((char*)ret);
		needle = init_needle;
	}
	return (0);
}
