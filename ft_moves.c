/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:44 by hvby              #+#    #+#             */
/*   Updated: 2025/03/06 21:22:55 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a)
{
	t_stack_node	*temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = temp;
	(*a)->prev = NULL;
	(*a)->next = temp;
	temp->prev = *a;
	write(1, "sa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
	write(1, "pb\n", 3);
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
	write(1, "pa\n", 3);
}

void	rotate(t_stack_node **stack, char stack_name)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	else if (stack_name == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack_node **stack, char stack_name)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	before_last = get_second_last_node(*stack);
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else if (stack_name == 'b')
		write(1, "rrb\n", 4);
}
