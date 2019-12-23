/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:22:15 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/15 16:25:33 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		real_len;
	char		*str;
	char		*ret;

	if (!s)
		return (0);
	real_len = ft_strlen(s);
	if (start >= real_len ||
		(start + len) > real_len)
		return (0);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ret = str;
	while (len--)
	{
		*str++ = *(s + start);
		++s;
	}
	*str = 0x00;
	return (ret);
}
