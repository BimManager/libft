#if 0

ft_dequeue.c

#endif

#include "libft.h"

void	*ft_dequeue(t_queue *queue)
{
  void		*content;

  if (!queue || !queue->head)
    return (0);
  content = malloc(queue->head->content_size * sizeof(char));
  if (!content)
    return (0);
  ft_memcpy(content, queue->head->content, queue->head->content_size);
  ft_lstdelone(&queue->head, queue->free_fn);
  return (content);
}
