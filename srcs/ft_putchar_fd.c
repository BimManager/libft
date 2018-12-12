#if 0

ft_putchar_fd.c

#endif

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}
