/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datanew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:37:15 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/13 14:44:06 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_datanew(const void *content, size_t size)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->size = size;
	if (!content || !size)
		data->content = NULL;
	else
	{
		data->content = malloc(sizeof(size));
		ft_memcpy(data->content, content, data->size);
	}
	return (data);
}
