/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:44:47 by hadia             #+#    #+#             */
/*   Updated: 2025/03/29 07:47:16 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(int argc, char **argv, int *s_flag)
{
	char	**av;

	*s_flag = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	else if (argc == 2)
	{
		*s_flag = 1;
		av = ft_split(argv[1], ' ');
	}
	else
		av = argv + 1;
	return (av);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**av;
	int				s_flag;

	a = NULL;
	b = NULL;
	s_flag = 0;
	av = parse_args(argc, argv, &s_flag);
	if (!av)
		return (1);
	init_stack_a(&a, av);
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) <= 3)
			little_sort(&a);
		else
			sorter(&a, &b);
	}
	free_stack(&a);
	if (s_flag)
		ft_free_tab(av);
	return (0);
}
