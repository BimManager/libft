#if 0

ft_strjoin.c

#endif

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
  char *str;
  char *ret;

  str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
  if (!str)
    return (0);
  ret = str;
  while (*s1)
    *str++ = *s1++;
  while (*s2)
    *str++ = *s2++;
  *str = 0x00;
  return (ret);
} 
