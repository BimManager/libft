#if 0

ft_assert.c

#endif

#include "libft.h" 

void	ft_assert(const char *expr, const char *file, int nline)
{
  ft_putstr("Assertion failed: (");
  ft_putstr(expr);
  ft_putstr("), file "); 
  ft_putstr(file);
  ft_putstr(", line ");
  ft_putnbr(nline);
  ft_putstr(".\n");
  exit(1);
}
