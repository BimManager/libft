#if 0

ft_memmove.c

#endif

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
  char		*buf;
  size_t	i; 

  buf = malloc(len * sizeof(char));
  i = -1;
  while (++i < len)
    *(buf + i) = *((char*)src + i);
  while (len--)
    *((char*)dst + len) = *(buf + len);
  free(buf);
  return (dst);
}
