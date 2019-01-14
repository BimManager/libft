#if 0

ft_stacksize.c

#endif

#include "libft.h"

size_t	ft_stacksize(t_stack *stack)
{
  if (!stack)
    return (0);
  return (ft_lstsize(stack->top));
}
