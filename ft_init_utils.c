/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:57 by hvby              #+#    #+#             */
/*   Updated: 2025/03/27 16:39:20 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_number(char *av)
{
	int		i;
	long	n;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!av[i])
		return (0);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
		{
			return (0);
		}
		i++;
	}
	n = ft_atoi(av);
	if (n < INT_MIN || n > INT_MAX)
	{
		return (0);
	}
	return (1);
}

void	add_node(t_stack_node **stack, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = n;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

int	check_doubl(t_stack_node *stack, int n)
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		if (current->data == n)
			return (0);
		current = current->next;
	}
	return (1);
}
