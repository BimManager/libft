/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:14:23 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/15 15:53:08 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		ft_del_substr(char *str, char const *substr)
{
	char const *needle;
	char *change;
	
	if (!str || !*str || !substr || !*substr)
		return (0);
	needle = substr;
	while (*(change = str))
	{
		while (*str++ == *substr++)
		{
			if (!*substr)
			{
				while (*str)
					*change++ = *str++;
				*change = 0x00;
				return (1);
			}
//			else if (!*str)
//				return (0);
		}
		substr = needle;
	}
	return (0);
}

void	ft_swap_gen(void *pv1, void *pv2, unsigned int elem_size)
{
	char *buf;
	
	buf = malloc(elem_size * sizeof(char));
	ft_memcpy(buf, pv1, elem_size);
	ft_memcpy(pv1, pv2, elem_size);
	ft_memcpy(pv2, buf, elem_size);
	free(buf);
}

void	ft_str_reverse(char *str)
{
	char *pe;

	pe = str;
	while (*pe++)
		;
	pe -= 2;
	while (str < pe)
		ft_swap_gen(str++, pe--, sizeof(char));
}

int		ft_is_prime(unsigned int nb)
{
	unsigned int i;

	if (nb <= 1)
		return (0);
	else if (nb <= 3)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i < nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}
