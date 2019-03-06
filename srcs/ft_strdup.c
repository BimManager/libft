/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:42:33 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/01 10:27:30 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	dstsize;

	dstsize = ft_strlen(s1) + 1;
	s2 = malloc(dstsize);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, dstsize);
	return (s2);
}
