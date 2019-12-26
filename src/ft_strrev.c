/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:15:07 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/05 12:27:44 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*pb;
	char	*pe;

	if (!*str)
		return (str);
	pb = str;
	pe = str;
	while (*pe)
		++pe;
	--pe;
	while (pb < pe)
		ft_swap(pb++, pe--, sizeof(char));
	return (str);
}
