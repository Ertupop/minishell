/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 06:50:00 by ertupop           #+#    #+#             */
/*   Updated: 2023/01/23 07:50:36 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cd(char **tab, t_env *env, t_list *gc)
{
	if (ft_size_tab(tab) > 2)
		ft_putstr_fd("minishell: cd : too many arguments", 2);
	else if (ft_size_tab(tab) == 1)
		return (ft_home(env, gc));
	else
		return (ft_cd_2(tab[1], env, gc));
	return (0);
}

int	ft_home(t_env *env, t_list *gc)
{
	t_env	*tmp;
	char	*old;
	char	*tmpo;
	int		i;

	tmp = ft_get_env_pos(env, "HOME");
	tmpo = ft_strdup(tmp->str + 5);
	i = chdir(tmpo);
	if (i != 0)
	{
		if (tmpo != NULL)
			free(tmpo);
		return (1);
	}
	tmp = ft_get_env_pos(env, "PWD");
	old = ft_strdup(tmp->str);
	tmp->str = gc_join_str(&gc, "PWD=", tmpo);
	free(tmpo);
	tmp = ft_get_env_pos(env, "OLDPWD");
	if (tmp == NULL)
		return (ft_home2(old, env, gc, tmpo));
	gc_dell_one(gc, &tmp->str);
	tmp->str = gc_join_str(&gc, "OLDPWD=", old);
	return (0);
}

int	ft_home2(char *old, t_env *env, t_list *gc, char *tmpo)
{
	tmpo = ft_strjoin("OLDPWD=", old);
	free(old);
	ft_add_export(tmpo, env, gc);
	free(tmpo);
	return (0);
}

int	ft_cd_2(char *path, t_env *env, t_list *gc)
{
	t_env	*tmp;
	t_env	*old;
	char	*tmpo;

	tmpo = NULL;
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd : No Such file or directory\n", 1);
		return (1);
	}
	tmp = ft_get_env_pos(env, "PWD");
	fprintf(stderr, "fprintf de PWD : %s\n", tmp->str);
	if (tmp == NULL)
		return (1);
	old = ft_get_env_pos(env, "OLDPWD");
	fprintf(stderr, "fprintf de OLDPWD : %s\n", old->str);
	if (old == NULL)
		ft_cd3(tmp->str + 4, env, gc);
	else
		old->str = gc_join_str(&gc, "OLDPWD=", tmp->str + 4);
	tmpo = getcwd(tmpo, 0);
	tmp->str = gc_join_str(&gc, "PWD=", tmpo);
	free(tmpo);
	return (0);
}

void	ft_cd3(char *old, t_env *env, t_list *gc)
{
	char	*tmpo;

	tmpo = ft_strjoin("OLDPWD=", old);
	ft_add_export(tmpo, env, gc);
	free(tmpo);
}
