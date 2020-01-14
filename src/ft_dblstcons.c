/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstcons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:04:37 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/13 15:43:23 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dblstcons(t_dblst *lst, void *content, size_t size)
{
	ft_dblstsnoc(lst, content, size);
	lst->head = lst->head->prev;
}
