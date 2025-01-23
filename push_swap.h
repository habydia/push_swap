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

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
// # include "printf.h"

typedef struct s_stack_node
{
	int				data;
	int				index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}					t_stack_node;

//function check input
//function initialisation pile
//function initialisation node
//function utils
t_stack_node *find_last_node(t_stack_node *stack);
void free_stack(t_stack_node **stack);

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
#endif