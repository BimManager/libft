#if 0

ft_strtrim.c

#endif

#include "libft.h"

static int ft_isws(char c)
{
  if (c == ' ' || c == '\t' || c == '\n')
    return (1);
  return (0);
}

char	*ft_strtrim(char const *s)
{
  const char *pb;
  const char *pe;
  char *str;

  while (ft_isws(*s))
    ++s;
  pb = s;
  while (*s)
    ++s;
  --s;
  while (ft_isws(*s))
    --s;
  pe = s;
  str = malloc((pe - pb + 2) * sizeof(char));
  if (!str)
    return (0);
  s = (char const *)str;
  while (pb <= pe)
    *str++ = *pb++;
  *str = 0x00;
  return ((char *)s); 
}
