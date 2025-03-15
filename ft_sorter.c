#include "push_swap.h"

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;

	min_node = stack;
	while (stack)
	{
		if (stack->data < min_node->data)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;

	max_node = stack;
	while (stack)
	{
		if (stack->data > max_node->data)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void	handle_push_to_b(t_stack_node **a, t_stack_node **b, int threshold,
		int *pushed, int *rotations)
{
	pb(a, b);
	(*pushed)++;
	*rotations = 0;
	if (*b && stack_len(*b) > 1 && (*b)->data < threshold)
		rotate(b, 'b');
}

void	handle_rotation_or_pivot(t_stack_node **a, int *pivot, int *pushed,
		int *rotations, int chunk_size)
{
	if (*pushed < chunk_size && *rotations < stack_len(*a))
	{
		rotate(a, 'a');
		(*rotations)++;
	}
	else
	{
		*pivot += chunk_size;
		*pushed = 0;
		*rotations = 0;
	}
}

void	parse_b(t_stack_node **a, t_stack_node **b, int size)
{
	int	chunk_size;
	int	pivot;
	int	pushed;
	int	rotations;

	chunk_size = size / 5;
	if (chunk_size == 0)
		chunk_size = 1;
	pivot = find_min(*a)->data + chunk_size;
	pushed = 0;
	rotations = 0;
	while (stack_len(*a) > 3)
	{
		if ((*a)->data <= pivot)
			handle_push_to_b(a, b, pivot - (chunk_size / 2), &pushed,
				&rotations);
		else
			handle_rotation_or_pivot(a, &pivot, &pushed, &rotations,
				chunk_size);
	}
}

int	calculate_move_cost(t_stack_node *a, t_stack_node *b, int value)
{
	int	pos_in_a;
	int	pos_in_b;
	int	len_a;
	int	len_b;
	int	move_b;
	int	move_a;

	pos_in_a = find_best_insert_position(a, value);
	pos_in_b = get_position(b, value);
	len_a = stack_len(a);
	len_b = stack_len(b);
	if (pos_in_b <= len_b / 2)
	{
		move_b = pos_in_b;
	}
	else
	{
		move_b = len_b - pos_in_b;
	}
	if (pos_in_a <= len_a / 2)
	{
		move_a = pos_in_a;
	}
	else
	{
		move_a = len_a - pos_in_a;
	}
	return (move_a + move_b);
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

void	move_to_position(t_stack_node **stack, int pos, char stack_name)
{
	int	len;
	int	half;

	len = stack_len(*stack);
	if (pos == 0)
		return ;
	half = len / 2;
	if (pos <= half)
	{
		while (pos-- > 0)
			rotate(stack, stack_name);
	}
	else
	{
		pos = len - pos;
		while (pos-- > 0)
			reverse_rotate(stack, stack_name);
	}
}

void	reintegrate_sorted(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best;

	while (*b)
	{
		best = find_best_element_to_move(*a, *b);
		move_to_position(b, get_position(*b, best->data), 'b');
		move_to_position(a, find_best_insert_position(*a, best->data), 'a');
		pa(a, b);
	}
	rotate_until_top(a, find_min(*a)->data, 'a');
}

void	sorter(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_len(*a);
	parse_b(a, b, size);
	little_sort(a);
	reintegrate_sorted(a, b);
}
