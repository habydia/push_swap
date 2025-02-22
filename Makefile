# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 20:44:38 by hadia             #+#    #+#              #
#    Updated: 2025/02/06 17:56:31 by hadia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = ft_init.c ft_init_utils.c ft_little_sort.c push_swap.c ft_sorter.c ft_sorter_utils.c ft_moves.c ft_rrotate.c
OBJ = $(SRC:.c=.o) 
NAME = push_swap

all: $(NAME)

LIBDIR = libft
LIBFT = $(LIBDIR)/libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) -lft -I$(LIBDIR) -o $(NAME)

$(LIBFT):
	make -C $(LIBDIR)
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

re: all clean fclean re