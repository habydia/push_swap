/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <Hadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:53:53 by hvby              #+#    #+#             */
/*   Updated: 2025/03/27 17:32:27 by Hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
 * Aucun élément à comparer
 * a est le nouveau min
 * a est le nouveau max
 * a n'est ni le min ni le max
 */
int	is_next_min_or_max(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*min_b;
	t_stack_node	*max_b;

	if (!a || !b)
		return (0);
	min_b = find_min(b);
	max_b = find_max(b);
	if (a->data < min_b->data)
		return (-1);
	if (a->data > max_b->data)
		return (1);
	return (0);
}

int	calculate_move_cost(t_stack_node *a, t_stack_node *b, int value)
{
	int	pos_in_a;
	int	pos_in_b;
	int	move_b;
	int	move_a;

	pos_in_a = find_best_insert_position(a, value);
	pos_in_b = get_position(b, value);
	if (pos_in_b <= stack_len(b) / 2)
		move_b = pos_in_b;
	else
		move_b = stack_len(b) - pos_in_b;
	if (pos_in_a <= stack_len(a) / 2)
		move_a = pos_in_a;
	else
		move_a = stack_len(a) - pos_in_a;
	return (move_a + move_b);
}

/*
initialiation functions (creat pile...)
*/
void	init_stack_a(t_stack_node **a, char **av)
{
	int	i;
	int	data;

	i = 0;
	while (av[i])
{
    if (!(ft_is_valid_number(av[i])))
    {
        write(2, "Error\n", 6);
        free_stack(a);
        exit(1);
    }
    data = ft_atoi(av[i]);
    if (!check_doubl(*a, data))
    {
        write(2, "Error\n", 6);
        free_stack(a);
        exit(1);
    }
    add_node(a, data);
    i++;
}
}
