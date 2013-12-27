# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrault <abrault@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 12:54:18 by abrault           #+#    #+#              #
#    Updated: 2013/12/23 16:11:49 by abrault          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell

FLAG = -Wall -Wextra -Werror

SRC = main.c \
      ft_list.c

OBJ = main.o \
      ft_list.o

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L./libft/ -lft

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: clean fclean all

