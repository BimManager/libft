/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:38:36 by kkozlov           #+#    #+#             */
/*   Updated: 2019/02/13 14:02:59 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_words(char *str)
{
	int words;

	words = 0;
	while (*str)
	{
		while (ft_iswhitespace(*str))
			++str;
		++words;
		while (!ft_iswhitespace(*str) && *str)
			++str;
	}
	return (words);
}

char		**ft_split_whitespaces(char *str)
{
	int		size;
	int		len;
	char	**arr;
	char	**pbeg;

	size = ft_calc_words(str);
	arr = malloc((size + 1) * sizeof(char*));
	pbeg = arr;
	while (size--)
	{
		while (ft_iswhitespace(*str))
			++str;
		len = 0;
		while (!ft_iswhitespace(*str) && *str)
		{
			++len;
			++str;
		}
		if (!*str && len == 0)
			break ;
		*arr = malloc((len + 1) * sizeof(char));
		ft_strncpy(*arr++, str - len, len);
	}
	*arr = 0;
	return (pbeg);
}
