/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:41 by hvby              #+#    #+#             */
/*   Updated: 2025/03/06 21:22:28 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Case 1: If value is smaller than the smallest element, insert before min
 * Case 2: If value is larger than the largest element, insert after max
 * Case 3: Find position between two elements */

int	find_best_insert_position(t_stack_node *a, int value)
{
	int				best_pos;
	int				index;
	t_stack_node	*current;
	t_stack_node	*min_node;
	t_stack_node	*max_node;

	if (!a)
		return (0);
	best_pos = 0;
	index = 0;
	current = a;
	min_node = find_min(a);
	max_node = find_max(a);
	if (value < min_node->data)
		return (get_position(a, min_node->data));
	if (value > max_node->data)
		return ((get_position(a, max_node->data) + 1) % stack_len(a));
	while (current->next)
	{
		if (current->data < value && current->next->data > value)
			return (index + 1);
		index++;
		current = current->next;
	}
	return (best_pos);
}

/* Return -1 if the value is not found */

int	get_position(t_stack_node *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->data == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

/* No second last node if the stack is empty or has only one element
The node before the last one */
t_stack_node	*get_second_last_node(t_stack_node *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	rotate_until_bottom(t_stack_node **stack, int value, char stack_name)
{
	int	position;
	int	stack_size;

	position = get_position(*stack, value);
	stack_size = stack_len(*stack);
	if (position < stack_size / 2)
	{
		while (get_last(*stack)->data != value)
			rotate(stack, stack_name);
	}
	else
	{
		while (get_last(*stack)->data != value)
			reverse_rotate(stack, stack_name);
	}
}

/*
 Minimize rotation count by picking the best direction
*/
void	rotate_until_top(t_stack_node **stack, int value, char stack_name)
{
	int	position;
	int	stack_size;
	int	half;

	position = get_position(*stack, value);
	stack_size = stack_len(*stack);
	half = stack_size / 2;
	if (position <= half)
	{
		while ((*stack)->data != value)
			rotate(stack, stack_name);
	}
	else
	{
		while ((*stack)->data != value)
			reverse_rotate(stack, stack_name);
	}
}
