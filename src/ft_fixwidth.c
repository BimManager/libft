/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:57:31 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/21 13:19:00 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_specval(const char *sv, t_format *fmt)
{
	const char	*p;

	if ((p = ft_strstr(sv, "nan"))
		|| ((p = ft_strstr(sv, "inf"))))
		fmt->zero = 0;
}

char		*ft_fixwidth(char *str, t_format *fmt)
{
	char	*ret;
	int		sln;

	sln = ft_strlen(str);
	if (fmt->width <= sln)
		return (str);
	ret = malloc((fmt->width + 1) * sizeof(char));
	*(ret + fmt->width) = '\0';
	ft_specval(str, fmt);
	if (!fmt->align && fmt->zero)
		ft_memset(ret, '0', fmt->width);
	else
		ft_memset(ret, ' ', fmt->width);
	if (fmt->align)
		ft_strncpy(ret, str, sln);
	else
		ft_strncpy(ret + (fmt->width - sln), str, sln);
	free(str);
	return (ret);
}
