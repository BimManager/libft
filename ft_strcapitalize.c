/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:49:58 by kkozlov           #+#    #+#             */
/*   Updated: 2018/10/30 12:58:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int		is_lowcase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

void	to_upper(char *pc)
{
	if (is_lowcase(*pc))
		*pc = *pc + ('A' - 'a');
}

void	to_lower(char *pc)
{
	if (*pc >= 'A' && *pc <= 'Z')
		*pc = *pc - ('A' - 'a');
}

char	*ft_strcapitalize(char *str)
{
	char *pbeg;

	pbeg = str;
	if (is_alpha(*str))
		if (is_lowcase(*str++))
			to_upper(str - 1);
	while (*str)
	{
		if (!is_alpha(*str) && (*str < '0' || *str > '9'))
		{
			++str;
			if (is_alpha(*str))
				if (is_lowcase(*str++))
					to_upper(str - 1);
			continue;
		}
		else if (*str >= 'A' && *str <= 'Z')
			to_lower(str);
		++str;
	}
	return (pbeg);
}
