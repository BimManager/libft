#if 0

ft_gcd.c

#endif

#include "libft.h"

size_t	ft_gcd(size_t a, size_t b)
{
  size_t r;

  if (a < b)
    ft_swap(&a, &b, sizeof(size_t));
  while ((r = a % b))
    {
      a = b;
      b = r;
    }
  return (b);
}
