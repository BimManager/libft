









#include "libft.h"

int	ft_kadane(int *arr, int n)
{
	int	cur_max;
	int	max;
	int	i;

	cur_max = arr[0];
	max = arr[0];
	i = 0;
	while (++i < n)
	{
		cur_max = FT_MAX(arr[i], cur_max + arr[i]);
		max = FT_MAX(max, cur_max);
	}
	return (max);
}
