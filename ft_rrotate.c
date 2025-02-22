#include "push_swap.h"


int get_position(t_stack_node *stack, int value)
{
    int position = 0;

    while (stack)
    {
        if (stack->data == value)
            return position;
        stack = stack->next;
        position++;
    }
    return -1; // Return -1 if the value is not found
}
t_stack_node *get_second_last_node(t_stack_node *stack)
{
    if (!stack || !stack->next) 
        return NULL; // No second last node if the stack is empty or has only one element

    while (stack->next && stack->next->next)
        stack = stack->next;

    return stack; // The node before the last one
}

void reverse_rotate(t_stack_node **stack, char stack_name)
{
    t_stack_node *last, *before_last;

    if (!stack || !*stack || !(*stack)->next)
        return;

    before_last = get_second_last_node(*stack);
    last = before_last->next;

    before_last->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;

    if (stack_name == 'a')
        write(1, "rra\n", 4);
    else if (stack_name == 'b')
        write(1, "rrb\n", 4);
}

void rotate_until_bottom(t_stack_node **stack, int value, char stack_name)
{
    int position = get_position(*stack, value);
    int stack_size = stack_len(*stack);

    if (position < stack_size / 2)
    {
        while (get_last(*stack)->data != value)
            rotate(stack, stack_name); // ra or rb
    }
    else
    {
        while (get_last(*stack)->data != value)
            reverse_rotate(stack, stack_name); // rra or rrb
    }
}

void rotate_until_top(t_stack_node **stack, int value, char stack_name)
{
    int position = get_position(*stack, value);
    int stack_size = stack_len(*stack);

    if (position <= stack_size / 2)
    {
        while ((*stack)->data != value)
            rotate(stack, stack_name); // ra or rb
    }
    else
    {
        while ((*stack)->data != value)
            reverse_rotate(stack, stack_name); // rra or rrb
    }
}
