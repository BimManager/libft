// Copyright 2020 kkozlov

#include "libft.h"

static void	_rec(t_tstnode *prev, t_tstnode *it, char const *key,
                 void (*del)(void *, size_t))
{
  if (!*key || !it)
    return ;
  if (it->ch == *key)
    _rec(it, it->mid, key + 1, del);
  else if (it->ch > *key)
    _rec(it, it->left, key, del);
  else
    _rec(it, it->right, key, del);
  if (!key[1] && it->data)
    ft_datadel(&it->data, del);
  if ((prev && !it->data) && (!it->left && !it->mid && !it->right))
  {
    if (prev->left == it)
      prev->left = NULL;
    else if (prev->mid == it)
      prev->mid = NULL;
    else
      prev->right = NULL;
    ft_tstnode_del(&it, del);
  }
}

void		ft_tstrie_delkey(t_tstrie *trie, char const *key,
                             void (*del)(void *, size_t))
{
  _rec(NULL, trie->root, key, del);
}
