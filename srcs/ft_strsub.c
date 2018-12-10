#if 0

ft_strsub.c

#endif

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
  size_t	real_len;
  char		*str;
  char		*ret;

  real_len = ft_strlen(s);
  if (start >= real_len ||
      (start + len) > real_len)
    return (0);
  str = malloc((len + 1) * sizeof(char));
  if (!str)
    return (0);
  ret = str; 
  while (len--)
    {
      *str++ = *(s + start);
      ++s;
    }
  *str = 0x00;
  return (ret);
}
