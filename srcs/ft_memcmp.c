#if 0

ft_memcmp.c

#endif

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
  size_t i;

  i = -1;
  while (++i < n)
    if (*((unsigned char*)s1 + i) != *((unsigned char*)s2 + i))
      return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
  --i;
  return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
}
