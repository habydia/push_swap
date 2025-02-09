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
    int pushed = 0, rotated = 0;
    int limit = len - 3;  // Leave last 3 elements

    while (pushed < limit)
    {
        if (!(*a)) 
            break;

        if ((*a)->data <= pivot)
        {
            pb(a, b);
            pushed++;
        }
        else
        {
            ra(a);
            rotated++;
        }
    }

    // Restore order in A
    while (rotated-- > 0)
        rra(a);
}

int find_pivot(t_stack_node *a) 
{
    if (!a) return 0;

    t_stack_node *slow = a, *fast = a;

    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;  // Pivot is the middle element
}

void stack_sorter(t_stack_node **a, t_stack_node **b) 
{
    int pivot;

    if (!a || !(*a))
        return;
        
    if (stack_len(*a) <= 3)
    {
        little_sort(a);
        return;
    }

    pivot = find_pivot(*a);
    partition(a, b, pivot);

    little_sort(a);  // Sort remaining 3 numbers in A

    while (*b)
    {
        pa(a, b);
        if ((*a)->data > (*a)->next->data) // Ensure order
            sa(a);
    }
}
