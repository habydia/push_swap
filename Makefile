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
CFLAGS = -Wall -Wextra -Werror
SRC = *.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

LIBDIR = libft
LIBFT = $(LIBDIR)/libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) -l$(LIBDIR) -I$(LIBDIR) -o $(NAME)

$(LIBFT):
	make -C $(LIBDIR)
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(make) -C $(LIBDIR) clean
fclean: clean
	rm -f $(NAME)

re: all clean fclean re