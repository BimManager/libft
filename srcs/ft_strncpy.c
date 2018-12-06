/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:35:48 by kkozlov           #+#    #+#             */
/*   Updated: 2018/11/04 10:54:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *str;

	str = dest;
	while (n-- && *str)
		*dest++ = *src++;
	*dest++ = '\0';
	while (n--)
		*dest++ = '\0';
	return (str);
}