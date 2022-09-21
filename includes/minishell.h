/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:43:27 by jule-mer          #+#    #+#             */
/*   Updated: 2022/09/21 13:58:28 by ertupop          ###   ########.fr       */
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
# define DEBUG OFF

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
	int				is_file;
	char			*str;
	struct s_arg	*next;
}	t_arg;

typedef struct s_env
{
	char			*str;
	struct s_env	*next;
	int				ui;
}	t_env;


//check_str.c
int		ft_action(char *str, int *j);
int		ft_quote(char *str, int *j);
int		ft_check(char *str);

//main.c
int		ft_history(char *str);
void	ft_prompt(void);
//int		main(int ac, char **av, char **envp);

//errros.c
int		ft_error(int i, char c);

//garbage.c
t_arg	*gc_create_slot(t_list **collector);

//init.c
void	ft_end_init(t_arg **new);
void	ft_init_quote(t_list **collector, t_arg **new, char *str, int i);
void	ft_init_sep(t_list **collector, t_arg **new, char *str, int i);
void	ft_init_str(t_list **collector, t_arg **new, char *str, int i);

//parse_utils.c
int		ft_is_sep(char c, char *sep);
t_arg	*ft_arg_last(t_arg *list);
void	ft_arg_add_back(t_arg **args, t_arg *new);

//parsing.c
int		ft_parse(t_arg **args, char *str, t_list **collector);

//utils.c
int		ft_strcmp(char *s1, char *s2);

//debug.c
void	ft_debug(t_arg **args);

//si < en debut ou pipe <, un argument puis commande


///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///                                                                         ///
///                                 Bultins                                 ///
///                                                                         ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

//cd
char	*ft_find_env(t_env *env, char *find);
int		ft_pwd(t_env *env);
void	ft_echo(t_arg *lst);
//utils
char	*gc_strdup(t_list **collector, const char *s1);
t_env	*gc_alloc_env(t_list **collector);
t_env	*ft_env(t_list **collector, char **envp);
void	ft_lstadd_back_env(t_env **alst, t_env *new);
t_env	*ft_lstlast_env(t_env *lst);
int		ft_env_size(t_env *env);
t_env	*ft_get_env_pos(t_env env, char *find);

//export
int		ft_export(char **tab, t_env *env, t_list *garbage);
int		ft_size_tab(char **tab);
int		ft_print_export(t_env	*env);
char	**ft_make_tab(t_env *env);
void	ft_free_make_tab(char **tab);
void	ft_sort_env(char **envi);
int		ft_check_export(char *str);

//utils2
//int	ft_strcmp(const char *s1, const char *s2);
#endif


//echo -n-n affiche -n-n
//echo "bon" "jour" == bon jour
