/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:26 by hvby              #+#    #+#             */
/*   Updated: 2025/04/12 12:13:58 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_stacks(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp;

	write(2, "Stack A: ", 9);
	tmp = a;
	while (tmp)
	{
		ft_putnbr_fd(tmp->data, 2);
		write(2, " ", 1);
		tmp = tmp->next;
	}
	write(2, "\nStack B: ", 10);
	tmp = b;
	while (tmp)
	{
		ft_putnbr_fd(tmp->data, 2);
		write(2, " ", 1);
		tmp = tmp->next;
	}
	write(2, "\n", 1);
}

/*
 * Aucun élément à comparer
 * a est le nouveau min
 * a est le nouveau max
 * a n'est ni le min ni le max
 */

/* Keep smaller elements lower
 * Rotate only if we haven’t pushed enough
 * Move to the next chunk
 * Reset counter for next chunk */
void parse_b(t_stack_node **a, t_stack_node **b)
{
int size = stack_len(*a);
int chunk_count = 0;
int total_chunks = 5;
int min_val, max_val, range;
int bounds[2];

min_val = find_min(*a)->data;
max_val = find_max(*a)->data;
range = max_val - min_val;

while (stack_len(*a) > 3)
{
bounds[0] = min_val + (range * chunk_count / total_chunks);
bounds[1] = min_val + (range * (chunk_count + 1) / total_chunks);

if (process_chunk(a, b, bounds, &size))
chunk_count++;

if (chunk_count >= total_chunks && stack_len(*a) > 3)
handle_remaining(a, b, &size);
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
	parse_b(a, b);
	little_sort(a);
	reintegrate_sorted(a, b);
}
