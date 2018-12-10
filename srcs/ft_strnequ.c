#if 0

ft_strnequ.c

#endif

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
  while (*s1 && n--)
    if (*s1++ != *s2++)
      return (0);
  if (!*s1 && !n)
    return (1);
  return (*s1 == *s2 ? 1 : 0); 
}
