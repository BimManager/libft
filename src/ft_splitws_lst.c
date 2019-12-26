/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitws_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:10:44 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/25 16:03:21 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_strlst(char **str)
{
	t_list	*new;
	char	*it;
	char	*tmp;
	int		len;

	it = *str;
	while (*it && !ft_iswhitespace(*it))
		++it;
	if (!(len = it - *str))
		return (NULL);
	tmp = ft_memdup(*str, len + 1);
	*(tmp + len) = '\0';
	new = ft_lstnew(tmp, len + 1);
	free(tmp);
	*str += len;
	return (new);
}

static void		ft_freenode(void *pv, size_t size)
{
	if (size && pv)
		free(pv);
}

t_list			*ft_splitws_lst(char *str)
{
	t_list	*ret;

	ret = ft_lstnew(NULL, 0);
	while (*str)
	{
		while (*str && ft_iswhitespace(*str))
			++str;
		ft_lstadd(&ret, ft_strlst(&str));
	}
	ft_lstrev(&ret);
	ft_lstdelone(&ret, &ft_freenode);
	return (ret);
}
