#if 0

ft_enqueue.c

#endif

#include "libft.h"

void	ft_enqueue(t_queue *queue, void *content, size_t content_size)
{
  t_list *new;

  new = ft_lstnew(content, content_size);
  if (queue->tail)
    queue->tail->next = new;
  queue->tail = new;
}
