#if 0

ft_stackpeek.c

#endif

#include "libft.h"

void	*ft_stackpeek(t_stack *stack)
{
  void	*content;

  content = malloc(stack->top->content_size * sizeof(char));
  if (!content)
    return (0);
  ft_memcpy(content, stack->top->content, stack->top->content_size);
  return (content);
}
