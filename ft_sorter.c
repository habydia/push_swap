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

void partition(t_stack_node **a, t_stack_node **b, int pivot)
{
    int len = stack_len(*a);
    int pushed = 0;
    int limit = len - 3;  // Leave last 3 elements
    int max_it = len * 2;
    int it = 0;
    while (pushed < limit && it < max_it)
    {
        if (!(*a)) 
            break;

        if ((*a)->data <= pivot)
        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a);
        it++;
    }
    while(len - pushed > 3)
    {
        pb(a, b);
        pushed++;
    }
}

int find_pivot(t_stack_node *a) 
{
    if (!a) return 0;

    int len = stack_len(a);
    int mid = len / 2;
    t_stack_node *current = a;

    for (int i = 0; i < mid; i++)
        current = current->next;  

    return current->data;  // Closer to a median choice
}

static void insert_sorted(t_stack_node **a, t_stack_node *node)
{
    if (!(*a) || (*a)->data >= node->data) {
        node->next = *a;
        if (*a) {
            (*a)->prev = node;
        }
        *a = node;
    } else {
        t_stack_node *current = *a;
        while (current->next && current->next->data < node->data) {
            current = current->next;
        }
        node->next = current->next;
        if (current->next) {
            current->next->prev = node;
        }
        current->next = node;
        node->prev = current;
    }
}

// Sort the stack a with elements from stack b
void stack_sorter(t_stack_node **a, t_stack_node **b) 
{
    // Find pivot
    int pivot = find_pivot(*a);
    partition(a, b, pivot);  // Partition based on pivot
    little_sort(a);  // Sort remaining 3 elements in a
    // Reinsert elements from b into a in sorted order
    while (*b)
    {
        t_stack_node *temp = *b;
        *b = (*b)->next;
        temp->next = NULL;  // Detach node from b

        insert_sorted(a, temp);
    }
}


// void stack_sorter(t_stack_node **a, t_stack_node **b) 
// {
//     int pivot;

//     if (!a || !(*a))
//         return;
        
//     if (stack_len(*a) <= 3)
//     {
//         little_sort(a);
//         return;
//     }

//     pivot = find_pivot(*a);
//     partition(a, b, pivot);

//     little_sort(a);  // Sort remaining 3 numbers in A

//     while (*b)
//     {
//         pa(a, b);
//         if ((*a)->data > (*a)->next->data) // Ensure order
//             sa(a);
//     }
// }

