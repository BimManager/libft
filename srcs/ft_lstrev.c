#if 0

ft_lstrev.c

#endif 

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
  t_list *prv;
  t_list *cur;
  t_list *nxt;

  if (!alst)
    return ;
  prv = 0;
  cur = *alst;
  while (cur)
    {
      nxt = cur->next;
      cur->next = prv;
      prv = cur;
      cur = nxt;
    }
  *alst = prv;
}
