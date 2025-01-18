/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:44:54 by hadia             #+#    #+#             */
/*   Updated: 2025/01/18 05:26:13 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

//fonction check argument valide
int check_doubl(char *av);
int	ft_isdigit(int c);
int check_input(char *av);
int ft_atoi(const char *nptr);

//fonction check pile sorted
int	ft_is_sort(int **pile);

//fonctions instruction 
void	do_sa(t_list *elem);
void	do_sb(t_list *elem);
void	do_ss(t_list *elema, t_list *elem);
void	do_pa(t_list **lst, t_list *elem);
void	do_pb(t_list **lst, t_list *elem);
void	do_ra(t_list **lst, t_list *elem);
void	do_rb(t_list **lst, t_list *elem);
void	do_rr(t_list **lst, t_list *elem);
void	do_rra(t_list **lst, t_list *elem);
void	do_rrb(t_list **lst, t_list *elem);
void	do_rrr(t_list **lst, t_list *elem);

//fonctions init
void	ft_create_pile(t_list *pile_a);
t_list				*add_to_pile(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));

//fonction algos de tri
int ft_sorter(t_list **pile_a, t_list **pile_b);
int ft_median(t_list **pile_a);
int ft_litlle_sort(t_list pile_a);
void increment(void *data);
//structure pile
typedef struct s_list
{
	int				data;
	struct s_list	*elem_next;
}					t_list;

#endif