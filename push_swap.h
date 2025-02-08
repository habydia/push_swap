/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:44:54 by hadia             #+#    #+#             */
/*   Updated: 2025/02/06 18:03:38 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int				data;
	int				index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}					t_stack_node;

//function check input
int ft_is_valid_number(char *av);
int check_doubl(t_stack_node *stack, int n);
//function initialisation pile

//function initialisation node
void add_node(t_stack_node **stack, int n);
void init_stack_a(t_stack_node **a, char **av);
//function utils
t_stack_node *find_last_node(t_stack_node *stack);
void free_stack(t_stack_node **stack);
int stack_len(t_stack_node *stack);
int stack_sorted(t_stack_node *stack);

char	**ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_empty_substr(void);
size_t	ft_strlen(const char *s);

//function sort
void sa(t_stack_node **a);
void ra(t_stack_node **a);
void rra(t_stack_node **a);
void pb(t_stack_node **a, t_stack_node **b);
void pa(t_stack_node **a, t_stack_node **b);
void little_sort(t_stack_node **a);
int find_median(t_stack_node *a);
void stack_sorter(t_stack_node **a, t_stack_node **b);
//function debug
void print_stack(t_stack_node *stack);
#endif