#include "push_swap.h"

void swap(t_stack_node **a)
{
	t_stack_node *temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}


//check 
void rra(t_stack_node **a)
{
	t_stack_node *last;
	t_stack_node *before_last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = find_last_node(*a);
	before_last = *a;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *a;
	*a = last;
}
void little_sort(t_stack_node *a)
{
	while(a && a->next)
	{
		if (a->data > a->next->data)
			swap(&a);
		else if (a->data > find_last_node(a)->data)
			rra(&a);
			a = a->next;
	}
}


//little_sort
//function to call for lttle sort