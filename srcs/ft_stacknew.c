#if 0

ft_stacknew.c

#endif

#include "libft.h"

t_stack	*ft_stacknew(void const *content, size_t content_size,
		     void (*del) (void *, size_t))
{
  t_stack	*stack;
  t_list	*new;

  stack = malloc(sizeof(t_stack));
  if (!stack)
    return (0);
  new = ft_lstnew(content, content_size);
  if (!new)
    {
      free(stack);
      return (0);
    }
  stack->top = new;
  stack->free_fn = del;
  return (stack);
}
