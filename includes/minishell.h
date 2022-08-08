/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:43:27 by jule-mer          #+#    #+#             */
/*   Updated: 2022/08/08 13:01:02 by jule-mer         ###   ########.fr       */
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

//check_str.c
int		ft_action(char *str, int *j);
int		ft_quote(char *str, int *j);
int		ft_check(char *str);

//main.c
int		ft_history(char *str);
void	ft_prompt(void);
int		main(int ac, char **av, char **envp);

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
//echo -n-n affiche -n-n
//echo "bon" "jour" == bon jour

#endif
