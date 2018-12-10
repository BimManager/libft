#if 0

ft_strclr.c

#endif

#include "libft.h"

void	ft_strclr(char *s)
{
  while (*s)
    *s++ = 0x00;
}
