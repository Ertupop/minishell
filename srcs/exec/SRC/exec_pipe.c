/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:37 by ertupop           #+#    #+#             */
/*   Updated: 2023/02/20 17:51:48 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_exec_pipe(t_use *tmp, t_env *env, t_list *gc, t_pipex *pip)
{
	int		tokken;
	int		result;
	t_sig	signal;

	ft_set_sa(&signal, SIG_DFL);
	tokken = ft_check2(tmp->tab[0]);
	if (pip->count_command == 0)
		ft_exec_pipe2(pip);
	else if (pip->count_command == pip->nbr_command - 1)
		ft_exec_pipe3(pip);
	else
		ft_exec_pipe4(pip);
	if (tokken == NO)
		ft_exec_pipe5(pip, env, tmp, gc);
	else
		result = ft_exec_pipe6(tmp, env, gc, tokken);
	exit (result);
}

void	ft_exec_pipe2(t_pipex *pip)
{
	dup2(pip->infile, 0);
	close(pip->infile);
	if (pip->outfile != 1)
	{
		dup2(pip->outfile, 1);
		close(pip->outfile);
	}
	else
	{
		dup2 (pip->pipe[1], 1);
		close(pip->pipe[1]);
	}
}

void	ft_exec_pipe3(t_pipex *pip)
{
	dup2(pip->outfile, 1);
	if (pip->outfile != 1)
		close(pip->outfile);
	if (pip->count_command % 2 == 0)
	{
		dup2(pip->pipe[2], 0);
		close(pip->pipe[2]);
	}
	else
	{
		dup2(pip->pipe[0], 0);
		close(pip->pipe[0]);
	}
}

void	ft_exec_pipe4(t_pipex *pip)
{
	if ((pip->count_command) % 2 == 0)
	{
		dup2(pip->pipe[2], 0);
		close(pip->pipe[2]);
		if (pip->outfile != 1)
		{
			dup2(pip->outfile, 1);
			close(pip->outfile);
		}
		else
		{
			dup2(pip->pipe[1], 1);
			close(pip->pipe[1]);
		}
	}
	else
	{
		ft_exec_pipe4bis(pip);
	}
}

void	ft_exec_pipe4bis(t_pipex *pip)
{
	dup2(pip->pipe[0], 0);
	close(pip->pipe[0]);
	if (pip->outfile != 1)
	{
		dup2(pip->outfile, 1);
		close(pip->outfile);
	}
	else
	{
		dup2(pip->pipe[3], 1);
		close(pip->pipe[3]);
	}
}
