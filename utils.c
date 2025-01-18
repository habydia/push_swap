
#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	r;
	long	sign;

	i = 0;
	r = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	sign = ft_check_sign(nptr[i], &i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((r * 10 + (nptr[i] - '0')) < r)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * sign);
}

