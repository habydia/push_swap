#include "push_swap.h"

//initialiation functions (creat pile...)

void init_stack_a(t_stack_node **a, char **av)
{
	int i = 0;
	int data;
	while (av[i])
	{
		if (!(ft_is_valid_number(av[i])))
			free_stack(a);
		data = ft_atoi(av[i]);
		if (!check_doubl(*a, data))
			free_stack(a);
		add_node(a, data);
		i++;
	}
}




