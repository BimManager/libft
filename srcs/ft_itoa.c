#if 0

ft_atoi.c

#endif

#include "libft.h"

static void ft_itoa_it(char **nb, unsigned int n)
{
  if (n > 9)
    ft_itoa_it(nb, n / 10);
  *(*nb)++ = (n % 10) + '0'; 
}

char	*ft_itoa(int n)
{
  char		*itr;
  char		*ret;
  unsigned int	nb;

  ret = malloc(32 * sizeof(char));
  if (!ret)
    return (0);
  itr = ret;
  nb = n;
  if (n < 0)
    {
      *itr++ = '-';
      nb = -n;
    }
  ft_itoa_it(&itr, nb);
  *itr = 0x00;
  return (ret);
}
