#include "libft.h"

#ifdef UNDEF
static void ft_merge(void *base, size_t imid, size_t nel, size_t width,
                   int (*cmp) (const void *, const void *))
{
    void 	*left;
    void 	*right;
    size_t	il;
    size_t	ir;

    left = malloc(imid * width);
    right = malloc((nel - imid) * width);
    il = -1;
    while (++il < imid)
        memcpy((char *)left + il * width, (char *)base + il * width, width);
    ir = -1;
    while (++ir < nel - imid)
        memcpy((char *)right + ir * width, (char *)base + (imid + ir) * width, width);
    il = 0;
    ir = 0;
    while (il < imid && ir < nel - imid)
    {
        if (0 > cmp((char *)left + il * width, (char *)right + ir * width))
        {
            memcpy((char *)base + (il + ir) * width, (char *)left + il * width, width);
            ++il;
        }
        else
        {
            memcpy((char *)base + (il + ir) * width, (char *)right + ir * width, width);
            ++ir;
        }
    }
    --il;
    while (++il < imid)
        memcpy((char *)base + (il + ir) * width, (char *)left + il * width, width);
    --ir;
    while (++ir < nel - imid)
        memcpy((char *)base + (il + ir)* width, (char *)right + ir * width, width);
    free(left);
    free(right);
}

void ft_mergesort(void *base, size_t nel, size_t width,
                  int (*cmp)(const void *, const void *))
{
    if (1 >= nel)
        return ;
    ft_mergesort(base, nel / 2, width, cmp);
    ft_mergesort((char *)base + width * (nel / 2), nel - nel / 2, width, cmp);
    ft_merge(base, nel / 2, nel, width, cmp);
    }

#endif

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

void	ft_mergesort(void *base, size_t nel, size_t width,
                     int (*cmp)(void const *, void const *))
{
  void	*aux;

  aux = malloc(nel * width);
  _Mergesort(base, nel, width, cmp, aux);
  free(aux);
}
