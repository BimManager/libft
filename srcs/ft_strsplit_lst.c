/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:42:03 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/01 10:47:05 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		++len;
	return (len);
}

t_list			*ft_strsplit_lst(char const *s, char c)
{
	t_list	*fnode;
	t_list	*new;
	size_t	word_len;
	char	*tmp_str;

	fnode = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (!*s)
			break ;
		word_len = get_word_len(s, c);
		tmp_str = ft_strndup(s, word_len);
		new = ft_lstnew(tmp_str, word_len + 1);
		ft_lstadd(&fnode, new);
		free(tmp_str);
		s += word_len;
	}
	ft_lstrev(&fnode);
	return (fnode);
}
