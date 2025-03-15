/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:09:48 by hadia             #+#    #+#             */
/*   Updated: 2025/03/15 18:09:50 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack_node **a, char **av)
{
	int	i;
	int	data;

	i = 0;
	while (av[i])
	{
		if (!(ft_is_valid_number(av[i])))
			free_stack(a);
		data = ft_atoi(av[i]);
		if (!check_doubl(*a, data))
			free_stack(a);
		add_node(a, data);
		i++;
	}
}
