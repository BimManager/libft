#if 0

ft_memccpy.c

#endif

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
  size_t i;

  i = -1;
  while (++i < n)
    {
      if (*((char*)src + i) == (unsigned char)c)
	{
	  *((char*)dst + i) = (unsigned char)c;
	  return ((char*)dst + ++i);
	}
      *((char*)dst + i) = *((char*)src + i);
    }
  return (0);
}
