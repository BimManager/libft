#if 0

ft_qsort.c

#endif

#include "libft.h"

static void	*ft_pivot(void *base, size_t nel, size_t width)
{
  return ((char *)base + (nel - 1) / 2 * width);
} 

void		ft_qsort(void *base, size_t nel,
			size_t width,
			int (*compar)(const void *, const void *))
{
  void		*pivot;
  size_t	i;
  size_t	last;	
  
  if (nel < 2)
    return ;
  pivot = ft_pivot(base, nel, width);
  ft_swap(base, pivot, width);
  i = 0;
  last = 0;
  while (++i < nel)
    {
      if (compar(base, (char *)base + i * width) > 0)
	{
	  ++last;
	  ft_swap((char *)base + i * width, (char *)base + last * width, width);
	}
    }
  ft_swap(base, (char *)base + last * width, width);
  ft_qsort(base, last, width, compar);
  ft_qsort((char *)base + (last + 1) * width, nel - last - 1, width, compar);
}
