#if 0

ft_lstnew.c

#endif

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
  t_list *node;

  node = malloc(sizeof(t_list));
  if (!node)
    return (0);
  if (!content)
    {
      node->content = 0;
      node->content_size = 0;
    }
  else
    {
      node->content = malloc(content_size * sizeof(char));
      ft_memcpy(node->content, content, content_size);
      node->content_size = content_size;
    }
  node->next = 0;
  return (node);
}
