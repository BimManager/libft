/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:26:03 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/07 14:03:55 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_data(void *data, size_t size)
{
	(void)size;
	free(data);
}

char		*ft_radstr(const void *pnb, size_t size,
				const char *digits, size_t rad)
{
	t_stack	*stack;
	char	*ret;
	char	*it;
	t_list	*digit;

	stack = ft_decrad(pnb, size, digits, rad);
	ret = malloc((ft_stacksize(stack) + 1) * sizeof(char));
	it = ret;
	while (ft_stackpeek(stack))
	{
		digit = ft_stackpop(stack);
		ft_strncpy(it++, digit->content, sizeof(char));
		ft_lstdel(&digit, &free_data);
	}
	*it = '\0';
	ft_stackdel(&stack, NULL);
	return (ret);
}
