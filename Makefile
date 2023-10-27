# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 09:30:42 by jule-mer          #+#    #+#              #
#    Updated: 2023/10/09 10:56:08 by ertupop          ###   ########.fr        #
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

SRCS	=	$(addprefix srcs/bultins/, \
			cd.c \
			echo.c \
			env.c \
			exit.c \
			export.c \
			export2.c\
			pwd.c \
			unset.c)

SRCS	+=	$(addprefix srcs/errors/, \
			errors.c)

SRCS	+= $(addprefix srcs/exec/SRC/, \
			exec_one.c \
			exec_one2.c \
			exec_pipe.c \
			exec_pipe2.c \
			exec0.c \
			exec.c \
			exec2.c \
			exec3.c \
			exec_ft_command.c \
			exev_pars.c)

SRCS	+=	$(addprefix srcs/garbage_collector/, \
			garbage_2.c \
			garbage.c)

SRCS	+=	$(addprefix srcs/parsing/, \
			bridge.c \
			check_env.c \
			check.c \
			expand_dell.c \
			expand.c \
			parsing_0.c \
			parsing.c \
			quote_gestion.c \
			spaces_gestion.c \
			tokkenisation.c \
			use_0.c \
			use_2.c \
			use_3.c \
			use.c)

SRCS	+=	$(addprefix srcs/utils/, \
			atol.c \
			env_utils.c \
			list_utils_2.c \
			list_utils.c \
			utils_bultins.c \
			utils.c)

SRCS	+=	$(addprefix srcs/, \
			heredoc.c \
			heredoc2.c \
			finish.c \
			main.c)
SRCS	+= $(addprefix srcs/Signaux/, \
			signal.c \
			signal2.c \
			ft_exit_sig.c)

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
	@make fclean -C libft
	@$(RM) $(NAME)
	@echo "\nALL IS DELETED\033[0m\n"

re:	fclean all

-include $(DEP)

.PHONY:	all clean fclean re
