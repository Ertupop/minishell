/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:14:40 by ertupop           #+#    #+#             */
/*   Updated: 2023/06/17 17:17:45 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_create_pipe(int count, int *pipes)
{
	if (count % 2 == 0)
	{
		pipe(pipes);
	}
	else
	{
		pipe(pipes + 2);
	}
	return (0);
}

int	ft_init_fd(t_pipex *pip, t_use *use)
{
	t_use	*tmp;
	int		command;

	command = 0;
	tmp = use;
	(void) pip;
	while (tmp)
	{
		if (tmp->tokken == COMMAND && tmp->tab != NULL)
			command++;
		tmp = tmp->next;
	}
	return (command);
}

void	ft_close_fd(int in, int out)
{
	if (in != 0)
		close (in);
	if (out != 1)
		close (out);
}

int	ft_check2(char *s)
{
	if (ft_strcmp(s, "cd") == 0)
		return (CD);
	if (ft_strcmp("echo", s) == 0)
		return (ECHO);
	if (ft_strcmp("env", s) == 0)
		return (ENV);
	if (ft_strcmp("exit", s) == 0)
		return (EXIT);
	if (ft_strcmp("export", s) == 0)
		return (EXPORT);
	if (ft_strcmp("pwd", s) == 0)
		return (PWD);
	if (ft_strcmp("unset", s) == 0)
		return (UNSET);
	return (NO);
}

void	ft_lunch_heredoc(t_use *here, t_env *env)
{
	ft_heredoc(here->fd, here->eof, env);
	close(here->fd);
	here->fd = open(here->file_name, O_RDONLY);
	unlink(here->file_name);
	free(here->file_name);
	free(here->eof);
}
