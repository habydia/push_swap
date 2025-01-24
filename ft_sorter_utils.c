#include "push_swap.h"

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

// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 	{
// 		lst = lst->next;
// 	}
// 	return (lst);
// }
// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	if (*lst)
// 	{
// 		ft_lstlast(*lst)-> next = new;
// 	}
// 	else
// 		*lst = new;
// }

t_stack_node *find_last_node(t_stack_node *stack) {
    while (stack && stack->next)
        stack = stack->next;
    return (stack);
}

void increment(void *data)
{
	int *value = (int *)data;
	(*value)++;
}
