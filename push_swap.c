/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:44:47 by hadia             #+#    #+#             */
/*   Updated: 2025/02/06 17:54:36 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**av;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
		av = argv + 1;
	init_stack_a(&a, av);
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) <= 3)
			little_sort(&a);
		else
			sorter(&a, &b);
	}
	free_stack(&a);
	return (0);
}
