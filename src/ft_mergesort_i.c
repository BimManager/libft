// Copyright 2020 kkozlov

#include "libft.h"

static void _Merge(void *base, size_t low, size_t mid, size_t high,
                   size_t width, int (*cmp)(void const *, void const *),
                   void *aux)
{
  size_t	i;
  size_t	j;
  size_t	k;

  memcpy(aux + low * width, base + low * width, (high - low + 1) * width);
  i = low;
  j = mid;
  k = low - 1;
  while (++k <= high)
  {
    if (i == mid)
      memcpy(base + k * width, aux + (j++ * width), width);
    else if (j > high)
      memcpy(base + k * width, aux + (i++ * width), width);
    else if (cmp(aux + i * width, aux + j * width) < 0)
      memcpy(base + k * width, aux + (i++ * width), width);
    else
      memcpy(base + k * width, aux + (j++ * width), width);
  }
}

void		ft_mergesort_i(void *base, size_t nel, size_t width,
                           int (*cmp)(void const *, void const *))
{
  void		*aux;
  size_t	sz;
  size_t	off;

  aux = malloc(nel * width);
  sz = 1;
  while (sz < nel)
  {
    off = 0;
    while (off < nel - sz)
    {
      _Merge(base, off, off + sz, FT_MIN(off + sz + sz - 1, nel - 1),
              width, cmp, aux);
       off += (sz + sz);
    }
    sz += sz;
  }
  free(aux);
}
