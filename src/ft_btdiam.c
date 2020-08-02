/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btdiam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:11:56 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/18 17:24:38 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	xmax(int a, int b)
{
	return (a > b ? a : b);
}

static int	_btdiam(t_btnode *root, int *diam)
{
	int	left_h;
	int	right_h;
	int	max;

	if (!root)
		return (0);
	left_h = _btdiam(root->left, diam);
	right_h = _btdiam(root->right, diam);
	max = left_h + right_h + 1;
	*diam = xmax(max, *diam);
	return (xmax(left_h, right_h) + 1);
}

int			ft_btdiam(t_btnode *root)
{
	int	diam;

	diam = 0;
	_btdiam(root, &diam);
	return (diam);
}
