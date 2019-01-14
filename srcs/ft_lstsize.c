#if 0

ft_lstsize.c

#endif

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
  size_t size;

  size = 0;
  while (lst)
    {
      ++size;
      lst = lst->next;
    }
  return (size);
}
