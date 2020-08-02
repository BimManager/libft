// Copyright 2020 kkozlov

#include "libft.h"

t_data	*ft_tstrie_get(t_tstrie *trie, char const *key)
{
  t_tstnode	*it;

  it = trie->root;
  while (*key)
  {
    if (!it)
      return (NULL);
    if (it->ch == *key)
    {
      ++key;
      if (*key)
        it = it->mid;
    }
    else if (it->ch > *key)
      it = it->left;
    else
      it = it->right;
  }
  return (it->data);
}
