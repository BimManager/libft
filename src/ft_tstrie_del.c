// Copyright 2020 kkozlov

#include "libft.h"

void	ft_tstrie_del(t_tstrie *trie, void (*del)(void *, size_t))
{
  if (trie->root)
    ft_tstnode_del(&trie->root, del);
}
