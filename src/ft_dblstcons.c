/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstcons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:04:37 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/14 14:07:09 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dblstcons(t_dblst *lst, t_data *data)
{
	ft_dblstsnoc(lst, data);
	lst->head = lst->head->prev;
}
