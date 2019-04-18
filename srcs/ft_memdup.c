/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:57:36 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/12 14:57:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
  void	*ret;

  ret = malloc(n * sizeof(char));
  if (!ret)
    return (NULL);
  while (n--)
    *((char *)ret + n) = *((char *)src + n);
  return (ret);
}
