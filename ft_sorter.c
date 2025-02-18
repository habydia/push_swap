#include "push_swap.h"

void ft_find_median(t_stack_node *a, int *pivoit)
{
    int size = stack_len(a);
    *pivoit = size / 2;
}

void index_stack(t_stack_node *stack)
{
    t_stack_node *tmp = stack;
    int i = 0;
    int median = (int)ft_find_median(stack, &median);

    while(tmp)
    {
        tmp->index = i;
        if (i <= median)
        return(1);
        else
        return (0);
        tmp = tmp->next;
        i++;

    }
}

ft_find_max(t_stack_node *stack)
{
    t_stack_node *tmp = stack;
    int max = INT_MIN;

    while(tmp)
    {
        if (tmp->data > max)
            max = tmp->data;
        tmp = tmp->next;
    }
    return (max);
}

ft_find_min(t_stack_node *stack, int *match)
{
    t_stack_node *tmp = stack;
    int min = INT_MAX;

    while(tmp)
    {
        if (tmp->data < min)
            min = tmp->data;
        tmp = tmp->next;
    }
    *match = min;
    return (min);
}

void target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *tmp;
    t_stack_node *target_node;
    int match;
    
    while(a)
    {
        tmp = b;
        match = ft_find_min(a, &match);
        while(tmp)
        {
            if (tmp->data < a->data && tmp->data > match)
            {
                match = tmp->data;
                target_node = tmp;
            }
            tmp = tmp->next;
        }
        if (match != INT_MAX)
            a->target_node = target_node;
        a = a->next;
    }
}

void cost_analysis(t_stack_node *a, t_stack_node *b)
{
    int size_a = stack_len(a);
    int size_b = stack_len(b);
    int cost = 0;

    while(a)
    {
        a->push_cost = a ->index;
        if (!(index_stack(a))== 1)
            a->push_cost = size_a - a->index;
        if ((index_stack(a))== 0)
            a->push_cost += a->target_node->index;
        else
            a->push_cost += size_b -
        a = a->next;
    }
}

void set_cheapest(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *tmp = a;
    t_stack_node *cheapest = a;
    int min_cost = INT_MAX;

    while(tmp)
    {
        if (tmp->push_cost < min_cost)
        {
            min_cost = tmp->push_cost;
            cheapest = tmp;
        }
        tmp = tmp->next;
    }
    if (cheapest->index < stack_len(a) - cheapest->index)
        while(a != cheapest)
            ra(&a);
    else
        while(a != cheapest)
            rra(&a);
    pb(&a, &b);
}

void big_sorter(t_stack_node **a, t_stack_node **b)
{
    int size_a = stack_len(*a);

    int pivoit = ft_find_pivot(*a, &pivoit);

    if (size_a <= 3 && !stack_is_sorted(*a))
        little_sort(a);
    while(size_a > 3 && !stack_is_sorted(*a))
    { 
        partition(a, b, pivoit);
    }
    while(*b)
    {
            pa(a, b);
            //Insérer progressivement les éléments de b au bon endroit dans a.
            //éinjecter les éléments dans a en utilisant des rotations (rb, rrb) pour garder l’ordre. Utiliser des rotations intelligentes pour éviter de trop bouger les éléments.
    }
}