/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:22:50 by kkozlov           #+#    #+#             */
/*   Updated: 2018/10/30 14:34:54 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_printable(char c)
{
	if ((c >= 0x20 && c <= 0x7e))
		return (1);
	return (0);
}

int		ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!ft_is_printable(*str++))
			return (0);
	}
	return (1);
}
