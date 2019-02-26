/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:42:33 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/14 16:05:46 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char *copy;
	char *pb;

	copy = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!copy)
		return (0);
	pb = copy;
	while (*str)
		*copy++ = *str++;
	*copy = 0x00;
	return (pb);
}
