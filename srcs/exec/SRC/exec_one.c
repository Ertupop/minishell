/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 07:37:59 by ertupop           #+#    #+#             */
/*   Updated: 2023/02/09 09:13:11 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_exec_one(t_use *use, t_env *env, t_list *gc, t_pipex *pip)
{
	t_use	*tmp;
	int		tokken;
	int		s;
	int		i;
	int		result;

	tmp = NULL;
	tokken = ft_exec_one2(&use, &tmp, &pip);
	s = dup(1);
	i = dup(0);
	dup2(pip->infile, 0);
	dup2(pip->outfile, 1);
	if (tokken == NO)
		result = ft_execve_one(env, pip, tmp, gc);
	if (ft_check2(use->tab[0]) == EXIT)
		ft_close_one(s, i);
	if (tokken != NO)
		result = ft_exec_bultins(tmp, env, gc, tokken);
	dup2(s, 1);
	dup2(i, 0);
	close(s);
	close(i);
	(void) gc;
	return (result);
}

int	ft_exec_one2(t_use **use, t_use **tmp, t_pipex **pip)
{
	int		tokken;

	(*tmp) = (*use);
	(*pip)->outfile = 1;
	(*pip)->infile = 0;
	while ((*tmp))
	{
		if ((*tmp)->tokken == OUTFILE)
			(*pip)->outfile = (*tmp)->fd;
		if ((*tmp)->tokken == INFILE)
			(*pip)->infile = (*tmp)->fd;
		(*tmp) = (*tmp)->next;
	}
	*tmp = *use;
	tokken = ft_check2((*tmp)->tab[0]);
	while (*tmp && (*tmp)->tokken != COMMAND)
		*tmp = (*tmp)->next;
	return (tokken);
}

int	ft_exec_bultins(t_use *use, t_env *env, t_list *gc, int tokken)
{
	if (tokken == CD)
		return (ft_cd(use->tab, env, gc));
	else if (tokken == ECHO)
		return (ft_echo(use->tab));
	else if (tokken == ENV)
		return (ft_print_env(env));
	else if (tokken == EXIT)
		ft_exit(use->tab, gc);
	else if (tokken == EXPORT)
		return (ft_export(use->tab, env, gc));
	else if (tokken == PWD)
		return (ft_pwd());
	else if (tokken == UNSET)
		return (ft_unset(gc, env, use->tab));
	return (NO);
}

int	ft_execve_one(t_env *env, t_pipex *pip, t_use *tmp, t_list *gc)
{
	int		result;
	t_sig	signal;

	pip->childs = fork();
	if (pip->childs == 0)
	{
		ft_set_sa(&signal, SIG_DFL);
		ft_path(env, pip);
		pip->env = ft_make_env_tab(env);
		pip->command = ft_command(pip, tmp->tab[0]);
		ft_close_fd(pip->infile, pip->outfile);
		if (pip->command == NULL)
		{
			printf("\033[0;36mminishell \033[0;31m: \033[0m %s: command not found\n", tmp->tab[0]);
			ft_free_envp(pip->env);
			ft_free_pip(pip);
			g_exit = 127;
			gc_dell(gc);
			exit(127);
		}
		else if (execve(pip->command, tmp->tab, pip->env) == -1)
		{
			ft_free_envp(pip->env);
			ft_free_pip(pip);
			ft_exit(NULL, gc);
		}
	}
	waitpid(pip->childs, &result, 0);
	WIFEXITED(result);
	WEXITSTATUS(result);
	return (result);
}

void	ft_free_pip(t_pipex *pip)
{
	int	i;

	i = 0;
	free(pip->command);
	if (pip->path != NULL)
	{
		while (pip->path[i])
		{
			free(pip->path[i]);
			i++;
		}
		free(pip->path);
	}
}
