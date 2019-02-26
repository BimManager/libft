/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:31:35 by kkozlov           #+#    #+#             */
/*   Updated: 2018/10/30 15:40:18 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	char *pend;

	pend = dest;
	while (*pend++)
		;
	--pend;
	while (nb-- && *src)
		*pend++ = *src++;
	*pend = '\0';
	return (dest);
}
