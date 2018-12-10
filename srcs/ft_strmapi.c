#if 0

ft_strmapi.c

#endif

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
  char		*str;
  unsigned int	size;

  size = ft_strlen(s);
  str = malloc(++size * sizeof(char));
  if (!str)
    return (0);
  while (--size)
    *(str + size) = f(size, *(s + size));
  return (str);
}
