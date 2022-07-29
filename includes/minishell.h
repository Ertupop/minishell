/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:43:27 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/29 07:17:26 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ENTRY 1
# define EXIT 2
# define DELIMATION 3
# define APPEND 4
# define PIPE 5
# define VAR_ENV 6

# define S_PIPE 1
# define D_PIPE 2

typedef struct s_arg
{
	int				is_action_tokken;
	int				is_pipe;
	int				is_outfile;
	char			*str;
	struct s_arg	*next;
}	t_arg;

//main.c
void	ft_prompt(void);
int		main(int ac, char **av, char **envp);

//parsing.c
void	ft_fill_arg(t_arg *arg, char *str, int *receive, t_list **collector);
t_arg	*gc_create_slot(t_list **collector);
void	ft_init_arg(t_arg **new);
int		ft_number_of_slot(char *str);
t_arg	*ft_parse(t_arg **args, char *str, t_list **collector);

//utils.c
char	*ft_the_god_sep(char c);
int		ft_is_sep(char c, char *sep);
t_arg	*ft_arg_last(t_arg *list);
void	ft_arg_add_back(t_arg **args, t_arg *new);
int		ft_strcmp(const char *s1, const char *s2);

//builtins

#endif
