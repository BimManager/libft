/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zlength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:33:10 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/18 12:34:37 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_zlength(va_list pa, t_format *fmt, const char **sfmt)
{
	(void)pa;
	fmt->length = sizeof(size_t);
	++(*sfmt);
	return (NULL);
}
