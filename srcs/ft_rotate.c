#if 0

ft_rotate.c

#endif

#include "libft.h"

void	ft_rotate(void *front, void *middle, void *end)
{
  void		*buf;
  size_t	frontSize;
  size_t	backSize;

  frontSize = (char *)middle - (char *)front;
  backSize = (char *)end - (char *)middle;
  buf = malloc(frontSize * sizeof(char));
  if (!buf)
    return ;
  ft_memcpy(buf, front, frontSize);
  ft_memmove(front, middle, backSize);
  ft_memcpy((char *)end - frontSize, buf, frontSize);
  free(buf);
}
