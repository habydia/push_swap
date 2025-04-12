/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:24:30 by Hadia             #+#    #+#             */
/*   Updated: 2025/04/12 12:28:11 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_one_element(t_stack_node **a, t_stack_node **b, int bounds[2],
		int *size)
{
	if ((*a)->data >= bounds[0] && (*a)->data <= bounds[1])
	{
		pb(a, b);
		(*size)--;
		return (1);
	}
	else
	{
		rotate(a, 'a');
		return (0);
	}
}

int	process_chunk(t_stack_node **a, t_stack_node **b, int bounds[2], int *size)
{
	int	full_rotation;
	int	pushed_in_chunk;
	int	original_size;
	int	elements_per_chunk;

	full_rotation = 0;
	pushed_in_chunk = 0;
	original_size = *size;
	elements_per_chunk = original_size / 5;
	if (elements_per_chunk < 1)
		elements_per_chunk = 1;
	while (full_rotation < original_size && stack_len(*a) > 3)
	{
		if (process_one_element(a, b, bounds, size))
			pushed_in_chunk++;
		else
			full_rotation++;
		if (pushed_in_chunk >= elements_per_chunk
			|| full_rotation >= original_size)
		{
			return (1);
		}
	}
	return (0);
}

void	handle_remaining(t_stack_node **a, t_stack_node **b, int *size)
{
	int	min_pos;

	while (stack_len(*a) > 3)
	{
		min_pos = get_position(*a, find_min(*a)->data);
		move_to_position(a, min_pos, 'a');
		pb(a, b);
		(*size)--;
	}
}
