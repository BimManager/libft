/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datadel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:38:54 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/13 14:39:43 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_datadel(t_data **data, void (*del)(void *, size_t))
{
  if (del)
	del((*data)->content, (*data)->size);
  else
    free((*data)->content);
  free(*data);
  *data = NULL;
}
