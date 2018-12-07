#if 0

ft_memchr.c

#endif

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
  size_t i;

  i = -1;
  while (++i < n)
      if (*((char*)s + i) == (unsigned char)c)
	return ((char*)s + i);
  return (0);
}
