/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:10:41 by hadia             #+#    #+#             */
/*   Updated: 2025/03/15 18:10:43 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
