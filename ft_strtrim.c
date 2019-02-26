/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:26:51 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/15 16:06:23 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_slen(char const *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		++len;
	if (!len)
		return (len);
	s -= 2;
	while (len && ft_iswhitespace(*s--))
		--len;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char		*out;
	size_t		len;

	if (!s)
		return (0);
	while (*s && ft_iswhitespace(*s))
		++s;
	len = ft_slen(s);
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (0);
	ft_strncpy(out, s, len);
	*(out + len) = 0x00;
	return (out);
}
