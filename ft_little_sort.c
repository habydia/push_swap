/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:47 by hvby              #+#    #+#             */
/*   Updated: 2025/03/28 14:44:49 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	handle_rotation(t_stack_node **a, int *pushed, int *pivot,
		int chunk_size)
{
	if (*pushed < chunk_size)
		rotate(a, 'a');
	else
	{
		*pivot += chunk_size;
		*pushed = 0;
	}
}

void	little_sort(t_stack_node **a)
{
	if (stack_len(*a) == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
		return ;
	}
	if ((*a)->data > (*a)->next->data && (*a)->data > find_last_node(*a)->data)
		rotate(a, 'a');
	if ((*a)->next->data > find_last_node(*a)->data)
		reverse_rotate(a, 'a');
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
