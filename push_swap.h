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
static int	ft_count_word(char *s, char c);
static void	ft_free_tab(char **tab);
static int	write_split(char **tab, char const *s, char c);
int	ft_atoi(const char *nptr);
int static	ft_check_sign(const char c, int *i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_empty_substr(void);
size_t	ft_strlen(const char *s);
//function sort
void swap(t_stack_node **a);
void rra(t_stack_node **a);
void little_sort(t_stack_node *a);
#endif