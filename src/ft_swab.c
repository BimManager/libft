









#include "libft.h"

void	ft_swab(const void *src, void *dst, size_t nbytes)
{
	if (nbytes & 1)
		nbytes -= 1;
	while (nbytes--)
	{
		*((char *)dst + nbytes) = *((char *)src + nbytes - 1);
		*((char *)dst + nbytes - 1) = *((char *)src + nbytes);
		--nbytes;
	}
}
