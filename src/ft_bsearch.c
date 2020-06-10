









#include "libft.h"

void	*ft_bsearch(const void *key, const void *base, size_t nel,
					size_t width, int (*cmp)(const void *, const void *))
{
	int	left;
	int	right;
	int	mid;
	int	res;

	if (!nel)
		return (NULL);
	left = 0;
	right = nel - 1;
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);
		res = cmp((char *)base + width * mid, key);
		if (!res)
			return ((char *)base + width * mid);
		else if (0 < res)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (NULL);
}
