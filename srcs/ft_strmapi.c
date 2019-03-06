/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:16:48 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/15 14:55:42 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str;
	unsigned int	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	*(str + size) = 0x00;
	while (size--)
		*(str + size) = f(size, *(s + size));
	return (str);
}
