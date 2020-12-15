// Copyright 2020 kkozlov

#include "libft.h"

static void	_Swap(void *pv1, void *pv2, size_t n)
{
  char	t;

  while (n--)
  {
    t = *((char *)pv1 + n);
    *((char *)pv1 + n) = *((char *)pv2 + n);
    *((char *)pv2 + n) = t;
  }
}

static void	_Partition3way(void *base, int lo, int hi, size_t width,
                           int (*comp)(const void *, const void *))
{
  int	lt;
  int	gt;
  int	i;
  int	cmp;
  char	buf[32];

  if (lo >= hi)
    return ;
  memcpy(buf, base + lo * width, width);
  lt = lo;
  gt = hi;
  i = lo;
  while (i <= gt)
  {
    cmp = comp(base + i * width, buf);
    if (cmp < 0)
      _Swap(base + i++ * width, base + lt++ * width, width);
    else if (cmp > 0)
      _Swap(base + i * width, base + gt-- * width, width);
    else
      ++i;
  }
  _Partition3way(base, lo, lt - 1, width, comp);
  _Partition3way(base, gt + 1, hi, width, comp);
}

void		ft_qsort_3way(void *base, size_t nel, size_t width,
                          int (*comp)(const void *, const void *))
{
  _Partition3way(base, 0, nel - 1, width, comp);
}
