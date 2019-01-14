#if 0

ft_queuesize.c

#endif

#include "libft.h"

size_t	ft_queuesize(t_queue *queue)
{
  if (!queue || !queue->head)
    return (0);
  return (ft_lstsize(queue->head));
}
