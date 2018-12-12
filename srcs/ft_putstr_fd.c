#if 0

ft_putstr_fd.c

#endif

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
  while (*s)
    write(fd, s++, 1);
}
