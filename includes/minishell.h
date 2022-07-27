/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:43:27 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/27 12:01:49 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_arg
{
	char			*str;
	int				is_action_tokken;
	int				is_outfile;
	struct s_arg	*next;
}	t_arg;

//check.c

//main.c
int		ft_double_pipe(char *str);
void	ft_prompt(t_list **collector);
void	ft_prompt(t_list **collector);
int		main(int ac, char **av, char **envp);

//parsing.c
int		ft_number_of_slot(char *str);
t_arg	*ft_parse(t_list **collector, t_arg **args, char *str);

//utils.c
int		ft_strcmp(const char *s1, const char *s2);

#endif
