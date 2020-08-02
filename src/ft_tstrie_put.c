// Copyright 2020 kkozlov

#include "libft.h"

static void	ft_put_null(t_tstnode **it, char const *key, t_data *data)
{
  while (*key)
  {
    *it = ft_tstnode_new(*key++);
    if (*key)
      it = &(*it)->mid;
  }
  (*it)->data = data;
}

void		ft_tstrie_put(t_tstrie *trie, char const *key,
                      void const *content, size_t size)
{
  t_data	*data;
  t_tstnode	**it;

  data = ft_datanew(content, size);
  it = &trie->root;
  while (*key)
  {
    if (!*it)
      return (ft_put_null(it, key, data));
    if ((*it)->ch == *key)
    {
      ++key;
      if (*key)
        it = &(*it)->mid;
    }
    else if ((*it)->ch > *key)
      it = &(*it)->left;
    else
      it = &(*it)->right;
  }
  ft_datadel(&(*it)->data, NULL);
  (*it)->data = data;
}
