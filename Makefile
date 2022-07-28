# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: firawar <firawar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 09:30:42 by jule-mer          #+#    #+#              #
#    Updated: 2022/07/28 13:24:57 by firawar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g -MMD

RM		=	rm -rf

DEP		=	$(SRCS:srcs/%.c=objects/%.d)
OBJS	=	$(SRCS:srcs/%.c=objects/%.o)
SRCS	=	$(addprefix srcs/, $(SRC))
SRC		=	main.c \
			parsing.c \
			utils.c \
			debug.c

all:	$(NAME)

objects/%.o:	srcs/%.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@mkdir -p objects
	@$(CC) $(CFLAGS) -I includes -I libft -c $< -o $@

$(NAME):	$(OBJS)
	@echo "\n"
	@make -C libft
	@echo "\033[0;32m\nCompilation of minishell"
	@$(CC) $(OBJS) -g -o $(NAME) -Llibft -lft -lreadline
	@echo "\nREADY !\033[0m\n"

clean:
	@echo "\033[0;31mCleaning binaries..."
	@make clean -C libft
	@$(RM) $(OBJS) $(DEP) objects
	@echo "\nBINARIES ARE REMOVED\033[0m\n"

fclean:
	@echo "\033[0;31mCleaning binaries..."
	@make fclean -C libft
	@$(RM) $(OBJS) $(DEP) objects
	@echo "\nDeleting executable..."
	@rm $(NAME)
	@echo "\nALL IS DELETED\033[0m\n"

re:	fclean all

-include $(DEP)

.PHONY:	all clean fclean re
