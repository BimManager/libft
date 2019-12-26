/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvshash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:16:04 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 13:30:19 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_swapchr(char *str, int pos, char c)
{
	char	*pch;

	pch = ft_strchr(str, c);
	if (pch != NULL)
		ft_swap(str + pos, pch, sizeof(char));
	return (str);
}

char		*ft_mvsign(char *snb, t_format *fmt)
{
	if (!fmt->zero)
		return (snb);
	if (fmt->neg)
		ft_swapchr(snb, 0, '-');
	else if (fmt->plus)
		ft_swapchr(snb, 0, '+');
	else if (fmt->space)
		ft_swapchr(snb, 0, ' ');
	return (snb);
}

char		*ft_mvhash(char *snb, t_format *fmt, char hash)
{
	if (!fmt->zero || !fmt->hash)
		return (snb);
	ft_swapchr(snb, 1, hash);
	return (snb);
}
