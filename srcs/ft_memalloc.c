#if 0

ft_memalloc.c

#endif

#include "libft.h"

void	*ft_memalloc(size_t size)
{
  void *pv;
  
  pv = malloc(size * sizeof(char));
  if (!pv)
    return (0);
  while (size--)
    *((char*)pv + size) = 0;
  return (pv);
}
