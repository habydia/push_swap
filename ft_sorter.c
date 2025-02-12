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
int find_pivot(t_stack_node *stack)
{
    int min;
    int max;
    t_stack_node *current;

    if (!stack)
        return (0);

    // Trouve min et max
    min = stack->data;
    max = stack->data;
    current = stack;
    
    while (current)
    {
        if (current->data < min)
            min = current->data;
        if (current->data > max)
            max = current->data;
        current = current->next;
    }

    // Retourne la valeur approximative du milieu
    return (min + ((max - min) / 2));
}
void stack_sorter(t_stack_node **a, t_stack_node **b)
{
    int pivot;
    int len;

    len = stack_len(*a);
    while (len > 3)
    {
        pivot = find_pivot(*a);
        
        // Compte combien d'éléments sont sous le pivot
        int count = 0;
        t_stack_node *tmp = *a;
        while (tmp)
        {
            if (tmp->data <= pivot)
                count++;
            tmp = tmp->next;
        }

        // Push les éléments inférieurs au pivot vers B
        int pushed = 0;
        while (pushed < count && len > 3)
        {
            if ((*a)->data <= pivot)
            {
                pb(a, b);
                pushed++;
                len--;
            }
            else
                ra(a);
        }
    }

    // Trie les 3 derniers éléments
    little_sort(a);

    // Ramène les éléments de B vers A
    while (*b)
    {
        int best_move = INT_MAX;
        // int best_ra = 0;
        int best_rb = 0;
        
        // Trouve la position optimale
        t_stack_node *tmp_b = *b;
        int i = 0;
        while (tmp_b)
        {
            int moves = i;
            if (i > stack_len(*b) / 2)
                moves = stack_len(*b) - i;
            
            if (moves < best_move)
            {
                best_move = moves;
                best_rb = i;
            }
            tmp_b = tmp_b->next;
            i++;
        }

        // Exécute les mouvements optimaux
        if (best_rb <= stack_len(*b) / 2)
            while (best_rb--)
                rb(b);
        else
        {
            best_rb = stack_len(*b) - best_rb;
            while (best_rb--)
                rrb(b);
        }
        
        pa(a, b);
    }
}