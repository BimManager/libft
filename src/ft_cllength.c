/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cllength.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:47:09 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/09 16:19:39 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cllength(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	fmt->length = sizeof(long double);
	++(*sfmt);
	return (NULL);
}
