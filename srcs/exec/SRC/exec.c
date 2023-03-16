/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:11:43 by ertupop           #+#    #+#             */
/*   Updated: 2023/03/16 09:19:13 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exec(t_use **use, t_env *env, t_list *gc)
{
	t_pipex	pipex;
	int		result;

	pipex.outfile = 1;
	pipex.nbr_command = ft_init_fd(&pipex, *use);
	if (pipex.nbr_command == 0)
		return ;
	if (pipex.nbr_command == 1)
		result = ft_exec_one(*use, env, gc, &pipex);
	else
		result = ft_exec_all(*use, env, gc, &pipex);
	ft_close_fd(pipex.infile, pipex.outfile);
	g_exit = result;
}

int	ft_exec_all(t_use *use, t_env *env, t_list *gc, t_pipex *pip)
{
	t_use	*tmp;
	t_use	*outfile;

	tmp = use;
	outfile = use;
	pip->pipe = malloc(sizeof(int) * 4);
	if (pip->pipe == NULL)
		return (-1);
	pip->count_command = 0;
	while (pip->count_command < pip->nbr_command)
	{
		ft_exec_all2(pip, &outfile);
		while (tmp && tmp->tokken != COMMAND)
			tmp = tmp->next;
		pip->childs = fork();
		if (pip->childs == 0)
			ft_exec_pipe(tmp, env, gc, pip);
		tmp = tmp->next;
		ft_close_pipe(pip->count_command, pip->pipe, pip->nbr_command);
		pip->count_command ++;
		if (outfile != NULL)
			outfile = outfile->next;
	}
	return (ft_wait_lstchild(pip));
}

void	ft_exec_all2(t_pipex *pip, t_use **outfile)
{
	if (pip->count_command < pip->nbr_command - 1)
		ft_create_pipe(pip->count_command, pip->pipe);
	pip->outfile = 1;
	pip->infile = 0;
	while (*outfile && (*outfile)->tokken != PIPE)
	{
		if ((*outfile)->tokken == OUTFILE || (*outfile)->tokken == APPEND)
			pip->outfile = (*outfile)->fd;
		if ((*outfile)->tokken == INFILE)
		{
			pip->infile = (*outfile)->fd;
		}
		*outfile = (*outfile)->next;
	}
}

int	ft_wait_lstchild(t_pipex *pip)
{
	int		lastchilds;
	int		tmprtr;
	int		pidw;

	free(pip->pipe);
	pidw = waitpid(-1, &tmprtr, 0);
	while (pip->count_command != 0)
	{
		if (pidw == pip->childs)
			lastchilds = tmprtr;
		pidw = waitpid(-1, &tmprtr, 0);
		pip->count_command --;
	}
	if (WIFSIGNALED(lastchilds))
	{
		lastchilds = WTERMSIG(lastchilds) + 128;
		if (WTERMSIG(lastchilds) == SIGQUIT)
			write(STDERR_FILENO, "Quit (core dumped)\n", 19);
		else if (WTERMSIG(lastchilds) == SIGSEGV)
			write(STDERR_FILENO, "Segmentation fault (core dumped)\n", 33);
	}
	return (lastchilds);
}

int	ft_close_pipe(int count, int *pipe, int nbr_command)
{
	if (count == 0)
	{
		close(pipe[1]);
	}
	else if (count == nbr_command -1)
	{
		if (count % 2 == 0)
			close(pipe[2]);
		else
			close(pipe[0]);
	}
	else if (count % 2 == 0)
	{
		close(pipe[1]);
		close(pipe[2]);
	}
	else
	{
		close(pipe[0]);
		close(pipe[3]);
	}
	return (0);
}
