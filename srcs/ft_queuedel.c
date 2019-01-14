#if 0

ft_queuedel.c

#endif

#include "libft.h"

void	ft_queuedel(t_queue **queue)
{
  if (!*queue)
    return ;
  ft_lstdel(&(*queue)->head, (*queue)->free_fn);
  free(*queue);
  *queue = 0;
}
