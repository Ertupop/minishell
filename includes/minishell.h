/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:43:27 by jule-mer          #+#    #+#             */
/*   Updated: 2023/06/17 17:17:34 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/wait.h>
# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

/*----------------------------------------------------------------------------*/
/*                                 STRUCTURES                                 */
/*----------------------------------------------------------------------------*/

typedef enum s_tokken
{
	COMMAND,
	PIPE,
	OUTFILE,
	APPEND,
	INFILE,
	LIMITER
}	t_tokken;

typedef enum s_bultins
{
	CD,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
	NO,
}	t_bultins;

typedef struct s_easy
{
	int				space;
	int				d_quote;
	int				s_quote;
	int				dell;
	char			c;
	struct s_easy	*next;
}	t_easy;

typedef struct s_bridge
{
	char			*str;
	enum s_tokken	tokken;
	struct s_bridge	*next;
}	t_bridge;

typedef struct s_use
{
	enum s_tokken	tokken;
	char			**tab;
	int				fd;
	char			*eof;
	char			*file_name;
	struct s_use	*next;
}	t_use;

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
	char	*str;
}	t_parse;

typedef struct s_pipex
{
	char	**path;
	char	*command;
	int		nbr_command;
	int		count_command;
	char	**env;
	pid_t	childs;
	int		prev_pipes;
	int		infile;
	int		outfile;
	int		pipe[2];
	int		exit;
}	t_pipex;

typedef struct sigaction	t_sig;

extern int					g_exit;

/*----------------------------------------------------------------------------*/
/*                                    Main                                    */
/*----------------------------------------------------------------------------*/

//main.c
int			ft_history(char *str);
void		ft_init_parse(t_parse *parse);
void		ft_prompt(t_list **collector, t_env **env);
int			main(int ac, char **av, char **envp);

/*----------------------------------------------------------------------------*/
/*                                   Signaux                                  */
/*----------------------------------------------------------------------------*/

void		ft_sig_handler(int signum);
void		ft_set_sa(t_sig *signal, void (*f)(int));
void		ft_sig_handler_heredoc(int signum);
void		ft_set_sa_heredoc(t_sig *signale, void (*f)(int), void *end);

/*----------------------------------------------------------------------------*/
/*                                   BULTINS                                  */
/*----------------------------------------------------------------------------*/

//cd
int			ft_cd(char **tab, t_env *env, t_list *gc);
int			ft_home(t_env *env, t_list *gc);
int			ft_home2(char *old, t_env *env, t_list *gc, char *tmpo);
int			ft_cd_2(char *path, t_env *env, t_list *gc);
void		ft_cd3(char *old, t_env *env, t_list *gc);

//echo
int			ft_echo(char **tab);
void		ft_echo2(char **tab, int i, int n);

//env
int			ft_print_env(t_env *env);

//exit
void		ft_exit(char **tab, t_list *gc);
long long	ft_exit3(char **tab);
void		ft_exit2(char **tab, t_list *gc);
int			ft_check_number(char *number, t_list *gc);

//export
int			ft_export(char **tab, t_env *env, t_list *garbage);
void		ft_export2(char *tab, t_env *tmp, t_list *garbage, t_env *env);
int			ft_find_plus(char *str);
int			ft_find_equal(char *str);
t_env		*ft_add_export(char *str, t_env *env, t_list *garbage);

//export2
int			ft_size_tab(char **tab);
int			ft_check_export(char *str);
void		ft_join_export(char *str, t_env *tmp, t_list *garbage);

//pwd
int			ft_pwd(void);

//unset
int			ft_unset(t_list *collect, t_env *env, char **tab);
int			ft_unset_cmp(char *s1, char *s2);
void		ft_unset_remove(t_list *collect, t_env	*tmp, t_env *env);

/*----------------------------------------------------------------------------*/
/*                                   ERRORS                                   */
/*----------------------------------------------------------------------------*/

//errros.c
int			ft_error_2(char *str);
int			ft_error(int i, char c);

/*----------------------------------------------------------------------------*/
/*                                    EXEC                                    */
/*----------------------------------------------------------------------------*/

//exec_one.c
int			ft_exec_one(t_use *use, t_env *env, t_list *gc, t_pipex *pip);
int			ft_exec_one2(t_use **use, t_use **tmp, t_pipex **pip);
int			ft_exec_bultins(t_use *use, t_env *env, t_list *gc, int tokken);
int			ft_execve_one(t_env *env, t_pipex *pip, t_use *tmp, t_list *gc);
void		ft_free_pip(t_pipex *pip);
//exec_one2.c
void		ft_execve_one2(t_pipex *pip, t_use *tmp, t_list *gc);
//exec_pipe.c
int			ft_exec_pipe(t_use *tmp, t_env *env, t_list *gc, t_pipex *pip);
void		ft_exec_pipe2(t_pipex *pip);
void		ft_exec_pipe4(t_pipex *pip);
void		ft_exec_pipe4bis(t_pipex *pip);
void		ft_exec_pipe3(t_pipex *pip);

//exec_pipe2.c
void		ft_exec_pipe5(t_pipex *pip, t_env *env, t_use *tmp, t_list *gc);
int			ft_exec_pipe6(t_use *tmp, t_env *env, t_list *gc, int tokken);
void		ft_close_one(int s, int i);

//exec0.c
int			ft_exec_all(t_use *use, t_env *env, t_list *gc, t_pipex *pip);
void		ft_exec_all0(t_use **outfile, t_pipex **pip);

//exec.c
void		ft_exec(t_use **use, t_env *env, t_list *gc);
void		ft_exec_all2(t_pipex *pip, t_use **outfile);
int			ft_wait_lstchild(t_pipex *pip);
int			ft_close_pipe(int count, int *pipe, int nbr_command, t_pipex *pip);

//exec2.c
int			ft_create_pipe(int count, int *pipes);
int			ft_init_fd(t_pipex *pip, t_use *use);
void		ft_close_fd(int in, int out);
int			ft_check2(char *s);
void		ft_lunch_heredoc(t_use *here, t_env *env);

//exec_pars.c
void		ft_path(t_env *env, t_pipex *pip);
char		*ft_command(t_pipex *pip, char *command);
int			ft_is_a_slash(char	*command);
void		ft_path2(t_pipex *pip);
char		*ft_join(char *first, char *second);

/*----------------------------------------------------------------------------*/
/*                                   GARBAGE                                  */
/*----------------------------------------------------------------------------*/

//garbage_2.c
char		*gc_strdup(t_list **collector, const char *s1);
t_use		*gc_alloc_use(t_list **collector);
t_env		*gc_alloc_env(t_list **collector);

//garbage.c
t_bridge	*gc_create_bridge(t_list **collector);
t_easy		*gc_create_easy(t_list **collector);
t_use		*gc_create_use(t_list **collector);
char		**gc_alloc_char_r(t_list **collector, int size);
char		*gc_join_str(t_list **coll, const char *s1, const char *s2);

/*----------------------------------------------------------------------------*/
/*                                   PARSING                                  */
/*----------------------------------------------------------------------------*/

//bridge.c
void		ft_help_line(int *i, char *c, char d, int ca);
int			ft_size_of_str(t_easy **easy, int i, int len);
char		*ft_the_str(t_easy **easy, t_list **collector, int i, int j);
int			ft_number_space(t_easy *easy);
void		ft_create_bridge(t_easy *easy, t_use **use, t_list **collector);

//check_env.c
char		*ft_split_env(char *str);

//check.c
int			ft_is_in(char c, char *in);
int			ft_action_2(char *str, int *j);
int			ft_action(char *str, int *j);
int			ft_checking_quote(char *str, int *j);
int			ft_check_parse(char *str);
int			ft_check_parse(char *str);

//expand_dell.c
int			ft_quote(int i, int j);
void		ft_dell_dollar_2(t_easy **tmp, t_easy **tmp_2, t_list **col, int i);
void		ft_dell_dollar(t_easy **easy, t_list **collector);

//expand.c
t_easy		*ft_create_expand(char *str, t_list **collector);
void		ft_expand_exit(t_easy **easy, t_list **collector);
void		ft_apply_expand(char *str, t_easy **easy, t_list **collector);
void		ft_check_expand(t_easy **easy, t_list **collector, t_env **env);
void		ft_expand(t_easy **easy, t_list **collector, t_env **env);

//parsing.c
void		ft_init_easy(t_easy *easy);
void		ft_start_easy(t_easy **easy, t_list **collector, t_parse *parse);
int			ft_parse(t_use **use, t_parse *parse, t_list **collector,
				t_env **env);
void		ft_good_place(t_easy **first, t_list **collector);
void		ft_good_help(t_easy *easy, int *s, int *d);
void		ft_good_help_2(t_easy **new, t_easy **easy, t_list **collector);
void		ft_good_help_3(t_easy **new, t_easy **easy, t_list **collector);

//quote_gestion.c
void		ft_good_double(t_easy **tmp, int *i);
void		ft_good_simple(t_easy **tmp, int *i);
void		ft_good_quote(t_easy **easy);
void		ft_check_quote(t_easy **easy);

//spaces_gestion.c
void		ft_skip_middle(t_easy **tmp, t_list **collector, int *i);
void		ft_skip_start(t_easy **easy, t_easy **tmp, t_list **collector);
void		ft_skip_space(t_easy **easy, t_list **collector);

//tokkenisation.c
void		ft_is_action(t_bridge **bridge);
void		ft_tokkenisation(t_bridge **bridge);

//use.c
void		ft_add_heredoc(t_use **use, t_list **collector, int limiter,
				t_bridge *bridge);
void		ft_add_infile(t_use **use, t_list **collector, int infile);
void		ft_add_outfile(t_use **use, t_list **collector, int outfile,
				int append);
char		**ft_use_tab(t_bridge *bridge, t_list **collector, int len);
int			ft_tab_size(t_bridge *bridge);
int			ft_nbr_file(t_bridge *bridge, int *infile, int *outfile);
int			ft_nbr_slots(t_bridge *bridge);
void		ft_good_infile(t_bridge *bridge, int *infile, int *limiter);
void		ft_good_outfile(t_bridge *bridge, int *outfile, int *append);;
void		ft_fill_use(t_list **collector, t_use **use,
				t_bridge **bridge, int len);
void		ft_use(t_use **use, t_bridge *bridge, t_list **collector);
void		ft_init_for_use(int *i, int *o, int *a, int *l);
void		ft_fill_use_2(t_bridge **bridge, t_use **new);

/*----------------------------------------------------------------------------*/
/*                                    UTILS                                   */
/*----------------------------------------------------------------------------*/

//atol.c
long long	ft_atol(const char *str);

//env_utils.c
int			ft_env_size(t_env *env);
t_env		*ft_get_env_pos(t_env *env, char *find);
t_env		*ft_get_env_pos_export(t_env *env, char *find);
t_env		*ft_env(t_list **collector, char **envp);
char		**ft_make_env_tab(t_env *env);

//list_utils_2.c
t_env		*ft_lstlast_env(t_env *lst);
void		ft_lstadd_back_env(t_env **alst, t_env *new);
t_use		*ft_lstlast_use(t_use *lst);

//list_utils.c
void		ft_lstadd_back_use(t_use **alst, t_use *new);
t_bridge	*ft_lstlast_bridge(t_bridge *lst);
void		ft_lstadd_back_bridge(t_bridge **alst, t_bridge *new);
t_easy		*ft_lstlast_easy(t_easy *lst);
void		ft_lstadd_back_easy(t_easy **alst, t_easy *new);

//utils_bultins.c
char		*ft_find_env(t_env *env, char *find);

//utils.c
char		*ft_gc_strdup(const char *s1, t_list **collector);
void		ft_free_envp(char **envp);
char		*ft_strcat(char *s1, char *s2, t_list **collector);
int			ft_strcmp(char *s1, char *s2);

/*----------------------------------------------------------------------------*/
/*                                   heredoc                                  */
/*----------------------------------------------------------------------------*/
//heredoc.c
int			ft_acces_heredoc(t_use *use);
int			ft_heredoc_while(int i, char *str, char *number, char *heredoc);
void		ft_acces_free(char *str, char *number, char *heredoc);
void		ft_heredoc(int fd, const char *end, t_env *env);
void		ft_heredoc2(const char *end, char *str, t_list *gc);
void		ft_heredoc3(t_easy *work, t_list *gc, int fd);
void		ft_start_easy_here(t_easy **easy, t_list **collector,
				int *i, char *str);
void		ft_make_string_easy(t_easy *work, t_list **gc, int fd);
#endif
