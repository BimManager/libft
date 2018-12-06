/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:38:36 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/02 14:36:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		ft_calc_words(char *str)
{
	int words;

	words = 0;
	while (*str)
	{
		while (ft_is_whitespace(*str))
			++str;
		++words;
		while (!ft_is_whitespace(*str) && *str)
			++str;
	}
	return (words);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *str;

	str = dest;
	while (n--)
		*dest++ = *src++;
	*dest = '\0';
	return (str);
}

char	**ft_split_whitespaces(char *str)
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
		while (ft_is_whitespace(*str))
			++str;
		len = 0;
		while (!ft_is_whitespace(*str) && *str)
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
