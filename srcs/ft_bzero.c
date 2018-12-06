#if 0

ft_bzero.c

#endif

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
  while (n--)
    *((char*)s + n) = 0;
}
