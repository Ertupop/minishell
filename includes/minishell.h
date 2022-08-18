/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:43:27 by jule-mer          #+#    #+#             */
/*   Updated: 2022/08/17 11:49:30 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

//DEBUG
# define ON 1
# define OFF 0
# define DEBUG ON

# define ENTRY 1
# define EXIT 2
# define DELIMATION 3
# define APPEND 4
# define PIPE 5
# define VAR_ENV 6

typedef struct s_arg
{
	int				is_command;
	int				is_action_tokken;
	int				is_argument;
	int				is_option;
	int				is_outfile;
	char			*str;
	char			*option;
	struct s_arg	*next;
}	t_arg;

typedef struct s_env
{
	char			*str;
	struct s_env	*next;
	int				ui;
}	t_env;


//check_str.c
int		ft_third(char *str, int i);
int		ft_return_str(int a, int b);
int		ft_quote(char *str, int i);
int		ft_check_str(char *str);

//main.c
void	ft_prompt(void);
int		main(int ac, char **av, char **envp);

//parsing.c
void	ft_mv_list(t_arg **args, t_list **collector);
void	ft_fill(t_arg **args, char *str, t_list **collector);
int		ft_create_parse(t_arg **args, char *str, t_list **collector);
int		ft_parse(t_arg **args, char *str, t_list **collector);

//parse_utils.c
void	ft_fill_arg(t_arg *arg, char *str, int *receive, t_list **collector);
void	ft_init_arg(t_arg **new);
t_arg	*gc_create_slot(t_list **collector);
int		ft_number_of_slot(char *str, int i, int res);

//parse_utils_2.c
int		ft_the_good_tokken(char c);
int		ft_is_sep(char c, char *sep);
t_arg	*ft_arg_last(t_arg *list);
void	ft_arg_add_back(t_arg **args, t_arg *new);
int		ft_strcmp(const char *s1, const char *s2);

//debug.c
void	ft_debug(t_arg **args);

void	ft_echo(t_arg *lst);
//si < en debut ou pipe <, un argument puis commande
//echo -n-n affiche -n-n
//echo "bon" "jour" == bon jour

//cd
char	*ft_find_env(t_env *env, char *find);

//utils
char	*gc_strdup(t_list **collector, const char *s1);
t_env	*gc_alloc_env(t_list **collector);
t_env	*ft_env(t_list **collector, char **envp);
void	ft_lstadd_back_env(t_env **alst, t_env *new);
t_env	*ft_lstlast_env(t_env *lst);
int	ft_pwd(t_env *env);

//export
int	ft_export(char **tab, t_env *env, t_list *garbage);
int	ft_size_tab(char **tab);
int	ft_print_export(t_env	*env);
#endif
