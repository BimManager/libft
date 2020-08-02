// Copyright 2020 kkozlov

#include "libft.h"

t_tstnode	*ft_tstnode_new(char ch)
{
  t_tstnode	*node;

  node = malloc(sizeof(t_tstnode));
  node->left = NULL;
  node->mid = NULL;
  node->right = NULL;
  node->data = NULL;
  node->ch = ch;
  return (node);
}
