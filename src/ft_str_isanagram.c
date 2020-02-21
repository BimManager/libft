/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isanagram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:22:23 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/21 09:24:31 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef BUFF_SIZE
# undef BUFF_SIZE
#endif

#define BUFF_SIZE	255

int	ft_str_isanagram(const char *s1, const char *s2)
{
	char	buffer[BUFF_SIZE];
	int		i;

	i = -1;
	while (++i < BUFF_SIZE)
		buffer[i] = 0;
	while (*s1)
		buffer[(int)*s1++] += 1;
	while (*s2)
		buffer[(int)*s2++] -= 1;
	i = -1;
	while (++i < BUFF_SIZE)
		if (buffer[i])
			return (0);
	return (1);
}
