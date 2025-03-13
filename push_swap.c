/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:44:47 by hadia             #+#    #+#             */
/*   Updated: 2025/03/13 22:37:18 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->data);
		stack = stack->next;
	}
	printf("NULL\n");
}
int main(int argc, char **argv)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;
    char **av;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return 1;
    else if (argc == 2)
        av = ft_split(argv[1], ' ');  // Assuming ft_split is defined elsewhere
    else 
        av = argv + 1;
    init_stack_a(&a, av);  // Assuming init_stack_a is defined elsewhere

    printf("Initial stack:\n");
    print_stack(a);

    if (!stack_is_sorted(a))
    {
        if (stack_len(a) <= 3)
            little_sort(&a);
        else
            sorter(&a, &b);
    }

    printf("Stack sorted:\n");
    print_stack(a);

    free_stack(&a);
    return 0;
}