#if 0

ft_striter.c

#endif

#include "libft.h"

void	ft_striter(char *s, void (*f) (char *))
{
  while (*s)
    f(s++);
}
