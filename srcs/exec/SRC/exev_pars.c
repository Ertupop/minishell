/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:22:15 by ertupop           #+#    #+#             */
/*   Updated: 2023/01/06 09:26:08 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_path(t_env *env, t_pipex *pip)
{
	t_env	*tmpo;
	int		len;
	char	*tmp;

	tmpo = NULL;
	tmpo = ft_get_env_pos(env, "PATH");
	if (tmpo == NULL)
	{
		ft_path2(pip);
		return ;
	}
	len = ft_strlen(tmpo->str);
	tmp = malloc(sizeof(char) * ((len - 5) + 1));
	if (!tmp)
	{
		pip->path = NULL;
		return ;
	}
	ft_strlcpy(tmp, tmpo->str + 6, len + 1);
	pip->path = ft_split(tmp, ':');
	free(tmp);
}

char	*ft_command(t_pipex *pip, char *command)
{
	int		i;
	char	*tmp;

	i = -1;
	if (command == NULL)
		return (NULL);
	if (ft_is_a_slash(command) == 1)
	{
		if (access(command, 0) == 0)
			return (command);
		else
			return (NULL);
	}
	while (pip->path[++i])
	{
		tmp = ft_join(pip->path[i], command);
		if (access(tmp, 0) == 0)
			return (tmp);
		free(tmp);
		tmp = NULL;
	}
	if (tmp != NULL)
		free(tmp);
	return (NULL);
}

int	ft_is_a_slash(char	*command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	ft_path2(t_pipex *pip)
{
	pip->path = malloc(sizeof(char *) * 2);
	if (pip->path == NULL)
		return ;
	pip->path[0] = malloc(sizeof(char) * 1);
	if (pip->path[0] == NULL)
		return ;
	pip->path[0][0] = '\0';
	pip->path[1] = NULL;
	return ;
}

char	*ft_join(char *first, char *second)
{
	char	*join;
	int		i;
	int		i2;

	i = -1;
	if (first == NULL || second == NULL)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(first) + ft_strlen(second) + 2));
	if (join == NULL)
		return (NULL);
	while (first[++i])
		join[i] = first[i];
	join[i] = '/';
	i2 = 0;
	i++;
	while (second[i2])
	{
		join[i] = second[i2];
		i++;
		i2++;
	}
	join[i] = '\0';
	return (join);
}
