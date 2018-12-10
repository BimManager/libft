#if 0

ft_strmap.c

#endif

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
  char *str;
  char *itr;

  str = malloc((ft_strlen(s) + 1) * sizeof(char));
  if (!str)
    return (0);
  itr = str;
  while (*s)
    *itr++ = f(*s++);
  return (str);
}
