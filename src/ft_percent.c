/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:29:05 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/17 15:29:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_percent(va_list pa, t_format *fmt, const char **sfmt)
{
	char	*ret;

	(void)pa;
	fmt->done = 1;
	++(*sfmt);
	ret = malloc(2 * sizeof(char));
	ft_strcpy(ret, "%");
	ret = ft_fixwidth(ret, fmt);
	return (ret);
}
