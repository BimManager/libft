#if 0

ft_memcpy.c

#endif

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
  while (n--)
    *((char*)dst + n) = *((char*)src + n);
  return (dst);
}
