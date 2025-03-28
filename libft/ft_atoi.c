/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:02:19 by hadia             #+#    #+#             */
/*   Updated: 2025/03/28 14:29:44 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sign(const char c, int *i)
{
	int	sign;

	sign = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = sign * -1;
		++(*i);
	}
	return (sign);
}

long	ft_atoi(const char *nptr)
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
		if ((r * sign) < INT_MIN || (r * sign) > INT_MAX)
		{
			return (r * sign);
		}
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * sign);
}
/*
int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1) {
		while (i < ac) {
			printf("FT\t====\t%i\n", ft_atoi(av[i]));
			printf("ATOI\t===\t%i\n", atoi(av[i]));
			printf("FT\t====\t%i\n", ft_atoi("\n\t -46"));
			printf("ATOI\t===\t%i\n", atoi("\n\t -46"));
			i++;
		}
	}
}
*/
