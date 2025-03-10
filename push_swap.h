/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:44:54 by hadia             #+#    #+#             */
/*   Updated: 2025/03/10 14:23:00 by Hadia            ###   ########.fr       */
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
	int				pos;
	struct s_stack_node	*target_pos;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}					t_stack_node;

int ft_is_valid_number(char *av);
int check_doubl(t_stack_node *stack, int n);



void add_node(t_stack_node **stack, int n);
void init_stack_a(t_stack_node **a, char **av);

t_stack_node *find_last_node(t_stack_node *stack);
void free_stack(t_stack_node **stack);
int stack_len(t_stack_node *stack);
int stack_sorted(t_stack_node *stack);
void	handle_push_to_b(t_stack_node **a, t_stack_node **b, int pivot,
	int chunk_size);
void	handle_rotation(t_stack_node **a, int *pushed, int *pivot,
		int chunk_size);

char	**ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_empty_substr(void);
size_t	ft_strlen(const char *s);
t_stack_node	*get_second_last_node(t_stack_node *stack);

void	sa(t_stack_node **a);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rotate_both(t_stack_node **a, t_stack_node **b);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	reverse_rotate_both(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	little_sort(t_stack_node **a);
int	stack_is_sorted(t_stack_node *stack);
void	index_stack(t_stack_node *stack);
void	sorter(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*get_last(t_stack_node *stack);
t_stack_node	*find_best_element_to_move(t_stack_node *a, t_stack_node *b);

int	calculate_move_cost(t_stack_node *a, t_stack_node *b, int value);
int	get_position(t_stack_node *stack, int value);
void	reintegrate_sorted(t_stack_node **a, t_stack_node **b);
void	parse_b(t_stack_node **a, t_stack_node **b, int size);
void	reverse_rotate(t_stack_node **stack, char stack_name);
int	find_best_insert_position(t_stack_node *a, int value);
void	rotate_until_bottom(t_stack_node **stack, int value, char stack_name);
void	rotate_until_top(t_stack_node **stack, int value, char stack_name);
void	rotate(t_stack_node **stack, char stack_name);
#endif