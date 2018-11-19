/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:55:04 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/14 14:57:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *ret;
	char *needle;

	if (!str)
		return (0);
	if (!to_find || !*to_find)
		return (str);
	needle = to_find;
	while (*(ret = str))
	{
		while (*str++ == *to_find++)
			if (!*to_find)
				return (ret);
		to_find = needle;
	}
	return (0);
}
