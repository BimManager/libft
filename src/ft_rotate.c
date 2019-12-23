/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:57:51 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/13 12:00:26 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rotate(void *front, void *middle, void *end)
{
	void		*buf;
	size_t		front_size;
	size_t		back_size;

	front_size = (char *)middle - (char *)front;
	back_size = (char *)end - (char *)middle;
	buf = malloc(front_size * sizeof(char));
	if (!buf)
		return ;
	ft_memcpy(buf, front, front_size);
	ft_memmove(front, middle, back_size);
	ft_memcpy((char *)end - front_size, buf, front_size);
	free(buf);
}
