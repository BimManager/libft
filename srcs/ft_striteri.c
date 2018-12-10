#if 0

ft_striteri.c

#endif

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
  unsigned int i;

  i = 0;
  while (*s)
    f(i++, s++);
}
