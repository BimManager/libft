/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:55:04 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/16 11:46:50 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *ret;
	const char *init_needle;

	if (!*needle)
		return ((char *)haystack);
	init_needle = needle;
	ret = haystack;
	while (*ret)
	{
		haystack = ret;
		while (*haystack && *haystack++ == *needle++)
			if (!*needle)
				return ((char *)ret);
		needle = init_needle;
		++ret;
	}
	return (0);
}
