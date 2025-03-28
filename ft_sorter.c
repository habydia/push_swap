/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:26 by hvby              #+#    #+#             */
/*   Updated: 2025/03/28 16:07:50 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Aucun élément à comparer
 * a est le nouveau min
 * a est le nouveau max
 * a n'est ni le min ni le max
 */

/*Plus proche du min
 Plus proche du max */
int	get_closest_to_min_or_max(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*min_b;
	t_stack_node	*max_b;
	int				dist_min;
	int				dist_max;

	// if (!a || !b) //?
	// 	return (0);
	min_b = find_min(b);
	max_b = find_max(b);
	dist_min = abs(a->data - min_b->data);
	dist_max = abs(a->data - max_b->data);
	if (dist_min < dist_max)
		return (-1);
	return (1);
}

/* Keep smaller elements lower
 * Rotate only if we haven’t pushed enough
 * Move to the next chunk
 * Reset counter for next chunk */
void	parse_b(t_stack_node **a, t_stack_node **b, int size)
{
	int	min;
	int	pivot;
	int	pushed;
	int	chunk_size;

	chunk_size = size / 5;
	if (chunk_size < 1)
		chunk_size = 1;
	min = find_min(*a)->data;
	pivot = min + chunk_size;
	pushed = 0;
	while (stack_len(*a) > 3)
	{
		if ((*a)->data <= pivot)
		{
			handle_push_to_b(a, b, pivot, chunk_size);
			pushed++;
		}
		else
			handle_rotation(a, &pushed, &pivot, chunk_size);
	}
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

/* Push sorted chunks into `b`
 * Sort remaining 3 elements in `a`
 * Efficiently reintegrate sorted elements from `b` to `a`*/
void	sorter(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_len(*a);
	parse_b(a, b, size);
	little_sort(a);
	reintegrate_sorted(a, b);
}
