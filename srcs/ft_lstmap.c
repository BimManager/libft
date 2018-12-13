#if 0

ft_lstmap.c

#endif

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
  t_list *lstmap;
  t_list *lstitr;
  
  if (!lst)
    return (0);
  lstmap = f(lst);
  lstitr = lstmap;
  while ((lst = lst->next))
    {
      lstitr->next = f(lst);
      lstitr = lstitr->next;
    }
  return (lstmap);
}
