#include "push_swap.h"

//stack_sorted
int stack_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
//stack_len
int stack_len(t_stack_node *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void pb(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *temp;

    if (*a)
    {
        temp = *a;
        *a = (*a)->next;
        temp->next = *b;
        *b = temp;
    }
}

void pa(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *temp;

    if (*b)
    {
        temp = *b;
        *b = (*b)->next;
        temp->next = *a;
        *a = temp;
    }
}

void ra(t_stack_node **a)
{
    t_stack_node *temp;
    
    if (*a && (*a)->next)
    {
        temp = *a;
        *a = (*a)->next;
        temp->next = NULL;
        t_stack_node *last = *a;
        while (last->next)
            last = last->next;
        last->next = temp;
    }
}