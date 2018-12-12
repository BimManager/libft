#if 0

ft_putendl_fd.c

#endif

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
  while (*s)
    write(fd, s++, 1);
  write(fd, "\n", 1);
}
