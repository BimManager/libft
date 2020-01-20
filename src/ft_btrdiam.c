/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrdiam.c                                       :+:      :+:    :+:   */
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

static int	xbtrdiam(t_btrnode *root, int *diam)
{
	int	left_h;
	int	right_h;
	int	max;

	if (!root)
		return (0);
	left_h = xbtrdiam(root->left, diam);
	right_h = xbtrdiam(root->right, diam);
	max = left_h + right_h + 1;
	*diam = xmax(max, *diam);
	return (xmax(left_h, right_h) + 1);
}

int			ft_btrdiam(t_btrnode *root)
{
	int	diam;

	diam = 0;
	xbtrdiam(root, &diam);
	return (diam);
}
