/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:41:18 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/13 09:47:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = 0;
	node->content_size = 0;
	node->next = 0;
	if (content)
	{
		node->content = malloc(content_size * sizeof(char));
		if (!node->content)
		{
			free(node);
			return (0);
		}
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	return (node);
}
