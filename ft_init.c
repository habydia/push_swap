#include "push_swap.h"

//initialiation functions (creat pile...)

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else 
		return (0);
}

int is_valid_number(char *av)
{
	int i;
	long n;

	i = 0;
	if(av[i] == '-' || av[i] == '+')
		i++;
	while(av[i])
	{
		if (!is_digit(av[i]))
			return (0);
		i++;
	}
	n = ft_atoi(av);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

t_stack_node *find_last_node(t_stack_node *stack) {
    while (stack && stack->next)
        stack = stack->next;
    return (stack);
}

void free_stack(t_stack_node **stack) {
    t_stack_node *temp;
    while (*stack) {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

void add_node(t_stack_node **stack, int n)
{
	t_stack_node *new_node;
	t_stack_node *last_node;

	if (!stack)
		return ;
		new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = n;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else 
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

int check_doubl(t_stack_node *stack, int n) {
    t_stack_node *current = stack;

    while (current) {
        if (current->data == n)
            return (0); // Doublon détecté
        current = current->next;
    }
    return (1); // Aucun doublon
}

void init_stack_a(t_stack_node **a, char **av)
{
	int i = 0;
	int data;
	while (av[i])
	{
		if (!(is_valid_number(av[i])))
			free_stack(a);
		data = ft_atoi(av[i]);
		if (!check_doubl(*a, data))
			free_stack(a);
		add_node(a, data);
		i++;
	}
}




