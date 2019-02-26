/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:41:38 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/20 10:40:21 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*haystack_itr;
	const char	*needle_itr;
	size_t		init_len;

	if (!*needle)
		return ((char *)haystack);
	needle_itr = needle;
	haystack_itr = haystack;
	init_len = len;
	while (init_len && *haystack)
	{
		while (len-- && *haystack_itr++ == *needle_itr++)
			if (!*needle_itr)
				return ((char *)haystack);
		haystack_itr = ++haystack;
		needle_itr = needle;
		len = --init_len;
	}
	return (0);
}
