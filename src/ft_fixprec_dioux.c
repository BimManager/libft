/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixprec_dioux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:11:22 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 09:20:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fixprec_dioux(char *snb, t_format *fmt)
{
	char	*ret;
	int		len;

	if (-1 != fmt->prec)
		fmt->zero = 0;
	len = ft_strlen(snb);
	if (fmt->prec <= len)
		return (snb);
	ret = malloc((fmt->prec + 1) * sizeof(char));
	ft_memset(ret, '0', fmt->prec);
	ft_strcpy(ret + (fmt->prec - len), snb);
	free(snb);
	return (ret);
}
