/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:03:34 by jule-mer          #+#    #+#             */
/*   Updated: 2023/10/09 14:03:02 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env_size(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_env	*ft_get_env_pos(t_env *env, char *find)
{
	int		i2;
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		i2 = 0;
		while (tmp->str[i2] && tmp->str[i2] == find[i2] && find[i2])
			i2++;
		if (find[i2] == '\0' && (tmp->str[i2] == '=' || tmp->str[i2] == '+'))
			return (tmp);
		else
			tmp = tmp->next;
	}
	return (NULL);
}

t_env	*ft_get_env_pos_export(t_env *env, char *find)
{
	int		i2;
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		i2 = 0;
		while (tmp->str[i2] && tmp->str[i2] != '='
			&& tmp->str[i2] == find[i2] && find[i2]
			&& find[i2] != '=' && find[i2] != '+')
			i2++;
		if ((find[i2] == '\0' || find[i2] == '=' || find[i2] == '+')
			&& (tmp->str[i2] == '='))
			return (tmp);
		else
			tmp = tmp->next;
	}
	return (NULL);
}

t_env	*ft_env(t_list **collector, char **envp)
{
	t_env	*env;
	t_env	*tmpp;
	int		i;

	env = NULL;
	i = -1;
	if (envp[0] == NULL)
		return (env);
	while (envp[++i])
	{
		tmpp = gc_alloc_env(collector);
		tmpp->str = gc_strdup(collector, envp[i]);
		tmpp->next = NULL;
		ft_lstadd_back_env(&env, tmpp);
	}
	return (env);
}

char	**ft_make_env_tab(t_env *env)
{
	int		len;
	char	**envp;
	t_env	*tmp;
	int		i;

	if (env == NULL)
		return (NULL);
	len = ft_env_size(env);
	envp = malloc(sizeof(char *) * (len + 2));
	if (envp == NULL)
		return (NULL);
	envp[len] = NULL;
	tmp = env;
	i = 0;
	while (tmp)
	{
		len = ft_strlen(tmp->str);
		envp[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	return (envp);
}
