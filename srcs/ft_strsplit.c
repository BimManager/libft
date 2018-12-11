#if 0

ft_strsplit.c

#endif

#include "libft.h"

static size_t ft_getwc(char const *s, char c)
{
  size_t wc;

  wc = 0;
  while (*s)
    {
      while (*s == c)
	++s;
      if (*s)
	++wc;
      while (*s && *s != c)
	++s;
    }
  return (wc);
}

static size_t ft_getlen(char const *s, char c)
{
  size_t len;

  len = 0;
  while (*s && *s++ != c)
    ++len;
  return (len);
}

char	**ft_strsplit(char const *s, char c)
{
  char		**ret;
  char		**itr;
  size_t	wc;
  size_t	len;

  wc = ft_getwc(s, c);
  ret = malloc((wc + 1) * sizeof(char*));
  if (!ret)
    return (0);
  *(ret + wc) = 0;
  itr = ret;
  while (wc--)
    {
      while (*s == c)
	++s;
      len = ft_getlen(s, c);
      *itr = malloc((len + 1) * sizeof(char));
      ft_strncpy(*itr++, s, len);
      s += len;
    }
  return (ret); 
}
