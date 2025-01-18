/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:09:39 by hadia             #+#    #+#             */
/*   Updated: 2025/01/18 03:30:21 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* fonction check argument valide
	si aucun param, rien afficher et rendre invite de commande
	si param invalide 
		pas un nombre
		ne tiens pa dans un int
		est un doublon
		,afficher "Error"


*/
int is_number(char *av)
{
	if (ft_atoi(av[1]) >= INT_MIN && ft_atoi(av[1]) <= INT_MAX)
		return (1);
	else
		return (0);
}
int check_doubl(char *av)
{
	int i;
	int j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (av[i] == av[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else 
		return (0);
}

int check_input(char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]) && av[i] != ' ')
			return (0);
		i++;
	}
	if (!check_doubl(av))
		return (0);
	return (1);
}

