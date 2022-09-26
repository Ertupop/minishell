# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 09:30:42 by jule-mer          #+#    #+#              #
#    Updated: 2022/09/26 15:20:52 by ertupop          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
LIBFT	=	libft/libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g -MMD

INC		=	-I./includes -I./libft -MMD

LIB		=	-L./libft -lft -lreadline

RM		=	rm -rf

DEP		=	$(SRCS:srcs/%.c=objects/%.d)
OBJS	=	$(SRCS:srcs/%.c=objects/%.o)

SRCS	=	$(addprefix srcs/, main.c)
SRCS	+=	$(addprefix srcs/errors/, errors.c)
SRCS	+=	$(addprefix srcs/garbage_collector/, garbage.c)
SRCS	+=	$(addprefix srcs/parsing/, \
			check_str.c \
			fill_args.c \
			init.c \
			parse_utils.c \
			parsing.c)
SRCS	+=	$(addprefix srcs/utils/, utils.c)
SRCS	+= $(addprefix srcs/bultins/, \
			cd.c \
			echo.c export.c \
			unset.c)
SRCS	+=	$(addprefix srcs/debug/, debug.c)

all:	$(NAME)

objects/%.o:	srcs/%.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME):	$(OBJS)
	@echo "\n"
	@make -C libft
	@echo "\033[0;32m\nCompilation of minishell"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)
	@echo "\nREADY !\033[0m\n"
	@$(RM) null.d

clean:
	@echo "\033[0;31mCleaning binaries..."
	@make clean -C libft
	@$(RM) $(OBJS) $(DEP) objects
	@echo "\nBINARIES ARE REMOVED\033[0m\n"

fclean:	clean
	@echo "\033[0;31m\nDeleting executable..."
	@$(RM) $(NAME)
	@echo "\nALL IS DELETED\033[0m\n"

re:	fclean all

-include $(DEP)

.PHONY:	all clean fclean re
