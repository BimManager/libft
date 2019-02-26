/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:15:28 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/15 16:04:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char *str;
	char *itr;

	if (!s)
		return (0);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	itr = str;
	while (*s)
		*itr++ = f(*s++);
	*itr = 0x00;
	return (str);
}
