#if 0

ft_stackpop.c

#endif

#include "libft.h"

void	*ft_stackpop(t_stack *stack)
{
  void		*content;

  if (!stack || !stack->top)
    return (0);
  content = malloc(stack->top->content_size * sizeof(char));
  if (!content)
    return (0);
  ft_memcpy(content, stack->top->content, stack->top->content_size);
  ft_lstdelone(&stack->top, stack->free_fn);
  return (content);
}
