/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:14:25 by kkozlov           #+#    #+#             */
/*   Updated: 2018/10/29 17:39:25 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int res;
	int pn;

	res = 0;
	pn = 1;
	while (*str == ' '
			|| *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		++str;
		pn = 0;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	return (pn ? (res) : (res * -1));
}