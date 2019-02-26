/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:33:37 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/16 11:07:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getwc(char const *s, char c)
{
	size_t wc;

	wc = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
			++wc;
		while (*s && *s != c)
			++s;
	}
	return (wc);
}

static size_t	ft_getwl(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s++ != c)
		++len;
	return (len);
}

static size_t	ft_cpw(char ***ret, char const **s, char c)
{
	size_t	wl;

	wl = ft_getwl(*s, c);
	**ret = malloc((wl + 1) * sizeof(char));
	if (!**ret)
		return (0);
	ft_strlcpy(**ret, *s, wl + 1);
	++(*ret);
	*s += wl;
	return (1);
}

static void		ft_dealloc(char **tab)
{
	if (!tab)
		return ;
	while (*tab)
		free(*tab++);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	char		**itr;
	size_t		wc;

	if (!s)
		return (0);
	wc = ft_getwc(s, c);
	ret = malloc((wc + 1) * sizeof(char*));
	if (!ret)
		return (0);
	*(ret + wc) = 0;
	itr = ret;
	while (wc--)
	{
		while (*s == c)
			++s;
		if (!ft_cpw(&itr, &s, c))
		{
			ft_dealloc(ret);
			return (0);
		}
	}
	return (ret);
}
