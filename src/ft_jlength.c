/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jlength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:41:20 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/18 12:42:34 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_jlength(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	fmt->length = sizeof(intmax_t);
	++(*sfmt);
	return (NULL);
}
