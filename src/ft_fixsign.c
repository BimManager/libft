/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:56:24 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 10:30:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fixsign(char *snb, t_format *fmt)
{
	char	*ret;

	ret = malloc((ft_strlen(snb) + 2) * sizeof(char));
	ft_strcpy(ret + 1, snb);
	if (fmt->neg)
		ft_strncpy(ret, "-", 1);
	else if (fmt->plus)
		ft_strncpy(ret, "+", 1);
	else if (fmt->space)
		ft_strncpy(ret, " ", 1);
	else
		ft_strcpy(ret, snb);
	free(snb);
	return (ret);
}
