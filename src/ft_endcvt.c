/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endcvt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:50:46 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/21 09:28:37 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memrev(void *pv, size_t size)
{
	char	*bp;
	char	*ep;

	bp = pv;
	ep = bp + size;
	while (ep > bp)
		ft_swap(bp++, --ep, sizeof(char));
}

void		ft_endcvt(void *pv, size_t width, size_t nel)
{
	size_t	i;

	i = -1;
	while (++i < nel)
		ft_memrev((char *)pv + i * width, width);
}
