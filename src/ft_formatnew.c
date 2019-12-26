/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:01:52 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/18 10:34:23 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format	*ft_formatnew(void)
{
	t_format	*new;

	new = malloc(sizeof(t_format));
	ft_bzero(new, sizeof(t_format));
	new->width = -1;
	new->prec = -1;
	new->length = sizeof(int);
	return (new);
}
