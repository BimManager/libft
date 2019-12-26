/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infnan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:49:48 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/15 17:34:28 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_infnan(long double ldb)
{
	char		*ret;
	t_ext80		ext80;

	ext80.value = ldb;
	ret = malloc(4 * sizeof(char));
	if (EXP_ALL_ONES == ext80.bits.exp)
	{
		if (!(ext80.bits.man << 1))
			ft_strcpy(ret, "inf");
		else
			ft_strcpy(ret, "nan");
	}
	else
		ft_memdel((void **)&ret);
	return (ret);
}
