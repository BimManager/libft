#if 0

ft_lstdel.c

#endif

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
  t_list *tmp;
  
  while (*alst)
    {
      del((*alst)->content, (*alst)->content_size);
      tmp = (*alst)->next;
      free((*alst));
      *alst = tmp;
    }
  *alst = 0;
}
