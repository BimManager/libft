#include "libft.h"

double	ft_pow(double x, int n)
{
	double	tmp;

	if (!n)
		return (1.0);
	tmp = ft_pow(x, n / 2);
	if (n & 1)
	{
		if (n > 0)
			return (tmp * tmp * x);
		return (tmp * tmp / x);
	}
	return (tmp * tmp);
}
