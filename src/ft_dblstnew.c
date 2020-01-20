/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:56:49 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/17 11:43:29 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblst	*ft_dblstnew(void)
{
	t_dblst	*lst;

	lst = malloc(sizeof(t_dblst));
	lst->head = NULL;
	lst->elems = 0;
	return (lst);
}
