/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:15:54 by kkozlov           #+#    #+#             */
/*   Updated: 2018/10/30 10:17:02 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_digit(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int		ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!ft_is_digit(*str++))
			return (0);
	}
	return (1);
}
