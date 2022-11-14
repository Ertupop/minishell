/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:43:27 by jule-mer          #+#    #+#             */
/*   Updated: 2022/11/09 13:04:20 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

//DEBUG
# define ON 1
# define OFF 0
# define DETAILS 2
# define DEBUG DETAILS

/*----------------------------------------------------------------------------*/
/*                                 STRUCTURES                                 */
/*----------------------------------------------------------------------------*/
//
typedef enum s_tokken
{
	COMMAND,
	PIPE,
	OUTFILE,
	APPEND,
	INFILE,
	LIMITER
}	t_tokken;

typedef struct s_use
{
	enum s_tokken		tokken;
	char				**tab;
	char				*action;
	int					fd;
	struct s_use		*next;
}	t_use;

typedef struct s_arg
{
	int				is_str;
	int				is_command;
	int				is_action_tokken;
	int				is_argument;
	int				is_file;
	int				use;
	char			*str;
	struct s_arg	*next;
}	t_arg;

typedef struct s_env
{
	char			*str;
	struct s_env	*next;
	int				ui;
}	t_env;

typedef struct s_parse
{
	int		i;
	int		j;
	int		quote;
	char	c;
}	t_parse;

/*----------------------------------------------------------------------------*/
/*                                    MAIN                                    */
/*----------------------------------------------------------------------------*/
//
//main.c 3/5
int		ft_history(char *str);
void	ft_prompt(void);
//int		main(int ac, char **av, char **envp);

/*----------------------------------------------------------------------------*/
/*                                   ERRORS                                   */
/*----------------------------------------------------------------------------*/
//
//errros.c 1/5
int		ft_error(int i, char c);

/*----------------------------------------------------------------------------*/
/*                                   GARBAGE                                  */
/*----------------------------------------------------------------------------*/
//
//garbage.c 1/5
t_use	*gc_create_use(t_list **collector);
t_arg	*gc_create_slot(t_list **collector);

/*----------------------------------------------------------------------------*/
/*                                   PARSING                                  */
/*----------------------------------------------------------------------------*/
//
//check_str.c 4/5
int		ft_action_2(char *str, int *j);
int		ft_action(char *str, int *j);
int		ft_quote(char *str, int *j);
int		ft_check(char *str);

//fill_args.c 3/5
void	ft_use(t_use **use, t_arg **args, t_list **collector);
void	ft_args_type(t_arg **args);
void	ft_fill_args(t_use **use, t_arg **args, t_list **collector);

//init.c 4/5
void	ft_end_init(t_arg **new);
int		ft_init_quote_2(int i, char *str);
void	ft_init_quote(t_list **collector, t_arg **new, char *str, int i);
void	ft_init_sep(t_list **collector, t_arg **new, char *str, int i);

//parse_utils.c OVER
char	**gc_alloc_char_r(t_list **collector, int size);
int		ft_is_sep(char c, char *sep);
t_use	*ft_use_last(t_use *list);
void	ft_use_add_back(t_use **use, t_use *new);
t_arg	*ft_arg_last(t_arg *list);
void	ft_arg_add_back(t_arg **args, t_arg *new);

//parsing.c FULL
void	ft_parse_str(t_list **collector, t_arg **new, char *str,
			t_parse *parse);
void	ft_skip_char(char *str, t_parse *parse);
void	ft_parse_sep(t_list **collector, t_arg **new, char *str,
			t_parse *parse);
int		ft_parse_2(char *str, t_parse *parse);
int		ft_parse(t_arg **args, char *str, t_list **collector, t_parse parse);

/*----------------------------------------------------------------------------*/
/*                                    UTILS                                   */
/*----------------------------------------------------------------------------*/
//
//utils.c 1/5

char	*ft_strstr(char	*str, char	*to_find);
//utils_bultins
char	*ft_find_env(t_env *env, char *find);
int	ft_strcmp(const char *s1, const char *s2);
//utils
char	*gc_strdup(t_list **collector, const char *s1);
t_env	*gc_alloc_env(t_list **collector);
t_env	*ft_env(t_list **collector, char **envp);
void	ft_lstadd_back_env(t_env **alst, t_env *new);
t_env	*ft_lstlast_env(t_env *lst);
int		ft_env_size(t_env *env);
t_env	*ft_get_env_pos(t_env *env, char *find);

/*----------------------------------------------------------------------------*/
/*                                   BULTINS                                  */
/*----------------------------------------------------------------------------*/

//pwd
int		ft_pwd(void);
//echo
void	ft_echo(char **tab);
void	ft_echo2(char **tab, int i, int n);

//export
int		ft_export(char **tab, t_env *env, t_list *garbage);
int		ft_size_tab(char **tab);
int		ft_print_export(t_env	*env);
char	**ft_make_tab(t_env *env);
void	ft_free_make_tab(char **tab);
void	ft_sort_env(char **envi);
int		ft_check_export(char *str);
//env
void	ft_print_env(t_env *env);
//unset
void	ft_unset_remove(t_env	*tmp, t_env *env);
int		ft_unset(t_env *env, char **tab);

/*----------------------------------------------------------------------------*/
/*                                    DEBUG                                   */
/*----------------------------------------------------------------------------*/
//
//debug.c
void	ft_debug(t_arg **args);

#endif


//echo -n-n affiche -n-n
//echo "bon" "jour" == bon jour
