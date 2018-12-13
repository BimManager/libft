#if 0

ft_lstadd.c

#endif

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
  t_list *tmp;

  tmp = *alst;
  *alst = new;
  (*alst)->next = tmp;
}
