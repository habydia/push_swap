/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:28:33 by hadia             #+#    #+#             */
/*   Updated: 2025/02/06 17:19:50 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void partition(t_stack_node **a, t_stack_node **b, int pivot)
// {
//     while (*a)
//     {
//         if ((*a)->data < pivot)
//             pb(a, b);
//         else
//             ra(a);
//     }
// }

void partition(t_stack_node **a, t_stack_node **b, int pivot)
{
    int len = stack_len(*a);
    int pushed = 0;
    int rotated = 0;

    for (int i = 0; i < len; i++)
    {
        if ((*a)->data < pivot)
        {
            pb(a, b); // Push to B if less than pivot
            pushed++;
        }
        else
        {
            ra(a); // Rotate A
            rotated++;
        }
    }

    // Undo unnecessary rotations
    while (rotated--)
        rra(a);
}

int find_pivot(t_stack_node *a)
{
    if (!a)
        return 0;
    return a->data;  
}

void stack_sorter(t_stack_node **a, t_stack_node **b)
{
    int pivot;

    if (stack_len(*a) <= 3)
    {
        return(little_sort(a));
    }

    pivot = find_pivot(*a);
    partition(a, b, pivot);

    if (*a)
        stack_sorter(a, b);
    if (*b)
        stack_sorter(b, a);
    
    while (*b)
        pa(a, b);
}