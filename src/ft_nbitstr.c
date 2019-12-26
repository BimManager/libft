/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbitstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:51:14 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/25 17:31:15 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nbitstr(const void *pv, size_t nbits)
{
	char	*ret;
	char	*it;
	int		i;
	int		mask;

	ret = malloc((nbits + 1) * sizeof(char));
	*(ret + nbits) = '\0';
	it = ret;
	i = (nbits - 1) / BYTE + 1;
	while (i--)
	{
		mask = BYTE;
		while (mask--)
			*it++ = (*((char *)pv + i) >> mask & 1) + '0';
	}
	return (ret);
}
