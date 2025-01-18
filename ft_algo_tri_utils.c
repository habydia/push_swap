/*fonction instruction sa*/
/*fonction instruction sb*/
/*fonction instruction ss*/
/*fonction instruction pa*/
/*fonction instruction pb*/
/*fonction instruction ra*/
/*fonction instruction rb*/
/*fonction instruction rr*/
/*fonction instruction rrb*/
/*fonction instruction rrr*/
/*fonction creer pile b*/

#include "push_swap.h"


t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->elem_next)
	{
		lst = lst->elem_next;
	}
	return (lst);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		ft_lstlast(*lst)->elem_next = new;
	}
	else
		*lst = new;
}
void ft_create_pile(int )
{
	t_list *new_node;
	void *data;

	while (new_node)
	{
		data = pile_a->data;
		new_node = add_to_pile(data);
		ft_lstadd_back(&pile_a, new_node);
		pile_a = pile_a->elem_next;
	}
}
t_list *add_to_pile(void *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->elem_next = NULL;
	return (new);
}
void ajouter_contenu(t_list *pile_a, void (*f)(void *))
{
	t_list *current = pile_a;
	while (current != NULL)
	{
		f(current->data);
		current = current->elem_next;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->data);
	free(lst);
}
void increment(void *data)
{
	int *vanue = (int *)data;
	(*vanue)++;
}

/*t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*pile_a;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	pile_a = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&pile_a, del);
			return (NULL);
		}
		ft_lstadd_back(&pile_a, node);
		lst = lst->next;
	}
	return (pile_a);
}*/