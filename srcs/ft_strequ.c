#if 0

ft_strequ.c

#endif

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
  while (*s1)
    if (*s1++ != *s2++)
      return (0);
  return (*s1 == *s2 ? 1 : 0); 
}
