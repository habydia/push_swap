/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:44:47 by hadia             #+#    #+#             */
/*   Updated: 2025/01/18 05:10:18 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*fonctions
check argument valide
fonction check pile a dans ordre croissant
fonction creer pile b
fonction algo de tri
*/


// int	ft_is_sort(int **pile)
// {
// 	while ()
// 	{
		
// 	}
// }
static void push_swap( t_list **pile_a, t_list **pile_b)
{
	ft_create_pile(*pile_a);
	pile_b = NULL;
	//fonction check pile a dans ordre croissant
	if (!ft_is_sort(pile_a))
		ft_sorter(pile_a, pile_b);
}

int main(int argc, char **av)
 {

		t_list *pile_a;
		t_list *pile_b;

		pile_b = NULL;
		if (argc < 2)
			return(NULL);
		if(argc >= 2)
		{
			if (!check_input(av[1]))
				write(1, "Error\n", 6);

			else
				push_swap(pile_a, pile_b);
		}
		return (0);
}