# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssaehoei <ssaehoei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 21:50:23 by ssaehoei          #+#    #+#              #
#    Updated: 2022/09/21 16:41:56 by ssaehoei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = pipex

SRCS = ft_split.c

SRC_DIR = ./source

INCLUDE_DIR = ./includes

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)


$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: $(SRC_DIR)/%.c
	gcc $(FLAGS)  -I $(INCLUDE_DIR) -c $< -o $@


clean:
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean re fcleans

