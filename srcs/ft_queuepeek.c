#if 0

ft_queuepeek.c

#endif

#include "libft.h"

void	*ft_queuepeek(t_queue *queue)
{
  void	*content;

  if (!queue || !queue->head)
    return (0);
  content = malloc(queue->head->content_size * sizeof(char));
  if (!content)
    return (0);
  ft_memcpy(content, queue->head->content, queue->head->content_size);
  return (content);
}
