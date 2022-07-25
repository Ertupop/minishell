# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 09:30:42 by jule-mer          #+#    #+#              #
#    Updated: 2022/07/25 03:29:15 by jule-mer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g -MMD

RM		=	rm -rf

LIBFT	=	libft/libft.a

DEP		=	$(SRCS:srcs/%.c=objects/%.d)
OBJS	=	$(SRCS:srcs/%.c=objects/%.o)
SRCS	=	$(addprefix srcs/, $(SRC))
SRC		=	main.c

all:	$(NAME)

objects/%.o:	srcs/%.c
	mkdir -p objects
	$(CC) $(CFLAGS) -I includes -I libft -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) -g -o $(NAME) -Llibft -lft -lreadline

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	$(RM) $(OBJS) $(DEP) objects

fclean:	clean
	make fclean -C libft
	rm $(NAME)

re:	fclean all

-include $(DEP)

.PHONY:	all clean fclean re

