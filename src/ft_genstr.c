/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:11:25 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 14:01:19 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_genstr(va_list pa, t_format *fmt, const char **sfmt)
{
	char	*ret;

	(void)pa;
	ret = malloc(2 * sizeof(char));
	ft_strncpy(ret, *sfmt, 1);
	*(ret + 1) = '\0';
	ret = ft_fixwidth(ret, fmt);
	fmt->done = 1;
	++(*sfmt);
	return (ret);
}
