/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixhash_boxp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:34:41 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/19 10:41:26 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fixhash_boxp(char *snb, t_format *fmt, char *hash)
{
	char	*ret;
	int		sln;
	int		pln;

	if (!fmt->hash)
		return (snb);
	sln = ft_strlen(snb);
	pln = ft_strlen(hash);
	ret = malloc((sln + pln + 1) * sizeof(char));
	ft_strncpy(ret, hash, pln);
	ft_strcpy(ret + pln, snb);
	free(snb);
	return (ret);
}
