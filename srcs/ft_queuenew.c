#if 0

ft_queuenew.c

#endif

#include "libft.h"

t_queue	*ft_queuenew(void const *content, size_t content_size, void (*del) (void *, size_t))
{
  t_queue	*queue;
  t_list	*new;
  
  queue = malloc(sizeof(t_queue));
  if (!queue)
    return (0);
  new = ft_lstnew(content, content_size);
  if (!new)
    {
      free(queue);
      return (0);
    }
  queue->head = new;
  queue->tail = new;
  queue->free_fn = del;
  return (queue);
}
