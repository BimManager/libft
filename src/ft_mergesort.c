#include "libft.h"

static void	_Merge(void *base, size_t nel, size_t width,
                   int (*cmp)(void const *, void const *),
                   void *aux)
{
  size_t	i;
  size_t	j;
  size_t	k;

  memcpy(aux, base, nel * width);  
  i = 0;
  j = nel >> 1;
  k = -1;
  while (++k < nel)
  {
    if (i >= (nel >> 1))
      memcpy((char *)base + k * width, (char *)aux + j++ * width, width);
    else if (j >= nel)
      memcpy((char *)base + k * width, (char *)aux + i++ * width, width);
    else if (cmp(aux + i * width, aux + j * width) < 0)
      memcpy((char *)base + k * width, (char *)aux + i++ * width, width);
    else
      memcpy((char *)base + k * width, (char *)aux + j++ * width, width);
  }
}

static void	_Mergesort(void *base, size_t nel, size_t width,
                       int (*cmp)(void const *, void const *),
                       void *aux)
{
  if (nel <= 1)
    return ;
  _Mergesort(base, nel >> 1, width, cmp, aux);
  _Mergesort(base + (nel >> 1) * width, nel - (nel >> 1), width, cmp, aux);
  _Merge(base, nel, width, cmp, aux);
}

void		ft_mergesort(void *base, size_t nel, size_t width,
                         int (*cmp)(void const *, void const *))
{
  void	*aux;

  aux = malloc(nel * width);
  _Mergesort(base, nel, width, cmp, aux);
  free(aux);
}
