#if 0

ft_lstiter.c

#endif

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
  while (lst)
    {
      f(lst);
      lst = lst->next;
    }
}
