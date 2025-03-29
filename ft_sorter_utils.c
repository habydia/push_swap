/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:36 by hvby              #+#    #+#             */
/*   Updated: 2025/03/29 07:39:13 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack_sorted
int	stack_is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node	*find_best_element_to_move(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*best;
	t_stack_node	*current;
	int				min_cost;
	int				cost;

	best = b;
	current = b;
	min_cost = calculate_move_cost(a, b, current->data);
	while (current)
	{
		cost = calculate_move_cost(a, b, current->data);
		if (cost < min_cost)
		{
			min_cost = cost;
			best = current;
		}
		current = current->next;
	}
	return (best);
}

t_stack_node	*get_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// stack_len
int	stack_len(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	handle_push_to_b(t_stack_node **a, t_stack_node **b, int pivot,
		int chunk_size)
{
	pb(a, b);
	if (*b && stack_len(*b) > 1 && (*b)->data < pivot - (chunk_size / 2))
		rotate(b, 'b');
}
