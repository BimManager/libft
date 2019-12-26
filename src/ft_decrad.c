/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:23:14 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/21 13:04:01 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*ft_decrad(const void *pnb, size_t size,
					const char *digits, size_t rad)
{
	t_stack		*stack;
	char		buffer[sizeof(size_t)];
	long long	num;
	int			neg;

	ft_bzero(buffer, sizeof(size_t));
	ft_memcpy(buffer, pnb, size > sizeof(size_t) ? sizeof(size_t) : size);
	stack = ft_stacknew(NULL, 0);
	num = *(size_t *)buffer;
	neg = 0;
	if (!num)
		ft_stackpush(stack, (void *)&digits[num % rad], sizeof(char));
	while (num)
	{
		ft_stackpush(stack, (void *)&digits[num % rad], sizeof(char));
		num /= rad;
	}
	if (neg && 10 == rad)
	{
		neg = '-';
		ft_stackpush(stack, &neg, sizeof(char));
	}
	return (stack);
}
