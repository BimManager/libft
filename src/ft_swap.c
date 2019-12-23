/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:15:14 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/13 11:57:07 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *pv1, void *pv2, size_t elem_size)
{
	void *buf;

	buf = malloc(elem_size * sizeof(char));
	ft_memcpy(buf, pv1, elem_size);
	ft_memcpy(pv1, pv2, elem_size);
	ft_memcpy(pv2, buf, elem_size);
	free(buf);
}
