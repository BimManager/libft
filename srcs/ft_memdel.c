#if 0

ft_memdel.c

#endif

#include "libft.h"

void	ft_memdel(void **ap)
{
  free(*ap);
  *ap = 0;
}
