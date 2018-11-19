/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:00:05 by kkozlov           #+#    #+#             */
/*   Updated: 2018/10/30 20:08:58 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++)
		++len;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	out;
	int				max;

	out = ft_strlen(src);
	if (size == 0)
		return (out);
	max = size - 1;
	while (max--)
		*dest++ = *src++;
	*dest = '\0';
	return (out);
}
