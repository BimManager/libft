#if 0

ft_mergesort.c

#endif

#include "libft.h"

static void	ft_merge(void *base, size_t nel, size_t width, int (*compar) (const void *, const void *));
static void	ft_copy(void *base, void *src, size_t *i, size_t width);

int		ft_mergesort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *))
{
  size_t	mid;

  if (nel < 2)
    return (0);
  mid = nel / 2;
  ft_mergesort(base, mid, width, compar);
  ft_mergesort((char *)base + mid * width, nel - mid, width, compar);
  ft_merge(base, nel, width, compar);
  return (0);
}

static void	ft_copy(void *base, void *src, size_t *i, size_t width)
{
  ft_memcpy(base, src, width);
  (*i)++;
}

static void	ft_merge(void *base, size_t nel, size_t width, int (*compar) (const void *, const void *))
{
  void		*left;
  void		*right;
  size_t	mid;
  size_t	l;
  size_t	r;

  mid = nel / 2;
  left = malloc(mid * width * sizeof(char));
  right = malloc((nel - mid) * width * sizeof(char));
  ft_memcpy(left, base, mid * width);
  ft_memcpy(right, (char *)base + mid * width, (nel - mid) * width);
  l = 0;
  r = 0;
  while ((l < mid) && (r < (nel - mid)))
    {
      if (compar((char *)left + l * width, (char *)right + r * width) <= 0)
	ft_copy((char *)base + (l + r) * width, (char *)left + l * width, &l, width); 
      else
	ft_copy((char *)base + (l + r) * width, (char *)right + r * width, &r, width);
    }
  while (l < mid)
    ft_copy((char *)base + (l + r) * width, (char *)left + l * width, &l, width); 
  while (r < (nel - mid))
    ft_copy((char *)base + (l + r) * width, (char *)right + r * width, &r, width);
  free(left);
  free(right);
}
