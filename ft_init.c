
#include "push_swap.h"

void ft_create_pile(t_list pile_a, int argv)
{
}
t_list	*add_to_pile(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = content;
	new->elem_next = NULL;
	return (new);
}
// pile_a = ft_create_pile(/*param*/);