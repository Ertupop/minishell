/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:00:09 by ertupop           #+#    #+#             */
/*   Updated: 2023/01/17 09:57:15 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exec_pipe5(t_pipex *pip, t_env *env, t_use *tmp, t_list *gc)
{
	ft_path(env, pip);
	pip->env = ft_make_env_tab(env);
	pip->command = ft_command(pip, tmp->tab[0]);
	if (pip->command == NULL)
	{
		printf("\033[0;36mminishell \033[0;31m: \033[0m %s: command not found\n", tmp->tab[0]);
		ft_free_envp(pip->env);
		ft_free_pip(pip);
		g_exit = 127;
		gc_dell(gc);
		exit(127);
	}
	ft_close_fd(pip->infile, pip->outfile);
	if (execve(pip->command, tmp->tab, pip->env) == -1)
	{
		ft_free_envp(pip->env);
		exit(1);
	}
}

int	ft_exec_pipe6(t_use *tmp, t_env *env, t_list *gc, int tokken)
{
	int	result;

	result = 0;
	if (tokken == CD)
		result = ft_cd(tmp->tab, env, gc);
	else if (tokken == ECHO)
		result = ft_echo(tmp->tab);
	else if (tokken == ENV)
		result = ft_print_env(env);
	else if (tokken == EXIT)
		ft_exit(tmp->tab, gc);
	else if (tokken == EXPORT)
		result = ft_export(tmp->tab, env, gc);
	else if (tokken == PWD)
		result = ft_pwd();
	else if (tokken == UNSET)
		result = ft_unset(gc, env, tmp->tab);
	return (result);
}

void	ft_close_one(int s, int i)
{
	close(s);
	close(i);
}