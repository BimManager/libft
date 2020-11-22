// Copyright 2020 kkozlov

#include "libft.h"

void	ft_shellsort(void *base, size_t nel, size_t width,
                     int (*cmp)(void const *, void const *))
{
  size_t	step;
  size_t	i;
  size_t	j;

  step = 1;
  while (step < nel / 3)
    step = 3 * step + 1;
  while (step >= 1)
  {
    i = step;
    while (i < nel)
    {
      j = i;
      while (j > 0 && cmp((char *)base + (j - step) * width,
                          (char *)base + j * width) > 0)
      {
        ft_swap((char *)base + (j - step) * width,
                (char *)base + j * width, width);
        j -= step;
      }
      i += step;
    }
    step = (step - 1) / 3;
  }
}
