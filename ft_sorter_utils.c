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

/*void increment(void *data)*/
