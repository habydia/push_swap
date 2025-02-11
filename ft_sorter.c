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

int find_max_position(t_stack_node *stack)
{
    t_stack_node *current = stack;
    int max = INT_MIN;
    int pos = 0;
    int max_pos = 0;
    
    while (current)
    {
        if (current->data > max)
        {
            max = current->data;
            max_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return max_pos;
}

void find_best_move(t_stack_node *b, int *moves, int *reverse)
{
    int size = stack_len(b);
    int max_pos = find_max_position(b);
    
    if (max_pos <= size / 2)
    {
        *moves = max_pos;
        *reverse = 0;
    }
    else
    {
        *moves = size - max_pos;
        *reverse = 1;
    }
}

int find_median(t_stack_node *a)
{
    int *arr;
    int len;
    int median;
    int i;
    t_stack_node *tmp;

    len = stack_len(a);
    arr = malloc(sizeof(int) * len);
    i = 0;
    tmp = a;
    
    while (tmp)
    {
        arr[i++] = tmp->data;
        tmp = tmp->next;
    }
    
    // Tri simple du tableau
    for (i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    median = arr[len / 2];
    free(arr);
    return median;
}

void stack_sorter(t_stack_node **a, t_stack_node **b)
{
    int median;
    int push_count;
    int len;

    while (stack_len(*a) > 3)
    {
        median = find_median(*a);
        len = stack_len(*a);
        push_count = 0;

        // Pousse tous les nombres inférieurs à la médiane vers B
        while (push_count < len / 2)
        {
            if ((*a)->data < median)
            {
                pb(a, b);
                push_count++;
            }
            else
                ra(a);
        }
    }

    // Trie les 3 derniers nombres dans A
    little_sort(a);

    // Ramène les nombres de B vers A dans l'ordre
    while (*b)
    {
        int max_pos = find_max_position(*b);
        int size = stack_len(*b);
        
        // Faire la rotation en une seule fois avec rb ou rrb
        if (max_pos <= size / 2)
        {
            while (max_pos--)
                rb(b);
        }
        else
        {
            int moves = size - max_pos;
            while (moves--)
                rrb(b);
        }
        pa(a, b);
    }
}