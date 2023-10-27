/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ft_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:54:41 by ertupop           #+#    #+#             */
/*   Updated: 2023/10/27 06:09:55 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_command4(int fd, t_list *gc, char *command)
{
	fd = open(command, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_fprintf(2, "\033[0;36mminishell \033[0;31m: \033");
		ft_printf("[0m%s: Is a Directory\n", command);
		gc_dell(gc);
		exit(126);
	}
	else
		return (command);
}

char	*ft_command2(t_pipex *pip, char *command, t_env *env, int i)
{
	char	*tmp;
	int		fd;

	ft_path(env, pip);
	if (pip->path == NULL)
		return (ft_command2bis(pip));
	pip->env = ft_make_env_tab(env);
	while (pip->path[++i])
	{
		tmp = ft_join(pip->path[i], command);
		if (access(tmp, 0) == 0)
		{
			fd = open(command, __O_DIRECTORY);
			if (fd == -1)
				return (tmp);
			close(fd);
		}
		free(tmp);
		tmp = NULL;
	}
	return (tmp);
}

char	*ft_command2bis(t_pipex *pip)
{
	pip->env = NULL;
	return (NULL);
}

void	ft_command3(t_pipex *pip)
{
	int	i;

	i = 0;
	if (pip->env != NULL)
	{
		while (pip->env[i])
		{
			free(pip->env[i]);
			i++;
		}
		free(pip->env);
	}
	i = 0;
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
