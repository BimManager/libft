#if 0

ft_mergesort.c

#endif

#include "libft.h"

static void	ft_merge(void *base, size_t nel, size_t width);

int		ft_mergesort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *))
{
  if (nel < 2)
    return (0);

  ft_mergesort(base, nel / 2, width, compar);
  ft_mergesort((char *)base + (nel / 2) * width, nel - nel / 2, width, compar);
  ft_merge(base, nel, width); 
  return (0);
}

static void	ft_merge(void *base, size_t nel, size_t width)
{
  void	*left;
  void	*right;

  left = malloc(nel / 2 * width * sizeof(char));
  right = malloc((nel - nel / 2) * width * sizeof(char));
  ft_memcpy(left, base, (nel / 2) * width);
  ft_memcpy(right, (char *)base + nel / 2 * width, (nel - nel / 2) * width);
  
}
