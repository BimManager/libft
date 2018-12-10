#if 0

ft_strnew.c

#endif

#include "libft.h"

char	*ft_strnew(size_t size)
{
  char *str;

  str = malloc((size + 1)  * sizeof(char));
  if (!str)
    return (0);
  while (size--)
    *(str + size) = 0x00;
  return (str);
}
