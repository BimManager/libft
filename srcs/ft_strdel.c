#if 0

ft_strdel.c

#endif

#include "libft.h"

void	ft_strdel(char **as)
{
  free(*as);
  *as = 0;
}
