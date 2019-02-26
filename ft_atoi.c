/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:14:25 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/16 13:16:32 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_check_overflow(unsigned int unb, unsigned char sign)
{
	unsigned int	max;
	unsigned int	min;

	max = ~0U >> 1;
	min = -~max;
	if (unb > max && sign)
		return (-1);
	else if (unb > min)
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	unsigned int	res;
	unsigned char	sign;
	char			overflow;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		++str;
		sign = 0;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	if ((overflow = ft_check_overflow(res, sign)) != 1)
		return (overflow);
	return (sign ? res : -res);
}
