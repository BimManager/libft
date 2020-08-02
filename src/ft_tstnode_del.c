// Copyright 2020 kkozlov

#include "libft.h"

void	ft_tstnode_del(t_tstnode **node, void (*del)(void *, size_t))
{
  if ((*node)->left)
    ft_tstnode_del(&(*node)->left, del);
  if ((*node)->mid)
    ft_tstnode_del(&(*node)->mid, del);
  if ((*node)->right)
    ft_tstnode_del(&(*node)->right, del);
  if ((*node)->data)
    ft_datadel(&(*node)->data, del);
  free(*node);
  *node = NULL;
}
