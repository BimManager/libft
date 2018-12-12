#if 0

ft_lstdelone.c

#endif

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
  del((*alst)->content, (*alst)->content_size);
  free(*alst);
  *alst = 0;
}
