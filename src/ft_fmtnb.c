/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:57:02 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/20 11:07:04 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fmtnb(const char **sfmt)
{
	char	*pb;
	char	*snb;
	int		nb;

	pb = *(char **)sfmt;
	while (ft_isdigit(**sfmt))
		++(*sfmt);
	snb = malloc((((*sfmt) - pb) + 1) * sizeof(char));
	*(snb + ((*sfmt) - pb)) = '\0';
	ft_strncpy(snb, pb, (*sfmt) - pb);
	nb = ft_atoi(snb);
	free(snb);
	return (nb);
}
