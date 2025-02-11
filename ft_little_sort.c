#include "push_swap.h"

void sa(t_stack_node **a)
{
    t_stack_node *temp;

    if (!a || !*a || !(*a)->next)
        return;

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
//check 
void rra(t_stack_node **a)
{
    t_stack_node *last;
    t_stack_node *before_last;

    if (!a || !*a || !(*a)->next)
        return;

    last = find_last_node(*a);
    before_last = *a;

    while (before_last->next != last)
        before_last = before_last->next;

    before_last->next = NULL;
    last->next = *a;
    last->prev = NULL;
    (*a)->prev = last;
    *a = last;

    write(1, "rra\n", 4);
}

void rrb(t_stack_node **b)
{
    t_stack_node *last;
    t_stack_node *before_last;

    if (!b || !*b || !(*b)->next)
        return;

    last = find_last_node(*b);
    before_last = *b;

    while (before_last->next != last)
        before_last = before_last->next;

    before_last->next = NULL;
    last->next = *b;
    last->prev = NULL;
    (*b)->prev = last;
    *b = last;

    write(1, "rrb\n", 4);
}

void little_sort(t_stack_node **a)
{
    if (stack_len(*a) == 2) 
    {
        if ((*a)->data > (*a)->next->data)
            sa(a);
        return;
    }

    if ((*a)->data > (*a)->next->data && (*a)->data > find_last_node(*a)->data)
        ra(a); 
    if ((*a)->next->data > find_last_node(*a)->data)
        rra(a); 
    if ((*a)->data > (*a)->next->data)
        sa(a); 
}
