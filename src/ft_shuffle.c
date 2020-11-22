// Copyright 2020 kkozlov

#include "libft.h"

void	ft_shuffle(void *base, size_t nel, size_t width)
{
  size_t	i;
  size_t	rnd;

  srand(time(NULL));
  i = -1;
  while (++i < nel)
  {
    rnd = rand() % (i + 1);
    ft_swap((char *)base + i * width, (char *)base + rnd * width, width);
  }
}
