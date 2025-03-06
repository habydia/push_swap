/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:47 by hvby              #+#    #+#             */
/*   Updated: 2025/03/06 21:29:21 by Hadia            ###   ########.fr       */
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
