#if 0

ft_stackdel.c

#endif

#include "libft.h"

void	ft_stackdel(t_stack **stack)
{
  if (!*stack)
    return ;
  ft_lstdel(&(*stack)->top, (*stack)->free_fn);
  free(*stack);
  *stack = 0;
}
