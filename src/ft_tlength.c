/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:44:50 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/18 12:47:13 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tlength(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	fmt->length = sizeof(ptrdiff_t);
	++(*sfmt);
	return (NULL);
}
