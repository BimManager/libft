#if 0

ft_stackpush.c

#endif

#include "libft.h"

void	ft_stackpush(t_stack *stack, void *content, size_t content_size)
{
  t_list *new;

  new = ft_lstnew(content, content_size);
  new->next = stack->top;
  stack->top = new;
}
